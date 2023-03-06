APIView是所有视图基类

GenericAPIView继承自APIView

可以定义queryset和serializer_class

```python
class BooksView2(GenericAPIView):
    # queryset = BookInfo.objects
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer

    def get(self):
        # 获取序列化器
        self.get_serializer()
        # 获取模板
        self.get_object()
        return 200
```

五个视图扩展类

快速实现五个接口

```python
class BooksView(GenericAPIView, ListModelMixin, CreateModelMixin):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer

    def get(self, request):
        return self.list(request=request)

    def post(self, request):
        return self.create(request=request)
    
class BooksViewDetail(GenericAPIView, RetrieveModelMixin, DestroyModelMixin, UpdateModelMixin):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer
    
    def get(self, request, pk):
        return self.retrieve(request, pk)

    def put(self, request, pk):
        return self.update(request, pk)

    def delete(self, request, pk):
        return self.destroy(request, pk)
```



九个视图子类

ListAPIView 查询多个

CreateAPIView 创建

UpdateAPIView 更新

RetrieveAPIView 查询一个

DestroyAPIView 删除

```python
class BookViewExtend(ListAPIView, CreateAPIView):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer

class BookViewExtendDetail(UpdateAPIView, RetrieveAPIView, DestroyAPIView):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer

class BookViewExtend(ListCreateAPIView):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer
    
class BookViewExtendDetail(RetrieveUpdateDestroyAPIView):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer
```



直接使用ModelViewSet实现5个基础接口

```python
class BookViewModelSet(ModelViewSet):
    queryset = BookInfo.objects.all()
    serializer_class = BookInfoSerializer
    
# url  当路径匹配又是对应的请求，会执行视图类中的对应方法
urlpatterns = [
    path("book/", views.BookViewModelSet.as_view(actions={"get": "list", "post": "create"})),
    re_path(r"^book/(?P<pk>\d+)", views.BookViewModelSet.as_view(actions={"get": "retrieve", "put": "update", "delete": "destroy"}))
]
```



继承ViewSetMixin模板

```python
# ViewSetMixin一定要放在APIView之前，因为两个类都重写了as_view函数
class BookAsView(ViewSetMixin, APIView):
    def get_all_book_info(self, request):
        pass

# url
urlpatterns = [
    # 继承ViewSetMixin视图类，路由也可以改写成这样
    path("book/", views.BookViewModelSet.as_view(actions={"get": "list", "post": "create"})),
]
```

