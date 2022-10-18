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
