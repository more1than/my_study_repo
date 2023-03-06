### 查看日志

```bash
docker logs -tf --tail 10 容器id
-tf 显示全部日志，-f带上时间戳
--tail 10 查询10条
```

### 查看容器中的进程信息

```bash
C:\Users\zkf9676>docker top 容器id
```



### 查看镜像元数据

```bash
C:\Users\zkf9676>docker inspect 容器id
```



### 进入容器命令和拷贝命令

进入使用后台法昂是运行的容器

```bash
C:\Users\zkf9676>docker exec -it f406 /bin/bash
exec命令进入
```

第二种方式

```
docker attach 容器id
进入正在执行的代码
```

exec是开启一个新的终端进入，attach是进入容器正在执行的终端

### 删除所有容器 

linux系统删除所有容器

```bash
docker rm -f $(docker ps -aq)
```



### 从容器拷贝文件到主机上

```bash
docker cp 容器id:容器内路径 目的主机路径
```

拷贝是一个手动过程，未来可以使用-v 数据卷的技术来实现