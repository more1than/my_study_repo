使用redis缓存浏览商品id

每次添加都添加在列表最前，方便获取时顺序遍历

### id去重

商品id加入redis列表之前，判断列表中是否存在该商品，有则去重

截取redis列中前5个，或指定数量



视图中指定序列化器及权限，浏览记录仅登录用户查看

```python
class UserBrowserHistoryView(CreateAPIView):
    """用户商品浏览记录"""
    # 指定序列化器
    permission_classes = [IsAuthenticated]
    serializer_class = UserBrowserHistorySerializer
```

对应序列化器，redis逻辑代码在其中，使用redis中的list数据类型

及redis中list相关函数实现

```python
class UserBrowserHistorySerializer(serializers.Serializer):
    """保存商品浏览记录序列化器"""
    sku_id = serializers.IntegerField(label="商品sku_id", min_value=1)

    def validate_sku_id(self, attrs):
        """单独校验sku_id字段"""
        try:
            SKU.objects.get(id=attrs)
        except SKU.DoesNotExist:
            raise serializers.ValidationError("sku_id字段无效")
        return attrs

    def create(self, validated_data):
        sku_id = validated_data.get("sku_id")
        # 序列化器中获取当前的用户模型对象
        user = self.context["request"].user
        # 创建redis连接对象
        redis_conn = get_redis_connection("history")
        # 创建redis管道
        pl = redis_conn.pipeline()
        # 去重
        pl.lrem("history_%d" % user.id, 0, sku_id)
        # 添加到列表左侧
        pl.lpush("history_%d" % user.id, sku_id)
        # 截取前5个元素
        pl.ltrim("history_%d" % user.id, 0, 5)
        # 执行管道
        pl.execute()
        return validated_data
```



获取浏览记录视图接口

```python
    def get(self, request):
        """查询商品浏览记录"""
        # 创建redis链接对象
        redis_conn = get_redis_connection("history")
        # 获取redis中当前用户的浏览记录列表
        sku_ids = redis_conn.lrange("history_%d" % request.user.id, 0, -1)
        # 通过列表中sku_id获取sku模型
        # SKU.objects.filter(id__in=sku_ids)  此方法可以遍历获取集合中的元素进行查询，可是会打乱顺序(id__in)
        sku_list = []
        for sku_id in sku_ids:
            sku = SKU.objects.get(id=sku_id)
            sku_list.append(sku)
        # 创建序列化器进行序列化
        serializer = SKUSerializer(sku_list, many=True)
        # 响应
        return Response(serializer.data)
```

