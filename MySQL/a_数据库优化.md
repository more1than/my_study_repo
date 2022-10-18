1.选取最适用的字段属性

2.使用连接来代替子查询

3.添加索引

4.添加外键

5.模糊查询效率不高

```sql
例如下面的查询将会比较表中的每一条记录。
 
SELECT*FROMbooks

WHEREnamelike"MySQL%"

但是如果换用下面的查询，返回的结果一样，但速度就要快上很多：
 
SELECT*FROMbooks

WHEREname＞="MySQL"andname＜"MySQM"
```

6.数据唯一性越高索引效果越好，比如性别只有两个，添加索引反而影响速度

7.mysql查询只能使用一个索引，如果where使用了索引，排序就不会使用索引，所以尽量不要包含多个列的排序

8.not in 和<> 操作都会对全表扫描，索引失效，使用between和 exists代替

9.最好不要给数据库留NULL，尽可能的使用 NOT NULL填充数据库.

10.不要在查询时使用函数操作

11.不要使用count(*)，会进行全表扫描，不要使用select  * from