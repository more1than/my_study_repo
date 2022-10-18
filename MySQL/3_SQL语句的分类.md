```mysql
DQL: 数据库查询语言（凡是带有select关键字的都是查询语句）
	select...
DML: 数据操作语言(凡是对表中的数据进行增删改操作的的都是DML)
	insert 增
	delete 删
	update 改
DDL: 数据定义语言（凡是带有create, drop, alter的都是DDL）
主要操作的是表的结构，不是表中的数据
TCL: 事务控制语言，包括事务提交，事务回滚
	commit 提交
	rollback 回滚
DCL：数据控制语言
	grant 授权
	revoke 撤销权限
```

 查询表中数据

```mysql
select 字段 from 表名;
```

查询表的信息

```mysql
desc 表名;
```

查看当前数据库版本号

```mysql
select version();
```

查看当前使用的是哪个数据库

```mysql
select database();
```

