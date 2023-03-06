union 将查询结果合并

案例：查询工作岗位是manager和salesman的员工

```sql
select ename, job from emp where job='MANAGER' or job='SALESMAN'
```

第二种写法

```sql
select ename. job from emp where job in ("MANAGER", "SALESMAN")
```

使用union合并结果集

```sql
select ename, job from emp where job='MANAGER' 
union
select ename, job from emp where job='SALESMAN'
```

union的效率要高一些，对于表连接来说，每连接一个新表，则匹配的次数满足笛卡尔积，在减少匹配次数的情况下还可以实现两个结果集的拼接



union使用时的注意事项

union在进行结果集合并的时候，要求两个结果集的列数相同，不然会报错

结果集合并时，列和列的数据类型也需要一致