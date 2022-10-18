关联model的字段

```python
class MyForm(ModelForm):
    class Meta:
        model = Student
        fields = ["name", "password", "age"]
```



```python
class StudentModelForm(ModelForm):
    class Meta:
        model = Student
        fields = ["user", "gender", "owner_class"]
        
    def __init__(self, *args, **kwargs):
        super().__init__(self, *args, **kwargs)
        for name, field in self.fields.items():
            print(name, field)
```



view对应视图

```python
def user_model_form_add(request):
    # 获取前端POST请求的数据
    form = StudentModelForm(data=request.POST)
    if form.is_valid():
        # 保存用户为输入的数据
        form.instance.password = "123"
        # 将数据存储到数据库中
        form.save()
        print(form.cleaned_data)
    else:
        print(form.errors)
```



```python
def user_edit(request, id):
    # 传入数据库查询到的数据
    row_object = Student.objects.filter(id=id).first()
    form = StudentModelForm(instance=row_object)
    print(form)
```



创建用户modelform

```python
class PrettyModelForm(ModelForm):
    class Meta:
        model = Number
        # 展示所有
        # fields = "__all__"
        # 展示列表中的字段
        fields = ["mobile", "price", "level", "status"]

def pretty_add(request):
    # 获取前端传入的值，并在modelform中限制好
    form = PrettyModelForm()
    print(form)
```