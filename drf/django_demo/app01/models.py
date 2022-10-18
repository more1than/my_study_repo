from django.db import models


# Create your models here.
class Classes(models.Model):
    name = models.CharField(verbose_name="班级名称", max_length=32)


class Student(models.Model):
    # 实现一对一关联并级联删除
    user = models.OneToOneField("User", to_field="id", on_delete=models.CASCADE)
    # 性别字段
    gender = models.SmallIntegerField(verbose_name="性别", choices=((1, "男"), (2, "女")), null=False)
    # Classes表外键字段
    owner_class = models.ForeignKey(to="Classes", to_field="id", on_delete=models.CASCADE)


class Number(models.Model):
    """ 号码管理 """
    id = models.IntegerField(primary_key=True, )
    mobile = models.CharField(verbose_name="手机号", max_length=11)
    price = models.IntegerField(verbose_name="价格")
    level = models.SmallIntegerField(verbose_name="级别", choices=((1, "低"), (2, "中"), (3, "高")), default=1)
    status = models.SmallIntegerField(verbose_name="状态", choices=((1, "未占用"), (2, "已占用")), default=1)


class Admin(models.Model):
    """ 管理员 """
    username = models.CharField(verbose_name="用户名", max_length=32)
    password = models.CharField(verbose_name="密码", max_length=64)


class Task(models.Model):
    """ 任务 """
    level = models.SmallIntegerField(verbose_name="级别", choices=((1, "紧急"), (2, "一般")), default=1)
    title = models.CharField(verbose_name="标题", max_length=64)
    detail = models.TextField(verbose_name="详细信息")
    user = models.ForeignKey(verbose_name="负责人", to="Admin", on_delete=models.CASCADE)

    # 当该model对象被调用时，返回指定字段信息等
    def __str__(self):
        return self.level


class Order(models.Model):
    oid = models.CharField(verbose_name="订单号", max_length=64)
    title = models.CharField(verbose_name="名称", max_length=64)
    price = models.IntegerField(verbose_name="价格", max_length=64)
    status = models.SmallIntegerField(verbose_name="状态", choices=((1, "待支付"), (2, "已支付")), default=1)
    admin = models.ForeignKey(verbose_name="管理员", to="Admin", on_delete=models.CASCADE)


class City(models.Model):
    """ 城市 """
    name = models.CharField(verbose_name="名称", max_length=32)
    count = models.IntegerField(verbose_name="人口")
    # 本质上数据库也是CharField字段，自动保存数据，默认放到media文件夹下
    img = models.FileField(verbose_name="Logo", max_length='128', upload_to="city/")
