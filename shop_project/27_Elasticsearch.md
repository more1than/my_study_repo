### 搜索引擎

Elasticsearch是目前全文搜索引擎的首选

底层开源库是Lucene,Elasticsearch使用java实现的

Elasticsearch不支持对中文进行分词建立索引，需要配合elasticsearch-analysis-ik来实现中文分词处理

Elasticsearch分为客户端和服务端，服务端我们配置在docker中打成镜像包创建容器，客户端在后端项目中配置需安装第三方库

```
pip install drf-haystack
pip install elasticsearch==2.4.1
```

注册应用

```
"haystack",  # 搜索模块
```

settings中配置

```python
# Haystack
HAYSTACK_CONNECTIONS = {
    "default": {
        "ENGINE": "haystack.backends.elasticsearch.ElasticsearchSearchEngine",
        "URL": "http://192.168.0.0:9200",  # ip为Elasticsearch服务端IP地址，9200是Elasticsearch的默认端口号
        "INDEX_NAME": "MYSHOP",  # 指定Elasticsearch建立的索引库名称
    }
}

# 当添加，修改，删除操作时，自动生成索引
HAYSTACK_SIGNAL_PROCESSOR = "haystack.signals.RealtimeSignalProcessor"
```

在要搜索的模型目录下创建对应的文件，文件名指定为search_indexes.py

指定查询需要的查询集

```python
from haystack import indexes
from goods.models import SKU

class SKUIndex(indexes.SearchIndex, indexes.Indexable):
    """
    SKU索引数据模型类
    """
    text = indexes.CharField(document=True, use_template=True)

    def get_model(self):
        """返回建立索引的模型类"""
        return SKU

    def index_queryset(self, using=None):
        """返回要建立索引的数据查询集"""
        return self.get_model().objects.filter(is_launched=True)  # 只搜索商家的商品
```

在templates文件夹下创建文件，层级目录为

```
templates.search.indexes.goods.sku_text.txt
```

templates.search.indexes为固定，goods为应用名，sku_text搭配模型名称

在文件中填写,代表我们针对商品的名字，id，父标题建立三个索引

```
{{ object.id }}
{{ object.name }}
{{ object.caption }}
```

运行命令手动建立索引

```
python manage.py rebuild_index
```

在对应应用中创建搜索视图

```python
class SKUSearchViewSet(HaystackViewSet):
    """SKU搜索"""
    index_models = [SKU]  # 指定查询集

    serializer_class = SKUSearchSerializer  # 指定序列化器
```

定义关联序列化器

```python
class SKUSearchSerializer(HaystackSerializer):
    """SKU索引结果数据序列化器"""
    object = SKUSerializer(read_only=True)

    class Meta:
        index_classes = [SKUIndex]
        fields = ("text", "object")
```

定义路由器

```python
router = DefaultRouter()
router.register("skus/search", views.SKUSearchViewSet, basename="skus_search")

urlpatterns += router.urls
```

