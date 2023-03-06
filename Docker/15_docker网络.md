## Docker网络

学习docker网络前清空所有镜像和容器，清空docker环境，方便docker网络学习

```bash
# 拉取tomcat镜像
docker run -d -P --name tomcat01 tomcat
# 进入容器内部，若找不到ip 命令，执行 apt update && apt install -y iproute2下载(运行过程慢，安装包大)
docker exec -it tomcat01 ip addr 
```

### 原理

每启动一个docker容器，docker就会给docker容器分配一个ip，我们只要安装了docker，就会有一个网卡docker0，使用桥接模式，桥接模式使用的技术是evth-pair技术

本地会多出一个网卡，地址是vthc，绑定者容器内部的虚拟网卡，如果再启动一个容器会发现宿主机又多了一个网卡



### evth-pair

就是一堆虚拟设备的接口，他们都是成对出现的，一段连接协议，一段彼此相连

正因为有这个特性，evth-pair充当一个个桥梁



测试两个容器中的ip地址是否能相互ping通，结论也是可以ping通的

所有容器在不指定网络的情况下，都是docker0路由的，docker会给我们容器分配一个默认的可用ip

docker中所有网络接口都是虚拟的，因为虚拟的网络传输速率很快

如果删除容器，对应的网桥便会默认也被删除

