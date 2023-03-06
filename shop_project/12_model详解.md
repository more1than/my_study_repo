class Meta作用：使用内部类来提供一些metadata



abstract参数：如下段代码所示，将abstract设置为True后，CommonInfo无法作为一个普通的Django模型，而是作为一个抽象基类存在，作用 是为其他的类提供一些公有的属性。如Student会拥有三个属性，即name，age，home_group。利于公用信息的分解，避免重复编码。

提供一个抽象类，不会被迁移，供其他模型类使用

```python
from django.db import models

class CommonInfo(models.Model):
    name = models.CharField(max_length=100)
    age = models.PositiveIntegerField()

    class Meta:
        abstract = True

class Student(CommonInfo):
    home_group = models.CharField(max_length=5)
```



一对多的关系在多的表中创建外键关联一的表

```python
举例：定义老师和学生表，老师一 学生多，在学生表中创建外键
# 获取到老师对象
teacher = Teacher.objects.get(id=1)
# 使用老师实例获取学生对象列表(外键默认维护表名小写加上_set的属性来返回其对象，具体就是student_set)
student_object_list = teacher.student_set.all()

# 外键入参related_name="xxx"，可以改变返回属性的调用方法，原方法为xxx_set
related_name = "student_info"
student_object_list = teacher.student_info.all()
```



