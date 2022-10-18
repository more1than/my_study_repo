# 管理员方式打开CMD

### 初始化mysql 

**mysqld.exe --initialize --console**

### 安装mysql服务

 **mysqld.exe install mysql** 

### 启动mysql服务 

**net start mysql**

### 停止mysql服务

**net stop mysql**



### 先启动服务再修改密码

### 修改密码

mysql.exe -uroot -p

会提示输入密码，要输入的密码就是初始化时候产生的那一串字符

ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';

PS: password就是要修改成密码
