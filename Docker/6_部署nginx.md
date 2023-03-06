```bash
1.搜索镜像 search
2.拉取镜像 pull
3.测试运行
docker run -d --name nginx01 -p 3344:80 nginx
# -d 后台运行
# --name 指定容器名
# -p 暴露端口，宿主机端口映射容器内部端口
```



本机自测

```bash
C:\Users\zkf9676>curl localhost:3344
<!DOCTYPE html>
<html>
<head>
<title>Welcome to nginx!</title>
<style>
html { color-scheme: light dark; }
body { width: 35em; margin: 0 auto;
font-family: Tahoma, Verdana, Arial, sans-serif; }
</style>
</head>
<body>
<h1>Welcome to nginx!</h1>
<p>If you see this page, the nginx web server is successfully installed and
working. Further configuration is required.</p>

<p>For online documentation and support please refer to
<a href="http://nginx.org/">nginx.org</a>.<br/>
Commercial support is available at
<a href="http://nginx.com/">nginx.com</a>.</p>

<p><em>Thank you for using nginx.</em></p>
</body>
</html>
```

进入容器内部

```bash
C:\Users\zkf9676>docker exec -it 092 /bin/bash
root@092ad684b16d:/# whereis nginx
nginx: /usr/sbin/nginx /usr/lib/nginx /etc/nginx /usr/share/nginx
root@092ad684b16d:/# cd /etc/nginx
root@092ad684b16d:/etc/nginx# ls
conf.d  fastcgi_params  mime.types  modules  nginx.conf  scgi_params  uwsgi_params
root@092ad684b16d:/etc/nginx# docker run -d --name nginx01 -p 3344:80 nginx
```



每次要修改nginx配置文件都需要进入容器内部，非常麻烦，是否可以在容器外部映射一个路径，达到在外部容器修改文件名，容器内部就自动修改？ -v 数据卷