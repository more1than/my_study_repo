当该model对象被调用时，返回指定字段信息等

```python
class Task(models.Model):
    """ 任务 """
    level = models.SmallIntegerField(verbose_name="级别", choices=((1, "紧急"), (2, "一般")), default=1)
    title = models.CharField(verbose_name="标题", max_length=64)
    detail = models.TextField(verbose_name="详细信息")
    user = models.ForeignKey(verbose_name="负责人", to="Admin", on_delete=models.CASCADE)

    # 当该model对象被调用时，返回指定字段信息等
    def __str__(self):
        return self.level
```

