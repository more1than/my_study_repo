### **认证组建可以支持多个**从左到右依次执行

自定义认证类

```python
class MyAuthentication(BaseAuthentication):
    # 认证逻辑，如果通过认证，返回两个值，如果认证失败，抛出AuthenticationFailed异常

    def authenticate(self, request):
        token = request.GET.get("token")
        if token:
            user_token = UserToken.objects.filter(token=token).first()
            if user_token:
                # 认证通过返回两个值，认证失败抛出异常
                return user_token.user, token
            else:
                raise AuthenticationFailed("认证失败")
        else:
            raise AuthenticationFailed("请求地址中需要携带token")
```

视图中配置

```python
authentication_classes = [MyAuthentication]
```



全局设置

```python
REST_FRAMEWORK = {
    # 录入类名，设置全局
    "DEFAULT_AUTHENTICATION_CLASSES": ["app01.app_auth.MyAuthentication", ]
}
```



## 

