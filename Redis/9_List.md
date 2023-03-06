### List 

list实际上是一个链表，可以在左右插入值

如果key不存在，则创建新的链表

相对来说，改动中间的元素会比改动两边的元素效率低一些

reids的基本数据类型

最后存放的元素在最左边，最先存放的元素在最右边

所有的list命令都是以L开头的

```bash
# lpush 往列表中插入值，插入列表的头部
127.0.0.1:6379> lpush list one
(integer) 1
127.0.0.1:6379> lpush list two
(integer) 2
# lrange 获取范围中的列表值（默认倒序获取）
127.0.0.1:6379> LRANGE list 0 -1
1) "two"
2) "one"
```

移除元素

lpop 移除左边第一个元素，rpop移除右边第一个元素

```bash
127.0.0.1:6379> lpop list
"three"
127.0.0.1:6379> rpop list
"-1"
```

通过下标获取list中某一个值

```bash
127.0.0.1:6379> lindex list 1
"one"
127.0.0.1:6379> lindex list 0
"two"
```

Llen返回列表的长度

```bash
127.0.0.1:6379> llen list
(integer) 3
```



移除列表中的指定值

```bash
lrem 列表名 删除个数 指定元素名

127.0.0.1:6379> lrem list 1 three
(integer) 1
```



组合命令也可以使用其他方式实现

rpoplpush  移除列表的之后一个元素并且添加一个新的元素

删除一个元素后，将该元素存储到第二个列表中

```bash
127.0.0.1:6379> rpush mylist hello
(integer) 1
127.0.0.1:6379> rpush mylist hello1
(integer) 2
127.0.0.1:6379> rpush mylist hello2
(integer) 3
127.0.0.1:6379> rpush mylist hello3
(integer) 4
127.0.0.1:6379> rpoplpush mylist myotherlist
"hello3"
# 查看原来的列表
127.0.0.1:6379> lrange mylist 0 -1
1) "hello"
2) "hello1"
3) "hello2"
127.0.0.1:6379> lrange myotherlist 0 -1
1) "hello3"
```



向列表中指定下标位置插入值

lset

```bash
lset list index item
```

```bash
127.0.0.1:6379> lset list 0 item
OK
```

将下标为0的元素设置为item

异常越界

```bash
127.0.0.1:6379> lset list 1 other
(error) ERR index out of range
```



插入元素

选择指定元素，使用before  after关键字，指定前后插入

```bash
127.0.0.1:6379> rpush mylist world
(integer) 1
127.0.0.1:6379> linsert mylist before world other
(integer) 2
127.0.0.1:6379> linsert mylist after world new
(integer) 3
127.0.0.1:6379> lrange mylist 0 -1
1) "other"
2) "world"
3) "new"
```

