### Hyperloglog 基数统计的算法

一个人访问一个网站多次，还是算作一个人

传统方式：用set保存用户id，set一样直接会覆盖之前的值

这种方式如果保存大量用户id会比较麻烦，消耗内存

hyperloglog的优点：占用内存固定，只需要非12kb内存

```bash
# 创建一组元素
127.0.0.1:6379> pfadd mykey a b c d e f g
(integer) 1
# 统计元素基类数量
127.0.0.1:6379> pfcount mykey
(integer) 7
127.0.0.1:6379> pfadd mykey2 i j z x c v b n
(integer) 1
127.0.0.1:6379> pfcount mykey2
(integer) 8
# 合并两个组
127.0.0.1:6379> PFMERGE mykey3 mykey mykey2
OK
127.0.0.1:6379> pfcount mykey3
(integer) 13
```

如果允许容错，一定可以使用hyperloglog

如果不允许容错就可以使用自己的数据类型或set