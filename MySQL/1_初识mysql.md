windows启动和停止mysql

```mysql
net stop MySQL
net start MySQL
```

登录

-u用户  -p密码

```mysql
mysql -uroot -p123456
```

退出mysql

```mysql
exit
```

查询有哪些数据库

```mysql
show databases;
```

mysql默认自带了四个数据库

```
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
```

使用数据库

```mysql
use test_db;
```

创建db

```mysql
create database test_db;
```

