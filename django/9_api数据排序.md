#### 升序降序排列

升序降序可通过减号控制，字符串传入要排列的字段

```python
def pretty_list(request):
    # 等同于sql语句：select * from 表 order by level desc;
    queryset = models.PrettyNum.objects.all().order_by("-level")
    queryset = models.PrettyNum.objects.all().order_by("level")
    return queryset
```

