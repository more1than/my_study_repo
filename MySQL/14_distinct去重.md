distinct 去重关键字

distinct只能出现在所有字段之前

distinct出现在字段之前，表示字段联合去重

```sql
select distinct name, age from tb_student;
```

