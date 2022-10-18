in关键字

查询年龄是20和30的数据

```sql
select name, age from tb_student where age in(20, 30);
```

not in 

查询年龄不是20或30的数据

```sql
select name, age from tb_student where age not in (20， 30);
```

