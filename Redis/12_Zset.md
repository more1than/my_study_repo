### Zset(有序集合)

在set的基础上增加了一个值

```bash
# 创建zset,添加一个值
127.0.0.1:6379> zadd myset 1 one
(integer) 1
# 添加多个值
127.0.0.1:6379> zadd myset 2 two  3 three
(integer) 2
# 查询zset中的值
127.0.0.1:6379> zrange myset 0 -1
1) "one"
2) "two"
3) "three"
```



将序号当作薪资来操作

-inf   +inf 正负无穷

```bash
# 插入元素
127.0.0.1:6379> zadd sala 2500 zhanghao
(integer) 1
127.0.0.1:6379> zadd sala 5000 zhao
(integer) 1
127.0.0.1:6379> zadd sala 500 jintaoo
(integer) 1
# 根据薪资（序号）排序
127.0.0.1:6379> ZRANGEBYSCORE sala -inf +inf
1) "jintaoo"
2) "zhanghao"
3) "zhao"
# 显示小于2500员工的升序排序
127.0.0.1:6379> zrangebyscore sala -inf 2500 withscores
1) "jintaoo"
2) "500"
3) "zhanghao"
4) "2500"
```



移除元素zrem

```bash 
127.0.0.1:6379> zrange sala 0 -1
1) "jintaoo"
2) "zhanghao"
3) "zhao"
# 移除指定元素
127.0.0.1:6379> zrem sala zhanghao
(integer) 1
# 移除全部元素
127.0.0.1:6379> zremrangebyrank myset 0 -1
(integer) 0
```



利用zcount查看总数

```bash
127.0.0.1:6379> zadd myset 1 hello
(integer) 1
127.0.0.1:6379> zadd myset 2 world 3 kuangzshen
(integer) 2
# 查看区间内的元素数量
127.0.0.1:6379> zcount myset 0 10
(integer) 3
```

