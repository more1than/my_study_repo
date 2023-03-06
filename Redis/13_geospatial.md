### geospatial 地理位置

geo底层的实现原理就是Zset集合，所以可以使用Zset命令操作geo

geoadd 添加城市数据

规则：南极北极无法添加，一版使用程序插入地理位置数据

```bash

127.0.0.1:6379> geoadd china:city 116.40 39.90 beijing
(integer) 1
127.0.0.1:6379> geoadd china:city 121.47 31.23 shanghai
(integer) 1
127.0.0.1:6379> geoadd china:city 106.50 29.53 chongqing
(integer) 1
127.0.0.1:6379> geoadd china:city 114.05 22.52 shenzhen
(integer) 1
127.0.0.1:6379> geoadd china:city 120.16 30.24 hangzhou
(integer) 1
127.0.0.1:6379> geoadd china:city 108.96 34.26 xian
(integer) 1
```



geopos 获取指定的经纬度

```bash
127.0.0.1:6379> geopos china:city beijing
1) 1) "116.39999896287918"
   2) "39.900000091670925"
```



查看两人之间的距离

geodist

单位： m(米) km（千米） mi  （英里） ft （英尺）

```bash
127.0.0.1:6379> GEODIST china:city beijing shanghai
"1067378.7564"
127.0.0.1:6379> geodist china:city beijing shanghai km
"1067.3788"
127.0.0.1:6379> geodist china:city beijing chongqing km
"1464.0708"
```



如何获取我附近的人，定位！ 

georadius  以给定的经纬度为中心，找出某一半径内的元素

```bash
127.0.0.1:6379> GEORADIUS china:city 110 30 1000 km
1) "chongqing"
2) "xian"
3) "shenzhen"
4) "hangzhou"
127.0.0.1:6379> georadius china:city 110 30 500 km
1) "chongqing"
2) "xian"
```



展示距离， 限定返回数量

```bash
# withcoord 显示经纬度距离
# 以110  30 经纬度为中心，寻找500KM内的城市
127.0.0.1:6379> georadius china:city 110 30 500 km withcoord
1) 1) "chongqing"
   2) 1) "106.49999767541885"
      2) "29.529999579006592"
2) 1) "xian"
   2) 1) "108.96000176668167"
      2) "34.2599996441893"
# count 限定返回值数量
127.0.0.1:6379> georadius china:city 110 30 500 km withdist withcoord count 1
1) 1) "chongqing"
   2) "341.9374"
   3) 1) "106.49999767541885"
      2) "29.529999579006592"
```



以城市为圆心获取指定范围内的城市

```bash
127.0.0.1:6379> GEORADIUSBYMEMBER china:city beijing 1000 km
1) "beijing"
2) "xian"
127.0.0.1:6379> GEORADIUSBYMEMBER china:city shanghai 400 km
1) "hangzhou"
2) "shanghai"
```



geohash 返回一个或多个位置元素的geohash表示

将二维的城市经纬度转换为一维的11位字符串

两个字符串越像，则表示两个城市越接近

```bash
127.0.0.1:6379> GEOHASH china:city shanghai
1) "wtw3sj5zbj0"
```

