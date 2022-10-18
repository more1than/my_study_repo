## cookie

短链接：一次请求和一次响应之后断开连接

cookie：保存在浏览器的键值对，发送请求时，自动携带cookie

session：存储在服务器端，可以存储在数据库中，redis中或文件中 

```python
class LoginForm(Form):
    # required为True代表必填字段
    username = CharField(label="用户名", widget=TextInput, required=True)
    password = CharField(label="密码", widget=PasswordInput, required=True)

    def clean_password(self):
        password = self.cleaned_data.get("password")
        return my_md5(password)

def login(request):
    if request.method == "GET":
        form = LoginForm()
        print(form)
        return form
    form = LoginForm(data=request.POST)
    if form.is_valid():
        # 验证成功后获取到的用户信息
        print(form.cleaned_data)
        admin_object = Admin.objects.filter(**form.cleaned_data).first()
        if not admin_object:
            form.add_error("password", "用户名或密码错误")
        # 用户名密码正确
        # 网站生成随机字符串，写道用户浏览器cookie中，再写道session中
        request.session["info"] = admin_object.username

def admin_list_test(request):
    info = request.session.get("info")
    # 如果未登录，info获取不到信息，重定向到登陆页面
    if not info:
        return redirect("/login/")
```

