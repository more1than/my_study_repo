### ORM作用

1.增删改查数据库中的数据表，无需写sql语句，无法创建数据库

2.操作数据表中的数据

### 下载mysqlclient第三方库

```python
pip install mysqlclient
```

#### 连接mysql

在settings中配置

```python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'db.name',  # 要链接的数据库
        'USER': 'root',
        'PASSWORD': 'xxx',
        'HOST': '', # mysql目标服务器ip
        'PORT': '',
    }
}
```



操作数据表

在models中定义好映射类

```python
class UserInfo(models.Model):
    name = models.CharField(max_length=32) # char类型
    password = models.CharField(max_length=64)
    age = models.IntegerField() # 整型
```



django映射数据库迁移操作

```dos
python manage.py makemigrations
python manage.py migrate
```



数据库中如果已经有表，向往表中添加字段时，django会报出两个选项

1. 输入一个新字段的默认值，即表中所有字段都是输入值

2. 提出，django建议添加默认值，default=1

3. 允许该值为空

