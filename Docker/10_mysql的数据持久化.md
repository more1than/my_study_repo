## Mysql持久化

mysql配置需要密码，可以到docker hub官网上查询到对应命令

```bash
docker run -d -p 3310:3306 -v /e/docker_test/for_mysql/conf:/etc/mysql/conf.d -v /e/docker_test/for_mysql/data:/var/lib/mysql -e  MYSQL_ROOT_PASSWORD=123456 --name=mysql01 mysql
映射mysql配置数据卷和mysql真实数据的卷
```

映射数据卷后，容器即使删除，挂载到本地的数据卷依旧存在，这就说明了实现了持久化功能

