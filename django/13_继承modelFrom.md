定义modelForm，做一些公有操作，其他modelForm来继承该model

下方便是model被继承的父类模板

```python
class BootStrapModelForm(forms.ModelForm):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        # 循环ModelForm中的所有字段，给每个字段添加数据
        for name, field in self.fields.items():
            # 字段中有属性值，保留原来，没有属性则添加
            if field.widget.attrs:
                field.widget.attrs["class"] = "a"
            else:
                field.widget.attrs = {
                    "class": "a"
                }
```

