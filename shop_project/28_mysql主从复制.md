### 备份

冷备份：主机需要停机，再将数据备份给从机

热备份：主机无需停机，就可以把数据备份给从机

先冷后热

## 冷备份

### 主机导出文件

```shell
mysqldump -uroot -pymysql --all-databases --lock-all-tables > ~/master_db.sql
```

### 从机导入数据

```shell
mysql -uroot -pymysql -h192.168.0.0 --port=3307 < ~/master_db.sql
```



## 热备份

```mysql
# 生成新账户
GRANT REPLICATION SLAVE ON *.* TO 'slave'@'%' identified by 'slave';
# 刷新账号让其生效
FLUSH PRIVILEGES;
```



检查主机log文件状态

```MYSQL
SHOW MASTER STATUS;
```

FILE代表从机热备份时读取数据的文件

Position代表从热备份时读取数据的位置，节点

项目settings中配置

```python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'my_shop',
        'HOST': "127.0.0.1",
        'PORT': 3306,
        'USER': 'zhanghao',
        'PASSWORD': 'zhanghao'
    },
    'slave': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'my_shop',
        'HOST': "127.0.0.1",
        'PORT': 3307,
        'USER': 'zhanghao',
        'PASSWORD': 'zhanghao'
    },
}
```

在utils文件下创建db_router文件进行路由分发操作

```PYTHON
class MasterSlaveDBRouter:
    """数据库主从读写分离路由"""
    
    def db_for_read(self, model, **hints):
        """数据库读操作"""
        return "slave"
    
    def db_for_write(self, model, **hints):
        """数据库写操作"""
        return "default"
    
    def allow_relation(self, obj1, obj2, **hints):
        """是否运行关联操作"""
        return True
```

