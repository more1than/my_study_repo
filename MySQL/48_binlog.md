MYSQL中的binlog全称是binary log 简称为binlog，就是我们平时说的二进制日志

binlog在mysql中默认是不开启的，因为他需要消耗一些性能，如果做主从同步集群时，master主库上面的binlog是必需要打开的

验证binlog日志是否开启

```sql
show variables like "%log_bin%";

+---------------------------------+-------+
| Variable_name                   | Value |
+---------------------------------+-------+
| log_bin                         | OFF   |  /*这里显示OFF，表示没有开启binlog日志。*/
| log_bin_basename                |       |
| log_bin_index                   |       |
| log_bin_trust_function_creators | OFF   |
| log_bin_use_v1_row_events       | OFF   |
| sql_log_bin                     | ON    |
+---------------------------------+-------+
6 rows in set (0.02 sec)
```

这是开启了binlog的效果

```sql
mysql> show variables like '%log_bin%';
+---------------------------------+--------------------------------+
| Variable_name                   | Value                          |
+---------------------------------+--------------------------------+
| log_bin                         | ON                             |/*这显示ON，表示已经开启binlog*/
| log_bin_basename                | /var/lib/mysql/mysql-bin       |/*这是binlog日志文件存放的目录和名称*/
| log_bin_index                   | /var/lib/mysql/mysql-bin.index |/*这是binlog日志文件的索引文件目录和名称*/
| log_bin_trust_function_creators | OFF                            |
| log_bin_use_v1_row_events       | OFF                            |
| sql_log_bin                     | ON                             |
+---------------------------------+--------------------------------+
6 rows in set (0.02 sec)
```



其中 log_bin_basename: 这是配置的binlog日志文件的存放目录及名称，因为binlog日志是一个一直滚动追加的日志文件，当超过一个指定的默认值（通常是1GB）后，会自动切换到另一个新的binlog文件中

log_bin_index 这个配置是binlog文件的索引文件存储目录和名称，里面记录了mysql目前所有的有效的binlog文件列表，每一个binlog文件一行，按照binlog日志生成的时间顺序依次排列

### 开启和关闭binlog日志

在mysql的配置文件my.cnf中

```ini
[mysqld]
# 启用二进制日志
log-bin=mysql-bin

# 选择性的开启binlog
# 此参数表示只记录制定数据库的二进制日志，下面配置的是只记录mydb1,mydb2,mydb3,mydb4着四个数据库的binlog日志，其他数据库的binlog日志不记录。
binlog_do_db=mydb1,mydb2,mydb3,mydb4
```



可以通过sql_log_bin参数来控制某些有变更的sql语句是否可以被记录在binlog中

```sql
mysql> show variables like 'sql_log_bin';/*查看当前sql_log_bin参数的值为on,表示会记录所有当前session操作的SQL语句。*/
+---------------+-------+
| Variable_name | Value |
+---------------+-------+
| sql_log_bin   | ON    |
+---------------+-------+
1 row in set (0.01 sec)

mysql> set session sql_log_bin=off;/*关闭当前session记录binlog的功能*/
Query OK, 0 rows affected (0.00 sec)

mysql> show variables like 'sql_log_bin';/*查看后，确实关闭的session的binlog记录功能。*/
+---------------+-------+
| Variable_name | Value |
+---------------+-------+
| sql_log_bin   | OFF   |
+---------------+-------+
1 row in set (0.01 sec)

mysql> show master status;/*查看当前binlog日志的文件名称和位置。*/
+------------------+----------+--------------+------------------+-------------------+
| File             | Position | Binlog_Do_DB | Binlog_Ignore_DB | Executed_Gtid_Set |
+------------------+----------+--------------+------------------+-------------------+
| mysql-bin.000013 |      632 |              | mysql            |                   |
+------------------+----------+--------------+------------------+-------------------+
1 row in set (0.01 sec)

mysql> create table t(id int);/*创建了一个表t，这个DDL语句应该不会被记录在binlog日志中。*/
Query OK, 0 rows affected (0.03 sec)

mysql> show master status;/*再次查看当前binlog日志的文件名称和位置，和创建表t之前的文件名称和位置是相同的，就是说binlog日志并没有向后滚动增加。*/
+------------------+----------+--------------+------------------+-------------------+
| File             | Position | Binlog_Do_DB | Binlog_Ignore_DB | Executed_Gtid_Set |
+------------------+----------+--------------+------------------+-------------------+
| mysql-bin.000013 |      632 |              | mysql            |                   |
+------------------+----------+--------------+------------------+-------------------+
1 row in set (0.01 sec)

```

