age字段校验

```python
class StudentModelSerializer(serializers.ModelSerializer):
    """学生信息序列化器"""
    # 1.转换的字段声明
    nickname = serializers.CharField(read_only=True)

    # 2.如果当前序列化器继承的是ModelSerializer, 则需要声明调用的模型信息
    # 必须给Meta声明两个属性
    class Meta:
        # model传入要继承的模型
        model = Student
        # 字段列表
        fields = "__all__"
        # 只读字段（选填）, 只会在序列化阶段采用
        # read_only_fields = []
        # 字段额外项声明（选填）
        extra_kwargs = {
            "age": {
                "min_value": 5,
                "max_value": 20,
                "error_messages": {
                    "min_value": "最小值必须大于等于5岁",
                    "max_value": "最大值必须小于等于20岁",
                }
            },
        }
```