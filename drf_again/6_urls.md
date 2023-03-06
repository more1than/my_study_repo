```python
router = routers.SimpleRouter()
# 注册 不用加/了
router.register("books", views.BooksView, )

urlpatterns = []

urlpatterns += router.urls
```

action装饰器包装函数建立路由

detail表示是不是对单一数据操作，类似于封装查询一个或查询所有接口的区别

```python
class BookViewModelSet(ModelViewSet):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer

    @action(methods=["get"], detail=False)
    def get_all(self, request):
        return 200

    @action(methods=["get"], detail=True)
    def get_all(self, request):
        return 200
```

