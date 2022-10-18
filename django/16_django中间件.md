###  定义中间件

如果该方法中没有返回值，则继续往后走
如果有返回值， HttpResponse, render redirect 则不再往后执行

```python
from django.utils.deprecation import MiddlewareMixin

class M1(MiddlewareMixin):
    """ 自定义中间件 """

    def process_request(self, request):
        # 如果该方法中没有返回值，则继续往后走
        # 如果有返回值， HttpResponse, render redirect 则不再往后执行
        print("进入m1中间件")

    def process_response(self, request, response):
        print("退出m1中间件")
```



定义后希望调用中间件，到settings中的MIDDLEWARE配置

精确到类名

```python
MIDDLEWARE = [
    'django.middleware.security.SecurityMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
    "app01.middleware.auth.M1",
]
```



应用中间件

用户登录场景，校验session

```python
from django.http import HttpResponse
from django.utils.deprecation import MiddlewareMixin

class AuthMiddleware(MiddlewareMixin):
    """ 自定义中间件 """

    def process_request(self, request):
        # 排除不需要登录就能访问的页面，否则会无限调用中间件死循环
        if request.path_info == "/login/":
            # 如果该方法中没有返回值或返回None，则继续往后走
            return
        # 读取当前访问的用户的session信息，如果能读取到，说明已经登录过
        info_dict = request.session.get("info")
        if info_dict:
            return
        # 如果没登陆过
        return HttpResponse("请登录")

    def process_response(self, request, response):
        print("退出中间件")
```