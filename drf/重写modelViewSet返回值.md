重写视图集中方法的返回值，操作错误信息和正确信息

```python
class MyModelViewSet(ModelViewSet):
    def retrieve(self, request, *args, **kwargs):
        instance = self.get_object()
        serializer = self.get_serializer(instance)
        if not is_valid:
            return Response({
                "code": 400,
                "msg": '失败',
                "data": serializer.errors,
            })
        return Response({
            "code": 200,
            "msg": '成功',
            "data": serializer.data,
        })
```



视图中调用自定义类

```python
class StudentModelViewSet(MyModelViewSet):
    queryset = Student.objects
    serializer_class = StudentModelSerializer
```



 