## Redis.conf

启动的时候就是通过配置文件启动的

### 单位

对单位的大小写不敏感

```bash
# 1k => 1000 bytes
# 1kb => 1024 bytes
# 1m => 1000000 bytes
# 1mb => 1024*1024 bytes
# 1g => 1000000000 bytes
# 1gb => 1024*1024*1024 bytes
#
# units are case insensitive so 1GB 1Gb 1gB are all the same.
```



### 包含

可以包含其他配置文件

```bash
################################## INCLUDES ###################################

# include .\path\to\local.conf
# include c:\path\to\other.conf
```



### 网络配置

可以更换ip和端口

```bash
################################## NETWORK #####################################

# By default, if no "bind" configuration directive is specified, Redis listens
# for connections from all the network interfaces available on the server.
# It is possible to listen to just one or multiple selected interfaces using
# the "bind" configuration directive, followed by one or more IP addresses.
#
# Examples:
#
# bind 192.168.1.100 10.0.0.1
# bind 127.0.0.1 ::1
bind 127.0.0.1
```



### 通用配置

```
daemonize yes
```

以守护进程的方式运行，默认是no，需要自己开启为yes，便可以退出的时候不结束redis

```bash
logfile ""  # 日志文件名
loglevel notice # 日志等级
databases 16 # 数据库的默认数量
```

也可以更改日志级别

```
################################# GENERAL #####################################

# By default Redis does not run as a daemon. Use 'yes' if you need it.
# Note that Redis will write a pid file in /var/run/redis.pid when daemonized.
# NOT SUPPORTED ON WINDOWS daemonize no
```



### 快照

在规定时间内执行了多少次操作，则会持久化到文件.rdb   .aof

redis是内存数据库，如果没有持久化那么数据就会断电即失

```bash
# 如果900秒内，至少有一个key进行了修改，我们就进行持久化操作
save 900 1 
# 如果300秒内，至少有10个key进行了修改，我们就进行持久化操作
save 300 10
# 如果60秒内，至少有1000个key进行了修改，我们就进行持久化操作
save 60 10000
# 也可以自己定义时间及次数

# 持久化如果出错，是否还需要继续工作
stop-writes-on-bgsave-error yes
# 是否压缩rdb文件，默认开启，会消耗cpu资源
rdbcompression yes
# 保存rdb文件的时候进行错误的检查校验
rdbchecksum yes
# rdb持久化文件的保存目录 
dbfilename dump.rdb
```



### 主从复制 REPLICATION 



### 安全 SECURITY 

```bash
在这句注释的下一行插入密码
# requirepass foobared
requirepass 123456
```

也可以使用命令设置密码

```bash
# 设置密码
127.0.0.1:6379> config set requirepass 123456
OK
# 试用命令没有权限
127.0.0.1:6379> config get requirepass 123456
(error) NOAUTH Authentication required.
# 登录redis
127.0.0.1:6379> auth 123456
OK
```



### 限制CLIENTS

```bash
# 连接上redis的最大客户端数
maxclients 10000
# redis配置的最大内存容量
maxmemory <bytes>
# 内存达到上限之后的处理策略
maxmemory-policy noeviction
	# 移除一些过期的key 或 报错等操作
	
```

#### maxmemory-policy 六种方式

```bash
# 只对设置了过期时间的key进行LRU（默认值）
1、volatile-lru 
# 删除lru算法的key  
2、allkeys-lru 
# 随机删除即将过期key  
3、volatile-random
# 随机删除 
4、allkeys-random
# 删除即将过期的
5、volatile-ttl 
# 永不过期，返回错误
6、noeviction
```



### APPEND ONLY 模式 aof配置

```bash
# 默认是不开启aof模式的
appendonly no
# 持久化文件的名字
appendfilename "appendonly.aof"

# 每次修改都会同步，消耗性能
# appendfsync always  
# 每秒执行一次同步，可能会丢失这一秒的数据
appendfsync everysec
# 不执行同步，这个时候操作系统自己同步数据，速度最快
# appendfsync no
```

