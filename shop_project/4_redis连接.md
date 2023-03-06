配置settings   

CACHES

```PYTHON
# 配置redis数据库作为缓存后端
CACHES = {
    "default": {  # 缓存业务
        "BACKEND": "django_redis.cache.RedisCache",
        "LOCATION": "redis://127.0.0.1:6379/0",
        "OPTIONS": {
            "CLIENT_CLASS": "django_redis.client.DefaultClient",
        }
    },
    "session": {  # 缓存session
        "BACKEND": "django_redis.cache.RedisCache",
        "LOCATION": "redis://127.0.0.1:6379/1",
        "OPTIONS": {
            "CLIENT_CLASS": "django_redis.client.DefaultClient",
        }
    },
    "verify_codes": {  # 缓存验证码
        "BACKEND": "django_redis.cache.RedisCache",
        "LOCATION": "redis://127.0.0.1:6379/2",
        "OPTIONS": {
            "CLIENT_CLASS": "django_redis.client.DefaultClient",
        }
    }
}
SESSION_ENGINE = "django.contrib.sessions.backends.cache"
SESSION_CACHE_ALIAS = "session"

```

代码连接

```python
class SMSCodeView(APIView):
    """短信验证"""

    def get(self, request, mobile):
        # 1. 创建redis连接对象
        redis_conn = get_redis_connection("verify_codes")
        # 2  从redis获取发送短信标记位
        send_flag = redis_conn.get("send_flag_%s" % mobile)
        if send_flag:  # 如果取到了标记位，证明60s已经发送了短信
            return Response({"message": "手机频繁发送短信"}, status=status.HTTP_400_BAD_REQUEST)
        # 3. 生成验证码
        # %06d 代表数位不足时前面的字符用0补全
        sms_code = "%06d" % randint(0, 999999)
        logger.info(sms_code)
        # 4. 把验证码存储到redis数据库
        # param1: redis key名
        # param2: 过期时间
        # param3: redis value值
        redis_conn.setex("sms_%s" % mobile, 300, sms_code)
        # 5 存储一个标记位，表示该手机号是否在60秒内发送过短信
        redis_conn.setex("send_flag_%s" % mobile, 60, 1)
        # 6. 利用xx工具发送短信验证码
        # 7. 响应
        return Response({"message": "ok"})
```

url中

```python
urlpatterns = [
    # 发短信
    re_path(r"^sms_codes/(?P<mobile>1[3-9]\d{9})/$", views.SMSCodeView.as_view()),
]
```



使用管道机制优化连接redis连接次数

仅将写操作放入管道，读操作不需要放入管道

```python
class SMSCodeView(APIView):
    """短信验证"""

    def get(self, request, mobile):
        # 1. 创建redis连接对象
        redis_conn = get_redis_connection("verify_codes")
        # 2  从redis获取发送短信标记位
        send_flag = redis_conn.get("send_flag_%s" % mobile)
        if send_flag:  # 如果取到了标记位，证明60s已经发送了短信
            return Response({"message": "手机频繁发送短信"}, status=status.HTTP_400_BAD_REQUEST)
        # 3. 生成验证码
        # %06d 代表数位不足时前面的字符用0补全
        sms_code = "%06d" % randint(0, 999999)
        logger.info(sms_code)
        # 4. 把验证码存储到redis数据库
        # param1: redis key名
        # param2: 过期时间
        # param3: redis value值
        # 创建redis管道:(把多次redis操作装入管道中，将来一次性去执行，减少redis连接操作)
        pl = redis_conn.pipline()
        pl.setex("sms_%s" % mobile, contants.SMS_CODE_REDIS_EXPIRES, sms_code)
        # 5 存储一个标记位，表示该手机号是否在60秒内发送过短信
        pl.setex("send_flag_%s" % mobile, contants.SEND_SMS_CODE_INTERVAL, 1)
        # 执行管道
        pl.execute()
        # 6. 利用xx工具发送短信验证码
        # 7. 响应
        return Response({"message": "ok"})
```

