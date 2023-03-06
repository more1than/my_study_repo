## DockerFile

### 坑：docker build最后一定有一个点(.)

```bash
编写一个dockerfile文件

docker build构建成为一个镜像

docker run 运行镜像

docker push 发布镜像(DockerHub，阿里云镜像仓库)
```

### dockerfile指令

每个指令关键字必须都是大写字母

执行顺序由上而下

 # 表示注释

每一个指令都会创建提交一个新的镜像层，并提交



dockerfile 构建文件，定义了一切的步骤

dockerimages 通过dockerfile构建生成的镜像，最终发布和运行的产品

docker container 容器就是镜像运行起来提供服务器

### 基础指令

```
FROM 指定基础镜像
MAINTAINER 维护者的信息，姓名+邮箱
RUN docker镜像构建时候运行的命令
ADD 将项目压缩包加入镜像
WORKDIR 工作目录 cd
VOLUME 设置一个挂在主机目录
EXPOSE 对外的暴露端口
CMD 指定容器启动时要运行的命令,只有最后一个命令会生效，可被替代
ENTRYPOINT 指定容器启动时要运行的命令,可以追加命令
ONBUILD	当构建一个被继承的dockerfile就会运行onbuild命令
COPY 将我们文件拷贝到镜像中
ENV 构建时候设置环境变量
```

docker hub中大部分镜像都是从基础镜像过来的 FROM scratch



```bash
通过docker history 查看构建过程
```



CMD 

```dockerfile
FROM centos
CMD ["ls", "-a"]
CMD echo 123 # 仅仅执行最后一条的CMD
```

