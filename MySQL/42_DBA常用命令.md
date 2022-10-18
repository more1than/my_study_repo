### DBA常用命令

创建用户

```sql
create user username identified by 'password';
```



#### 数据的备份，导入导出

数据导出

在windows cmd中执行，不是在mysql中

```dos
mysqldump database_name>D:\myproject.sql -uroot -p123456
```



导入文件在mysql中操作

导入sql文件

```sql
source sql文件路径;
```

