用户结算时，无论如何都需要登录，这时需要把cookie中的数据合并到用户对应redis中

目前策略：如果cookie中购物车商品如果有和redis中有相同的，数量用cookie的覆盖redis中的

如果商品在cookie或redis中的一方勾选商品，则最终就是勾选的

自定义工具函数实现合并操作

```python
import base64
import pickle

from django_redis import get_redis_connection


def merge_cart_cookie_to_redis(request, user, response):
    """
    登录时合并购物车
    :param request: 登录时借用的请求对象
    :param user: 登录时借用的用户对象
    :param response: 登录时借用的响应对象
    :return:
    
    # cookie 数据格式
    {
        "sku_id_1": {"count": 1, "selected": True},
        "sku_id_2": {"count": 1, "selected": True},
    }
    """
    # 获取cookie并校验
    cart_str = request.COOKIES.get("cart")
    # 把cookie中的字符串转换为字典
    if cart_str is None:
        return
    cart_dict = pickle.loads(base64.b64decode(cart_str.encode()))
    # 创建redis连接对象
    redis_conn = get_redis_connection("cart")
    pl = redis_conn.pipeline()
    # 遍历cookie购物车大字典，把sku_id及count向redis的hash中存储
    for sku_id in cart_dict:
        pl.hset("cart_%d" % user.id, sku_id, cart_dict[sku_id]["count"])
        # 如果cookie中商品勾选
        if cart_dict[sku_id]["selected"]:
            pl.sadd("selected_%d" % user.id, sku_id)
    pl.execute()
    # 清空cookie
    response.delete_cookie("cart")  # 删除cookie
    return True
```

用户登录视图重写post方法，添加合并功能

```python
class UserAuthorizeView(ObtainJSONWebToken):
    """自定义账号密码登录视图，实现购物车登陆合并"""
    def post(self, request, *args, **kwargs):
        serializer = self.get_serializer(data=request.data)

        if serializer.is_valid():
            user = serializer.object.get('user') or request.user
            token = serializer.object.get('token')
            response_data = jwt_response_payload_handler(token, user, request)
            response = Response(response_data)
            if api_settings.JWT_AUTH_COOKIE:
                expiration = (datetime.utcnow() +
                              api_settings.JWT_EXPIRATION_DELTA)
                response.set_cookie(api_settings.JWT_AUTH_COOKIE,
                                    token,
                                    expires=expiration,
                                    httponly=True)
            merge_cart_cookie_to_redis(request, user, response)
            return response
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
```

