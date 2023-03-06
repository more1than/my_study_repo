## 容器

有了奖项才可以创建容器

### 新建容器并启动

```shell
docker run [可选参数] image
# 参数说明
--name='NAME'  容器名字 tomcat01 tomcat02用来区分容器
-d  		   后台方式运行
-it			   使用交互方式运行，进入容器查看内容
-p			   执行容器端口 -p 8080:8080  主机端口:容器端口
-P   	       指定随机端口
--rm 		   用来测试，表示用完容器自动删除
```

### 启动并进入容器内核的操作系统中

```bash
docker run -it centos /bin/bash
[root@45ca9f5c9bdf ~]#
[root@45ca9f5c9bdf ~]# exit
exit   退出容器
通过ctrl + p + q 不停止容器退出
```

### 列出所有运行的容器

```bash
docker ps 命令
-a # 列出当前正在运行的容器，带出历史容器
-n=? # 列出最近创建的容器 n=1
-q # 只显示当前容器编号
```

### 删除容器

```bash
docker rm 容器id  # 删除指定容器
docker rm -f 容器id # 强制删除，正在运行的容器也可以删除
docker ps -a -q|xargs docker rm # 删除所有容器
```

### 启动停止容器

```bash
docker start 容器id # 开启容器
docker restart 容器id # 重启容器
docker stop 容器id # 停止容器
docker kill 容器id # 
```

### 后台启动容器

```bash
docker run -d centos 
# -d 后台启动
常见的坑：容器使用后台运行的时候必须有一个前台容器在运行，不然后台进程无法启动
```

