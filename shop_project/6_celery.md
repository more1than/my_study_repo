创建celery_tasks文件夹，与项目文件夹和日志文件夹同级

celery文件夹中创建main和config文件

需要用celery实现的任务在celery下创建新文件夹（创建sms用来异步发短信）

在任务文件夹下创建tasks文件，该文件名称不能更改



### 坑

```
1. python 3.7以上版本不支持celery3或celery4，只能下载最新的celery5，库中含有async，但是python中3.7以后async变成了关键字
2. celery -A celery_tasks.main worker -l info命令报错：ModuleNotFoundError: No module named 'celery_task'或TypeError: the 'package' argument is required to perform a relative import for '.\\celery_tasks\\main'，应更改为：celery.exe -A celery_tasks.main worker -l info，   尝试加上.exe
```

main

```python
from celery import Celery

# 1.创建celery实例对象
celery_app = Celery("my_shop")

# 2.加载配置文件
celery_app.config_from_object("celery_tasks.config")

# 3.自动注册异步任务
celery_app.autodiscover_tasks(["celery_tasks.sms"])
```

config

```python
# celery配置文件
from celery import app
from django.conf import settings

# 指定任务队列的位置
broker_url = "redis://127.0.0.1:6379/7"
```



运行

```bash
celery -A celery_tasks.main worker -l info
```



注册任务

```python
# 编辑异步任务代码
from time import sleep
from celery_tasks.main import celery_app

@celery_app.task(name="send_sms_code")  # 使用装饰器注册任务
def send_sms_code(mobile, code):
    print("发送短信, {0}, {1}".format(mobile, code))
    sleep(1)
```

```
被celery修饰的函数使用 delay函数来调用
```

使用delay函数调用异步任务函数，实现异步功能

```python
from random import randint
from rest_framework import status
from rest_framework.response import Response
from rest_framework.views import APIView
from django_redis import get_redis_connection
import logging
from . import contants
from celery_tasks.sms.tasks import send_sms_code

logger = logging.getLogger("django")


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
        pl = redis_conn.pipeline()
        pl.setex("sms_%s" % mobile, contants.SMS_CODE_REDIS_EXPIRES, sms_code)
        # 5 存储一个标记位，表示该手机号是否在60秒内发送过短信
        pl.setex("send_flag_%s" % mobile, contants.SEND_SMS_CODE_INTERVAL, 1)
        # 执行管道
        pl.execute()
        # 6. 利用xx工具发送短信验证码
        # 触发异步任务，将异步任务添加到celery任务队列
        # send_sms_code(mobile, sms_code)  # 普通调用函数
        send_sms_code.delay(mobile, sms_code)  # 触发异步任务
        # 7. 响应
        return Response({"message": "ok"})
```

