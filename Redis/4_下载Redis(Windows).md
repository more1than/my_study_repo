github下载源码包

```url
https://github.com/MicrosoftArchive/redis/tags
```

5M左右的大小

下载完毕后双击redis-server.exe可执行文件打开服务端



双击redis-cil 打开客户端

输入ping 得到回显pong表示连接成功

```redis
127.0.0.1:6379> ping
PONG
```

尝试操作

```redis
127.0.0.1:6379> set name zhanghao
OK
127.0.0.1:6379> get name
"zhanghao"
```



## 踩坑

windows下redis闪退:

解决：cmd中输入（手动指定配置文件）

```bash
 D:\redis>redis-server.exe redis.windows.conf
```

