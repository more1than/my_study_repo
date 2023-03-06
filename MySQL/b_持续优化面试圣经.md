## SQL性能优化

```sql
1. 正确的建立索引，有索引查询速度非常快

2. SQL语句中IN包含的值不应该过多，能用between就不要用IN，但速度差距不会特别大

3. SELECT语句后务必要指明字段名称，禁止使用SELECT * FROM

4. 只查询一条数据的时候使用limit1 

5. 避免再where字句对字段进行NULL值的判断,MYSQL会根据表中为空数据的多少决定是否使用索引，概率导致索引失效
   ex: SELECT id FROM user WHERE phone is null; 
   
6. 避免在WHERE子句中对字段进行表达式操作
   ex: SELECT id FROM user WHERE uid*10=40; 
   对字段进行了算数操作会导致索引失效，建议改成
   ex: SELECT id FROM user WHERE uid=40/10;
   
7. 使用联合索引时，要使用最左前缀法则，入组合索引（id, name, sex） 可以使用id 或 id,name 禁止直接使用name 或 sex会导致索引失效

8. 不能使用前 % 查询，会导致索引失效

9. 避免 WHERE 子句中使用函数操作

10. 字符串类型字段查询时，如果不加引号“”，会导致自动进行隐式转换，进而索引失效

11. 多次提交数据时，可以手动开启事务，节省资源

12. count 函数使用count(*)相比count其他用法效率更高，因为MyIASM引擎会默认存储数据总数

13. 最好不要给数据库留空字段，尽量使用非空字段填充

14. not in 和<> 操作都会对全表扫描，索引失效，使用between和 exists代替

15. 数据唯一行越高，索引效果越好，比如性别只有两个，添加索引反而影响速度
```

![img](https://img-blog.csdnimg.cn/20200925161801761.png)





