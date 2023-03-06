## Dockerfile

dcokerfile就是构建docker镜像的构建文件

建议文件名使用Dockerfile

```dockerfile
# 文件中的指令使用大写参数
FROM centos

VOLUME ["volume01", "volume02"]

CMD echo "-----end-----"
CMD /bin/bash
```

使用dockerfile生成镜像

```bash
docker -f dockerfile_path -t iamges_name .
```

假设构建镜像时没有挂在卷，需要手动挂载 -v 卷名：容器内路径



## 容器间数据同步

先创建容器docker01

```bash
docker run -it --name docker01 df103
```

在创建docker02，根据打通关联数据卷

```
docker run -it --name docker02 --volumes-from docker01 df103
```

如果在docker01中创建文件，docker02中便能共享得到

使用docker02 和docker03关联docker01,如果删除docker01 

容器之间可以配置信息的传递，数据卷容器的生命周期一直持续到没有容器使用为止

