### SET集合（无序不重复集合）

set中的值不能重复

创建集合，存放值

```bash
# set集合中添加元素
127.0.0.1:6379> sadd myset hello
(integer) 1
127.0.0.1:6379> sadd myset kuangshen
(integer) 1
127.0.0.1:6379> sadd myset love
(integer) 1
# 查看指定的set值
127.0.0.1:6379> SMEMBERS myset
1) "love"
2) "kuangshen"
3) "hello"
# 判断某一个值是否在set中
127.0.0.1:6379> SISMEMBER myset hello
(integer) 1
127.0.0.1:6379> sismember myset he
(integer) 0
```



scard 获取set集合中的个数

```bash
127.0.0.1:6379> scard myset
(integer) 3
```



移除set集合中的指定元素

```bash
127.0.0.1:6379> SREM myset hello
(integer) 1
```



随机抽选出元素  sranmember

```bash
127.0.0.1:6379> SRANDMEMBER myset
1) "kuangshen"
# 随机抽选出指定数量的元素
127.0.0.1:6379> SRANDMEMBER myset 1
1) "love"
```



随即删除指定的key

```bash
# 随机删除set集合中的元素
127.0.0.1:6379> spop myset
1) "kuangshen"
127.0.0.1:6379> SMEMBERS myset
1) "love"
```



移动指定的值到另外一个集合中

```bash
smove myset1 myset2 member

127.0.0.1:6379> smove myset myset2 love
(integer) 1
```



数学集合类

```bash
127.0.0.1:6379> sadd key1 a
(integer) 1
127.0.0.1:6379> sadd key1 b
(integer) 1
127.0.0.1:6379> sadd key1 c
(integer) 1
127.0.0.1:6379> sadd key2 c
(integer) 1
127.0.0.1:6379> sadd key2 d
(integer) 1
127.0.0.1:6379> sadd key2 e
(integer) 1
# 查看差集
127.0.0.1:6379> sdiff key1 key2
1) "b"
2) "a"
# 查看交集
127.0.0.1:6379> sinter key1 key2
1) "c"
# 查看并集
127.0.0.1:6379> SUNION key1 key2
1) "c"
2) "a"
3) "b"
4) "e"
5) "d"
```

