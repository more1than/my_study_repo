使用benchmark进行性能测试

100个并发连接，100000次请求

```dos
redis-benchmark.exe -h localhost -p 6379 -c 100 -n 100000
```



回显解析

```
====== SET ======
 # 对十万个请求进行写入测试
  100000 requests completed in 0.89 seconds
 # 100个并发客户端
  100 parallel clients
 # 每次写入三个字节
  3 bytes payload
 # 只有一台服务器来处理，单机性能
  keep alive: 1

# 一毫秒的时间处理了98.69%的请求
98.69% <= 1 milliseconds
99.80% <= 2 milliseconds
99.86% <= 3 milliseconds
99.93% <= 4 milliseconds
99.99% <= 5 milliseconds
# 所有请求在5毫秒内处理完毕
100.00% <= 5 milliseconds
# 每秒处理多少个请求（111731.84）
111731.84 requests per second
```

