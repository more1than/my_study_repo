### Commit镜像

自制镜像

如果要保存当前容器状态，可以通过commit提交，获得一个镜像

```bash
docker commit 提交容器成为一个新的副本
-m="提交的描述信息"
-a="作者id"
# 传入的镜像名和tag是自定义，自主命名的
docker commit 容器id 镜像名:tag
```

