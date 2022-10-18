下载

https://www.mongodb.com/try/download/community?tck=docs_server

我们需要去把他的环境变量配置一下：右击此电脑=>属性=>高级系统设置=>环境变量=>
找到Path双击进去，新建，内容是刚刚安装的MongoDB的Bin文件夹位置，我装的是E盘，路径为E:\MongoDB\bin
配置完环境变量，我们在C盘的根目录去创建一个data文件夹，在里面再建一个db文件夹
我们打开cmd（win+r打开巡行输入cmd），输入mongod，他会跑出来一堆代码，这时候我们再去看刚刚新建的db文件夹，里面已经有东西了
我们再新建一个cmd，输入mongo（mongod用来启动服务器，mongo用来启动客户端），出现 >就差不多了，这样我们就快好了
c盘的data文件夹下继续新建log文件夹
在mongoDB的文件夹里（bin的上一级）我们要新建一个mongod.cfg文件，以记事本方式打开，内容为

```
systemLog:
    destination: file
    path: c:\data\log\mongod.log
storage:
    dbPath: c:\data\db
```

