#### 向表中新增数据

类名.objects.create向表中添加数据

filter()  通过字段筛选

delete()    删除字段

all()   获取所有数据

```python
# model中
class Department(models.Model):
    title = models.CharField(max_length=32)

# views中
def orm(request):
    # 测试ORM中的数据
    Department.objects.create(title="销售部")
    # 删除指定项
    Department.objects.filter(title="销售部").delete()
    # 删除所有
    Department.objects.all().delete()
    # 获取数据
    info_list = UserInfo.objects.all()
    # 遍历获取数据
    for obj in info_list:
        print(obj.id, obj.name, obj.password, obj.age)
    # 过滤数据并获取第一个
    info_list = UserInfo.objects.filter(id=1).first()
    print(obj.id, obj.name, obj.password, obj.age)
    # 更新数据
    UserInfo.objects.filter(name="张浩").update(age=18)
    return HttpResponse("success")
```

### 注意坑

```python
objects不可调用
UserInfo.objects.all()  # 不会报错
UserInfo.objects().all()  # 会报错
```

手动创建id，django也会默认创建

```python
id = models.BigAutoField(verbose_name='ID', primary_key=True)
```

values()  只获取几个字段，返回值为字典

```python
# info_dict = {"id": "1", "name": "zhang"}
info_dict = UserInfo.objects.filter(id=1).values("id", "name").first()
```

