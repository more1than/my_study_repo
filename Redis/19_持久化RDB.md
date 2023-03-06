## RDB持久化

父进程单独fork出一条子进程，子进程将内存内容写入RDB文件中

生成中会将RDB备份

### 触发机制

1. save的规则满足的情况下，会自动触发rdb规则
2. 执行flushall命令，也会触发我们的rdb规则
3. 退出redis，也会产生rdb文件

备份就自动生成一个dump.rdb



### 恢复rdb文件

1. 只要将rdb文件放在我们的redis启动目录就可以，redis启动时会自动检查dump.rdb恢复其中的数据

查询配置文件目录

```bash
127.0.0.1:6379> config get dir
1) "dir"
2) "E:\\Redis\\Redis-x64-3.2.100"
```

配置

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

优点：

1. 适合大规模的数据恢复！
2. 对数据的完整性要求不高

缺点：

1. 需要一定的时间加那个进行此操作！ 如果redis意外宕机了，这个最后一次修改数据就没有了
2. fork一条进程的时候会占用一定的内存空间

