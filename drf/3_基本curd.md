```python
import json
from django.http import JsonResponse
from django.views import View
from .models import Student


# Create your views here.

class StudentView(View):
    def post(self, request):
        """添加一个学生信息"""
        # 1.接收客户端提交的数据
        name = request.POST.get("name")
        sex = request.POST.get("sex")
        age = request.POST.get("age")
        class_null = request.POST.get("class_null")
        description = request.POST.get("description")

        # 2. 操作数据库，持久化存储
        instance = Student.objects.create(
            name=name,
            sex=sex,
            age=age,
            class_null=class_null,
            description=description
        )

        # 3. 返回结果
        return JsonResponse(data={
            "id": instance.pk,
            "name": instance.name,
            "sex": instance.sex,
            "age": instance.age,
            "class_null": instance.class_null,
            "description": instance.description,
        }, status=201)

    def get(self, request):
        """获取多个用户信息"""
        # 返回值为对象，转换为列表
        students_list = list(Student.objects.values())
        # safe=False，列表格式也可读取
        return JsonResponse(data=students_list, status=200, safe=False)


class StudentInfoView(View):
    def get(self, request, pk):
        """获取一条数据"""
        try:
            # 获取不到会报错
            instance = Student.objects.get(pk=pk)
            return JsonResponse(data={
                "id": instance.pk,
                "name": instance.name,
                "sex": instance.sex,
                "age": instance.age,
                "class_null": instance.class_null,
                "description": instance.description,
            }, status=200)
        except Student.DoesNotExist:
            return JsonResponse(status=404, data=None)

    def put(self, request, pk):
        """更新一个学生信息"""
        data = json.loads(request.body)
        name = data.get("name")
        sex = data.get("sex")
        age = data.get("age")
        class_null = data.get("class_null")
        description = data.get("description")
        try:
            # 获取不到会报错
            instance = Student.objects.get(pk=pk)
            instance.name = name
            instance.sex = sex
            instance.age = age
            instance.class_null = class_null
            instance.description = description
            instance.save()

        except Student.DoesNotExist:
            return JsonResponse(status=404, data=None)

        return JsonResponse(data={
            "id": instance.pk,
            "name": instance.name,
            "sex": instance.sex,
            "age": instance.age,
            "class_null": instance.class_null,
            "description": instance.description,
        }, status=201)
    
    def delete(self, request, pk):
        try:
            Student.objects.filter(pk=pk).delete()
        except:
            pass
        return JsonResponse(data=None, status=204)
```

相关子路由配置

```python
from django.urls import path, re_path
from stuapi import views

urlpatterns = [
    path("students/", views.StudentView.as_view()),
    re_path(r"^students/(?P<pk>\d+)/$", views.StudentInfoView.as_view()),
]
```