limit 是将查询结果集的一部分取出来，通常用于分页

按照薪资降序，取出排名前5的员工

```sql
select ename, sal from emp order by sal desc limit 5;
```

完整写法

```sql
select ename, sal from emp order by sal desc limit 5;
```



limit startIndex   length

startIndex是起始下标，length是长度

mysql中，limit在order by之后执行



取出工资排名在3~5的员工

```sql
select ename, sal from emp order by sal desc limit 2, 3;
```

2 表示起始下标，0   1    2 ，  其中2排在第三

3表示要取的长度，从2包括2往后取两个



java分页函数

```java
public static void main(String[] args){
	// 用户提交过来一个页码，以及每页显示的记录条数
	int pageNo = 5; //第五页
	int pageSize = 10; // 每页显示10条
	
	int startIndex = (pageNo-1) * pageSize;
	String sql = "select ...limit" + startIndex + ", "+ pagesize;
}
```

分页公式：

```sql
limit (pageNo-1) * pageSize , pageSzie
```

