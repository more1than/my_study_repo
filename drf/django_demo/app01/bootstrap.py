from django import forms


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
