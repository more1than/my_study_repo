### String（字符串）

创建/设置值

```bash
set key value
```

查询值

```bash
get key
```

查询所有key

```bash
keys *
```

判断一个key是否存在，如果key不存在则创建一个key内容为空

```bash
exists key
```

追加字符串，如果key不存在则自动创建一个key

```bash
append key string
```

删除和批量删除

```bash
del key
del key1 key2 key3
```

自增1

```bash
incr key
```

自减1

```bash
decr key
```

可以设置步长来指定增量

```bash
incrby key 10
decrby key 10
```

截取字符串

```bash
getrange key start end
getrange key 0 3
getrange key 0 -1
```



替换

```bash
setrange key start value
setrange key 1 xx   # "axxdefg"
```



setex   (set with expire)  设置过期时间

setnx （set if not exist） 不存在再去设置（在分布式锁中会常常使用）

```bash
setex key 30 "hello" # 设置值为hello  30秒后过期
setnx mykey "aaa"  # 如果不存在就创建key
setnx mykey "bbb"  # 如果mykey已存在则创建失败
```



批量操作

```bash
mset k1 v1 k2 v2 k3 v3
```

批量获取

```bash
mget k1 k2 k3
```

```
k1已经被创建但是k4没有被创建，该命令会创建k4，所以msetnx命令具有原子性（要么一个部分都不执行，要么全部执行）
msetnx k1 v1 k4 v4
```



### 对象

设计特殊一些的键

```bash
user:{id}:{filed}
```

```bash
mset user:1:name zhanghao user:1:age 18
mget user:1:name user:1:age
```



联合命令 getset  先查询后赋值

```bash
getset key value  # 如果不存在值，则返回nil并设置新的值
```



string类型使用场景，value除了字符串还可以是数字

1.计数器

2.统计多单位数量 

3.粉丝数

4.对象缓存存储