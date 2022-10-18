#### 验证入参方式

方式1. 利用正则校验手机号规则(ModelForm)

```python
class PrettyModelForm(ModelForm):
    mobile = CharField(
        label="手机号",
        validators=[RegexValidator(r'^1\d{10}$', "手机号格式错误")]
    )

    class Meta:
        model = Number
        # 展示所有
        # fields = "__all__"
        # 展示列表中的字段
        fields = ["mobile", "price", "level", "status"]
```

方式2. 使用内置钩子方法

钩子方法命名：clean+字段名，获取数据使用self.cleaned_data，获取入参字典

```python
class PrettyModelForm(ModelForm):
    class Meta:
        model = Number
        # 展示所有
        # fields = "__all__"
        # 展示列表中的字段
        fields = ["mobile", "price", "level", "status"]

    def clean_mobile(self):
        # 获取用户传入的数据
        txt_mobile = self.cleaned_data["mobile"]
        if txt_mobile != "xxx":
            raise Exception
        # 验证成功则返回用户入参
        return txt_mobile
```

exists函数校验数据是否存在，返回Bool

下述为钩子函数

```python
def clean_mobile(self):
    # 获取用户传入的数据
    txt_mobile = self.cleaned_data["mobile"]
    exists = Number.objects.filter(mobile=txt_mobile).exists()
    if exists:
        raise Exception("手机号已存在")
    if txt_mobile != "xxx":
        raise Exception
    # 验证成功则返回用户入参
    return txt_mobile
```



#### 更新数据：除去自身之外，其他的手机号是否和这次的重复

exclude函数，排除某一条数据，除去某一条数据

```python
def clean_mobile(self):
    # 获取用户传入的数据
    txt_mobile = self.cleaned_data["mobile"]
    # 获取主键:id
    print(self.instance.pk)
    # id不等于2, 手机号等于xxxxxxx
    exists = Number.objects.exclude(id=self.instance.pk).filter(mobile=txt_mobile).exists()
    if exists:
        raise Exception("手机号已存在")
    if txt_mobile != "xxx":
        raise Exception
    # 验证成功则返回用户入参
    return txt_mobile
```