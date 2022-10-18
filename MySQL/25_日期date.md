格式化数字

format

```sql
select ename, format(sal, '$999,999') as sal from emp;
```



str_to_date：将字符串varchar类型转换为date类型

date_fromat: 将date类型转换成具有一定格式的varchar字符串类型

生日字段可以是用字符串，也可以使用date类型

字段定义为date后，如何传入日期格式，使用str_to_date函数

语法格式

```sql
str_to_date("字符串日期", "日期格式")
```

mysql日期格式：

```sql
%Y 年， %m 月， %d 日， %h 时， %i 分 , %s 秒
```

```sql
insert into t_user(id, name, birth) values(1, 'zhang'， str_to_date("10-01-1999", "%d-%m-%Y");
```

插入一个日期类型时，需要通过该函数从字符串转化为date

如果日期的格式常规，则自动类型转换

```sql
insert into t_user values(1, 'zhang', "1999-10-10");
```



date_format 可以将日期类型转换为特定格式的字符串

```sql
select id, name, date_format(birth, '%m/%d/%Y') as birth from t_user;
```

```sql
date_format(日期类型数据， '日期格式')
这个函数通常使用在查询日期方面，设置展示的日期格式
```



sql语句实际上进行了默认的日期格式化，自动将数据库中的date类型转换为了varchar，并采用的格式是mysql默认的日期格式：'%Y-%m-%d'



date和datetime的区别

date是短日期：只包括年月日

datetime是长日期：包括年月日时分秒信息



now函数获取系统当前时间

now是datetime类型

```sql
insert into t_user values(2, 'hao', '1949-10-01', now())
```

