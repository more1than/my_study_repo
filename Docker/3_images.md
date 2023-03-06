## 镜像

### 查看所有本机下的镜像

```bash
C:\Users\zkf9676>docker images
REPOSITORY   TAG       IMAGE ID       CREATED      SIZE
redis        latest    c2342258f8ca   3 days ago   117MB
```

repository：镜像仓库

tag：镜像标签

image id：镜像id

create： 镜像的创建时间

size：镜像的大小

```bash
# 可选项
-a 列出所有镜像
-q 只显示镜像id
可以联合使用  -aq
```

```bash
docker tag imageid author/image_name:tag
```



### 搜索镜像，和网页上查询操作一致

```bash
C:\Users\zkf9676>docker search mysql
NAME                            DESCRIPTION                                     STARS     OFFICIAL   AUTOMATED
mysql                           MySQL is a widely used, open-source relation…   13398     [OK]  
```

可选项

```bash
--filter=STARS=3000 搜索出来的镜像STARS数量大于3000
```



### 下载镜像

```bash
# docker pull 镜像名[:tag]默认使用最新版本
C:\Users\zkf9676>docker pull mysql
Using default tag: latest # 如果不指定，那么默认就是latest，最新版本
latest: Pulling from library/mysql
d67a603b911a: Pull complete # 分层下载，docker image的核心 联合文件系系统
0cf69c8f1492: Pull complete
a5ee239a0d3a: Pull complete
0f166cb3e327: Pull complete
882d294bf188: Pull complete
2649fc7eb806: Pull complete
bddb3394e2e3: Pull complete
93c83d9a2206: Pull complete
99d7f45787c0: Pull complete
234663a2e3ee: Pull complete
74531487bb7b: Pull complete
Digest: sha256:d4055451e7f42869e64089a60d1abc9e66eccde2910629f0dd666b53a5f230d8 # 签名， 防伪标志
Status: Downloaded newer image for mysql:latest
docker.io/library/mysql:latest # 真实地址
# 相当于 docker pull docker.io/library/mysql:latest
```



### 删除镜像

```bash
docker rmi -f image-id
```

