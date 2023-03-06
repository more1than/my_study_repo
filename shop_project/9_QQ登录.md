定义QQ登录模型类

优先定义基类

```python
from django.db import models

class BaseModel(models.Model):
    """为模型类补充字段"""
    # auto_now_add对象第一次创建时自动设置当前时间
    create_time = models.DateTimeField(auto_now_add=True, verbose_name="创建时间")
    # auto_now每次保存对象时，自动设置该字段为当前时间
    update_time = models.DateTimeField(auto_now=True, verbose_name="更新时间")

    class Meta:
        abstract = True  # 说明是抽象模型类，用于继承使用，数据库迁移时不会创建BaseModel表

```

定义QQ用户模型类

```python
from django.db import models
from users.models import User
from myshop.utils.models import BaseModel

class OAuthQQUser(BaseModel):
    """
    QQ登录用户数据
    """
    user = models.ForeignKey(User, on_delete=models.CASCADE, verbose_name="用户")
    openid = models.CharField(max_length=64, verbose_name="openid", db_index=True)

    class Meta:
        db_table = "tb_oauth_qq"
        verbose_name = "QQ登录用户数据"
        verbose_name_plural = verbose_name
```



1.准备工作：用公司QQ在QQ互联平台注册为开发者

2.创建应用（代表要和哪个项目合作， appid，appkey 回调域名）





总结：

```
get请求: 利用QQ登录SDK获取QQ登录网址，返回QQ登录网址
get请求：QQ登陆成功后，需要QQ登录回调网址，利用前端传入的code向QQ服务器获取access_token，再通过access_token获取openid，查询DB中是否有此openid绑定的用户，没有则
```

