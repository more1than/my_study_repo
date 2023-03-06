### Hash(哈希)

map集合

hash变更的数据，存储经常变动的信息，更适合存储变动的东西

本身和string没有太大区别，还是一个简单的key-value

不同于字符串，如果给键值对赋值的时候键值对存在的时候，却不会覆盖

```bash
# 创建hash，插入一个具体的值
127.0.0.1:6379> hset myhash field1 zhanghao
(integer) 1
# 查询创建的hash
127.0.0.1:6379> hget myhash field1
"zhanghao"
# hmset 批量插入键值对
127.0.0.1:6379> hmset myhash field1 hello field2 world
OK
# hmget 批量查询键值对
127.0.0.1:6379> hmget myhash field1 field2
1) "hello"
2) "world"
# hgetall 获取hash中所有的键值对，以下述形式返回
127.0.0.1:6379> HGETALL myhash
1) "field1"
2) "hello"
3) "field2"
4) "world"
```



删除指定的键值对

```bash
# 删除hash指定key字段，对应的value也会消失
127.0.0.1:6379> hdel myhash field1
(integer) 1
127.0.0.1:6379> hgetall myhash
1) "field2"
2) "world"
```



查询有多少个键值对  hlen

```bash
# 查询哈希中有多少个键值对
127.0.0.1:6379> hlen myhash
(integer) 1
```



只获取hash中的key或values

```bash
# 获取hash中的所有key
127.0.0.1:6379> hkeys myhash
1) "field2"
# 获取hash中的所有value
127.0.0.1:6379> HVALS myhash
1) "world"
```



自增自减

```bash
# 创建一个键值对，值为5
127.0.0.1:6379> hset myhash field3 5
(integer) 1
# 自增
127.0.0.1:6379> HINCRBY myhash field3 1
(integer) 6
# 自增-1，实现自减操作
127.0.0.1:6379> HINCRBY myhash field3 -1
(integer) 5
```



**插入键值对，如果键值对存在则不执行**

```bash
# 键值对不存在的插入操作
127.0.0.1:6379> hsetnx myhash field4 hello
(integer) 1
# 键值对存在的插入操作
127.0.0.1:6379> hsetnx myhash field4 world
(integer) 0
127.0.0.1:6379> hget myhash field4
"hello"
```



