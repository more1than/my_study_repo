通用视图类例子

优先定义全局queryset  model对象和serializer_class 全局序列化器

使用类中的方法调用定义好的全局变量

self.get_queryset()  获取queryset  

self.get_serializer()  获取serializer_class 

查询单个时

self.get_object()   根据pk值获取信息，函数内部已经封装

```python
"""GenericAPIView 通用视图类"""


class StudentGenericAPIView(GenericAPIView):
    queryset = Student.objects
    # 定义全局序列化器
    serializer_class = StudentModelSerializer

    def get(self, request):
        """获取所有学生信息"""
        # 1.从DB获取信息
        student_list = self.get_queryset()  # GenericAPIView提供的属性

        # 2.序列化   框架不建议调用属性，建议调用方法，get_serializer方法便是序列化器
        serializer = self.get_serializer(instance=student_list, many=True)

        # 3.转换数据并返回给客户端
        return Response(serializer.data)

    def post(self, request):
        """添加一个数据"""
        # 1.获取客户端提交的数据，并序列化
        serializer = self.get_serializer(data=request.data)

        # 2.反序列化并数据保存
        serializer.is_valid(raise_exception=True)
        serializer.save()

        # 3.返回
        return Response(serializer.data, status=status.HTTP_201_CREATED)


class StudentInfoGenericAPIView(GenericAPIView):
    queryset = Student.objects
    serializer_class = StudentModelSerializer

    def get(self, request, pk):
        """获取一个数据"""
        # 1.根据pk值获取模型对象  get_object内部已经根据pk查询数据
        student_info = self.get_object()

        # 2.实例化序列化器
        serializer = self.get_serializer(instance=student_info)

        # 3.返回数据
        return Response(serializer.data)

    def put(self, request, pk):
        """更新数据"""
        # 1.根据pk值获取模型对象
        student_info = self.get_object()

        # 2.实例化序列化器
        serializer = self.get_serializer(instance=student_info, data=request.data)

        # 3.反序列化并数据保存
        serializer.is_valid(raise_exception=True)
        serializer.save()

        # 4.返回数据
        return Response(serializer.data, status=status.HTTP_201_CREATED)

    def delete(self, request, pk):
        """删除数据"""
        # 1.根据pk值删除数据
        self.get_object().delete()

        # 2.操作入库
        return Response({}, status=status.HTTP_204_NO_CONTENT)
```