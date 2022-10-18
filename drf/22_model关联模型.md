一对一    one_to_one

一对多     Foreignkey    在多方模型中注册Foreignkey    

多对多    many_to_many

#### 虚拟外键：

```
db_constraint=False
```

 操作字段时不会对外键进行查询等操作，所以使用虚拟外键提高性能

 

```python
# 学生   sch_student      1
# 成绩   sch_course       n    n
# 课程   sch_achievement       1     n
# 老师   sch_teacher                 1

class Student(models.Model):
    name = models.CharField(max_length=50, verbose_name="姓名")
    age = models.SmallIntegerField(verbose_name="年龄")
    sex = models.BooleanField(default=False)

    class Meta:
        db_table = "sch_student"

    def __str__(self):
        return self.name

class Course(models.Model):
    name = models.CharField(max_length=50, verbose_name="课程名称")
    teacher = models.ForeignKey("Teacher", on_delete=models.DO_NOTHING, related_name="course", db_constraint=False)

    class Meta:
        db_table = "sch_course"

    def __str__(self):
        return self.name

class Teacher(models.Model):
    name = models.CharField(max_length=50, verbose_name="姓名")
    sex = models.BooleanField(default=False)

    class Meta:
        db_table = "sch_teacher"

    def __str__(self):
        return self.name

class Achievement(models.Model):
    score = models.DecimalField(default=0, max_digits=4, decimal_places=1, verbose_name="成绩")
    student = models.ForeignKey(Student, on_delete=models.DO_NOTHING, related_name="s_achievement", db_constraint=False)
    course = models.ForeignKey(Course, on_delete=models.DO_NOTHING, related_name="c_achievement", db_constraint=False)
    create_dtime = models.DateTimeField(auto_created=datetime.now)

    class Meta:
        db_table = "sch_achievement"

    def __str__(self):
        return self.score
```

