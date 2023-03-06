```python
from django.contrib import admin

from . import models


class GoodsCategoryAdmin(admin.ModelAdmin):
    """
    商品类别模型站点管理类
    """

    def save_model(self, request, obj, form, change):
        """
        当点击admin中的保存按钮时会来调用此方法
        :param request: 保存时本次请求对象
        :param obj: 本次保存的模型对象
        :param form: admin中表单
        :param change: 是否改变
        """
        obj.save()
        # 重新生成新的列表静态页面

    def delete_model(self, request, obj):
        """
        当点击admin中删除按钮时会调用此方法
        """
        obj.delete()


admin.site.register(models.GoodsCategory)
admin.site.register(models.GoodsChannel)
admin.site.register(models.Goods)
admin.site.register(models.Brand)
admin.site.register(models.GoodsSpecification)
admin.site.register(models.SpecificationOption)
admin.site.register(models.SKU)
admin.site.register(models.SKUSpecification)
admin.site.register(models.SKUImage)

```

self.kwargs技巧

```python
class SKUListView(ListAPIView):
    """ 商品列表数据查询 """
    serializer_class = ""

    # queryset = SKU.objects.filter()

    def get_queryset(self):
        """ 如果当前视图中没有定义get / post方法，就没法定义一个参数用来接收正则组提取出来的url路径参数
            可以利用视图对象的args / kwargs属性去获取
            起了别名用kwargs获取，没有起别名用args获取
        """
        category_id = self.kwargs.get("category_id")
        return SKU.objects.filter(is_launched=True, category_id=category_id)
```

