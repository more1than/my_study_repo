在settings配置文件中的INSTALLED_APPS列表里添加'rest_framework'

```python
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'rest_framework',
]
```

项目文件中__init__.py

```python
from pymysql import install_as_MySQLdb

# mysql对接django
install_as_MySQLdb()
```

settings中

```python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'students',
        'HOST': "127.0.0.1",
        'PORT': 3306,
        'USER': 'root',
        'PASSWORD': '123456'
    }
}
```



配置映射表

```python
class Student(models.Model):
    name = models.CharField(max_length=255, verbose_name="姓名")
    sex = models.BooleanField(default=1, verbose_name="性别")
    age = models.IntegerField(verbose_name="年龄")
    class_null = models.CharField(max_length=5, verbose_name="班级编号")
    description = models.TextField(max_length=1000, verbose_name="个性签名")

    class Meta:
        db_table = "tb_student"
        verbose_name = "学生"
        verbose_name_plural = verbose_name
```

一个创建的POST请求例子

```python
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
```



配置子路由文件(在app文件夹中)

```python
from django.urls import path, re_path
from stuapi import views

urlpatterns = [
    path("students/", views.StudentView.as_view()),
    re_path(r"^students/(?P<pk>\d+)/$", views.StudentInfoView.as_view()),
]
```

并在总路由文件中配置

依赖include函数，该路由为/api/students

```python
from django.contrib import admin
from django.urls import path, include

from stuapi import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/', include("stuapi.urls"))
]
```

