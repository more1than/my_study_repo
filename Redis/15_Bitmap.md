### Bitmap位存储

统计用户信息，活跃不活跃，登录未登录都可以使用bitmaps

```bash
# 定义从周一开始的打卡记录
127.0.0.1:6379> setbit sign 0 1
(integer) 0
127.0.0.1:6379> setbit sign 1 0
(integer) 0
127.0.0.1:6379> setbit sign 2 0
(integer) 0
127.0.0.1:6379> setbit sign 3 1
(integer) 0
127.0.0.1:6379> setbit sign 4 1
(integer) 0
127.0.0.1:6379> setbit sign 5 0
(integer) 0
127.0.0.1:6379> setbit sign 6 0
(integer) 0
# 查看某一天是否打卡
127.0.0.1:6379> getbit sign 6
(integer) 0
127.0.0.1:6379> getbit sign 4
(integer) 1
# 统计打卡总数
127.0.0.1:6379> bitcount sign
(integer) 3
```

