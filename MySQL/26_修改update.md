修改 update (DML)

语法格式

```sql
update 表名 set 字段名1=值1, 字段名2=值2  where 条件;
```

没有条件限制会导致所有数据全部更新

```sql
update t_user set name = 'abc';
```

