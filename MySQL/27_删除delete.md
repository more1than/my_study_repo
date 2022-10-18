删除数据delete关键字（DML语句）

```sql
delete from 表名 where 条件;
```

没有条件约束会删除整张表

```sql
delete from t_user where id=2;
```



删除所有    这种删除数据的方式比较慢

delete语句删除数据的原理：

表中的数据被删除了，但数据在硬盘上的存储空间不会被释放，这种方式缺点是删除的效率低，这种删除的优点是支持回滚，可以恢复数据

```sql
delete from t_user;
```



truncate 快速删除  物理删除(DDL语句)

删除表中的数据而表还在

快速删除表中数据

缺点：不支持回滚

优点：快速

```sql
truncate table 表名;
```



大表删除时，如果使用delete可能要删除1小时，可以选择使用truncate，使用truncate后不能恢复数据