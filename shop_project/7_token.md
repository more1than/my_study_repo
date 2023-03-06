### token由三部分组成header ， payload， signature

header声明加密格式，令牌类型等

payload声明签发者，用户方，接收方等

signature 保存SHA256加密后的字符串

如何使用token

生成token时，前端无需传入，仅后端进行生成然后返回即可



### token流程

```
1.客户端发送登录请求到服务端
2.验证账号密码，创建token并存储token的对应信息
3.登录成功把token返回给客户端
4.客户端存储token  下次登陆返回tiken
5.服务端验证token，与之前的token做比对
6.验证成功把用户信息返回给客户端
```



在请求头中加入Authorization，并加上bearer标注

```json
headers: {
 "Authorization": "Bearer "+ token
}
```

token只存在浏览器端，无需在服务器端保存

如果私钥被泄露，应该马上更换密钥，密钥应定期更换



使用djangorestframework-jwt第三方库生成jwt

```python
from rest_framework_jwt.settings import api_settings
jwt_payload_handler = api_settings.JWT_PAYLOAD_HANDLER
jwt_encode_handler = api_settings.JWT_DECODE_HANDLER

payload = jwt_payload_handler(user)
token = jwt_encode_handler(payload)
```



对应的序列化器

```python
class CreateUserSerializer(serializers.ModelSerializer):
    """注册序列化器"""

    # 序列化器需要校验的所有字段:[id, username, password, password2, mobile, sms_code, allow]
    # 需要校验的字段:[username, password, password2, mobile, sms_code, allow]
    # 模型中已存在的字段:[username, password, mobile]

    # 需要序列化的字段:[id, username, mobile]
    # 需要反序列化的字段:[username, password, password2, mobile, sms_code, allow]
    password2 = serializers.CharField(label="确认密码", write_only=True)
    sms_code = serializers.CharField(label="验证码", write_only=True)
    allow = serializers.CharField(label="同意协议", write_only=True)
    token = serializers.CharField(label="token", read_only=True)

    class Meta:
        model = User  # 从模型中映射序列化器字段
        fields = ["id", "username", "password", "password2", "mobile", "sms_code", "allow", "token"]
        extra_kwargs = {  # 限制字段入参
            "username": {
                "min_length": 5,
                "max_length": 20,
                "error_messages": {  # 自定义校验出错后的错误信息提示
                    "min_length": "仅允许5-20个字符的用户名",
                    "max_length": "仅允许5-20个字符的用户名",
                }
            },
            "password": {
                "write_only": True,
                "min_length": 8,
                "max_length": 20,
                "error_messages": {
                    "min_length": "仅允许8-20个字符的密码",
                    "max_length": "仅允许8-20个字符的密码",
                }
            }
        }

    def validate_mobile(self, value):
        """单独校验手机号"""
        if not re.match(r'1[3-9]\d{9}$', value):
            raise serializers.ValidationError("手机号格式有误")
        return value

    def validate_allow(self, value):
        """协议字段校验"""
        if value != "true":
            raise serializers.ValidationError("请同意用户协议")
        return value

    def validate(self, attrs):
        """校验密码是否相同"""
        if attrs["password"] != attrs["password2"]:
            raise serializers.ValidationError("两次密码不一致")

        # 校验验证码
        redis_conn = get_redis_connection("verify_codes")
        mobile = attrs["mobile"]
        real_sms_code = redis_conn.get("sms_%s" % mobile)

        # 向redis存储数据时都是以字符串进行存储的，取出来之后都是byte类型
        if real_sms_code is None or attrs["sms_code"] != real_sms_code.decode():
            raise serializers.ValidationError("验证码错误")
        return attrs

    def create(self, validated_data):
        # 部分信息无需入库
        del validated_data["password2"]
        del validated_data["sms_code"]
        del validated_data["allow"]

        # 密码加密
        password = validated_data.pop("password")

        user = User(**validated_data)
        user.set_password(password)  # 把加密后的密码赋值给user中的password属性
        user.save()  # 入库

        from rest_framework_jwt.settings import api_settings
        jwt_payload_handler = api_settings.JWT_PAYLOAD_HANDLER
        jwt_encode_handler = api_settings.JWT_DECODE_HANDLER

        payload = jwt_payload_handler(user)
        token = jwt_encode_handler(payload)

        user.token = token
        return user
```



用户登录返回token，仅使用第三方库中的obtain_jwt_token，即可校验用户名密码返回token

```python
urlpatterns = [
    # JWT登录, 内部认证逻辑是使用Django的, 额外登录成功生成token
    re_path(r"authorizations/$", obtain_jwt_token),
]
```

