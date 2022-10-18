使用Serializer类查询单个和多个的例子

```python
class StudentView(View):
    def get(self, request):
        """序列化器，序列化调用，序列化一个模型对象"""
        # 获取数据
        student_list = Student.objects.first()
        # 实例化序列化集
        serializer = Student1Serializer(instance=student_list)
        # 返回数据
        return JsonResponse(data=serializer.data, status=200, safe=False)

    def get2(self, request):
        """序列化器，序列化阶段的调用"""
        # 1. 获取数据
        student_list = Student.objects.all()

        # 2. 实例化序列化器
        # 传入多条模型数据使用many参数
        serializer = Student1Serializer(instance=student_list, many=True)

        # 3. 调用序列化对象的data属性方法，获取转换后的数据
        data = serializer.data

        # 4. 响应数据给客户端
        return JsonResponse(data=data, status=200, safe=False)
```

序列化多个值时，使用many关键字参数

Student1Serializer(instance=student_list, many=True)