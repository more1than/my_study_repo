安装第三方库

```
pip install drf-extensions
```



settings中指定

```
REST_FRAMEWORK_EXTENSIONS = {
    # 缓存时间
    "DEFAULT_CACHE_RESPONSE_TIMEOUT": 60 * 60,
    # 缓存存储
    "DEFAULT_USE_CACHE": "default",
}
```

视图类中继承对应类

```
ListCacheResponseMixin 为list方法添加缓存功能
RetrieveCacheResponseMixin 为Retrieve方法添加缓存功能
CacheResponseMixin 两个类配合使用
```



首次查询时会默认备份至redis中，再次进行查询时，自动访问redis中的数据