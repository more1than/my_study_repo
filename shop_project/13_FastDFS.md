### FastDFS分布式文件系统

可以用来存储商城等项目中的大量商品图片

淘宝架构师为了淘宝中的大量图片创建的FastDFS项目，使用c语言编写

FastDFS架构包括 Tracker server 和 Storage server中，客户端请求Tracker server进行文件的上传，下载，通过Tracker server调度最终由Storage server完成文件上传和下载

### 流程：

django接收到上传文件请求，FastDFS客户端接收到上传图片请求并将请求转发到调度服务器，FastDFS调度服务器找到空闲的存储服务器，存储服务器存储文件后，返回给django一个file_id以标记当前的存储位置



### FILE_ID

```
group1 /M00 /02/44/ wkgakskdwiaadw.sh
```

1. 组名 2. 虚拟磁盘路径 3.数据二级目录 4.文件名称



### 使用docker拉取镜像

```shell
docker pull delron/fastdfs
```

```shell
# 启动FastDFS tracker服务
sudo docker run -dti --network=host --name tracker -v /var/fdfs/tracker:/var/fdfs delron/fastdfs tracker
# 启动FastDFS storage服务
# -e 为storage指定tracker IP要设置静态，否则重启os可能会失效
sudo docker run -dti --network=host --name storage -e TRACKER_SERVER=(my ip:22122) -v /var/fdfs/storage:/var/fdfs delron/fastdfs storage
```

-d 守护式  -t命令行 -交互式

