import hashlib
import json

from django.conf import settings
from django.core.validators import RegexValidator
from django.forms import ModelForm, CharField, PasswordInput, Form, TextInput
from django.shortcuts import render, redirect
from rest_framework.views import APIView
from django.http import JsonResponse, HttpResponse
from django.core.exceptions import ValidationError
from app01 import models
from models import Student, Number, Admin
import logging
import time

logger = logging.getLogger(__name__)


def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


class UserInfoView(APIView):
    def __init__(self):
        super(UserInfoView, self).__init__()

    def get(self, request, *args, **kwargs):
        student_sex = request.POST.get("sex")
        student_info = Student.objects.filter(sex=student_sex).first()
        data = {
            "code": "200",
            "msg": student_info.name,
            "error": []
        }
        return JsonResponse(data)

    def delete(self, request, *args, **kwargs):
        student_info = Student.objects.filter(id=request.POST.get("id")).first()
        logger.info("{time}删除学生{name}信息".format(time=time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()),
                                                name=student_info.user))
        Student.objects.filter(id=request.POST.get("id")).delete()

        data = {
            "code": "200",
            "msg": "Delete Success",
            "error": []
        }
        return JsonResponse(data)

    def post(self, request, *args, **kwargs):
        input_number = request.POST.get("number")
        data = {
            "code": "200",
            "msg": fib(int(input_number)),
            "error": []
        }
        return JsonResponse(data)


def user_list(request):
    queryset = models.Student.objects.all()
    for obj in queryset:
        obj.get_gender_display()  # get_字段名称


class StudentModelForm(ModelForm):
    name = CharField(min_length=3, label="用户名")

    class Meta:
        model = Student
        fields = ["user", "gender", "owner_class"]

    def __init__(self, *args, **kwargs):
        super().__init__(self, *args, **kwargs)
        for name, field in self.fields.items():
            print(name, field)


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


def user_edit(request, id):
    # 传入数据库查询到的数据
    row_object = Student.objects.filter(id=id).first()
    form = StudentModelForm(instance=row_object)
    print(form)


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


def pretty_add(request):
    # 获取前端传入的值，并在modelform中限制好
    form = PrettyModelForm()
    print(form)


def pretty_list(request):
    # 等同于sql语句：select * from 表 order by level desc;
    # queryset = models.PrettyNum.objects.all().order_by("-level")
    queryset = Number.objects.all().order_by("level")
    return queryset


def pretty_edit(request, nid):
    # 根据id定位到数据
    row_object = Number.objects.filter(id=nid).first()
    if request.method == "GET":
        form = PrettyModelForm(instance=row_object)
        print(form)
    form = PrettyModelForm(data=request.POST, instance=row_object)
    if form.is_valid():
        form.save()
        print(form)


def find(request, nid):
    # 解包入参,联合查询
    data_dict = {"mobile": "18888888888", "id": "123"}
    Number.objects.filter(**data_dict)
    # 查询nid等于12
    Number.objects.filter(id=nid)
    Number.objects.filter(id__gt=nid)  # 大于nid
    Number.objects.filter(id__gte=nid)  # 大于等于nid
    Number.objects.filter(id__lt=nid)  # 小于nid
    Number.objects.filter(id__lte=nid)  # 小于等于nid
    # 根据字符串操作
    Number.objects.filter(mobile__startswith="1888")  # 以xxx开头
    Number.objects.filter(mobile__endswith="888")  # 以xxx结尾
    Number.objects.filter(mobile__contains="888")  # 包含xxxx


def number_list(request):
    data_dict = {}
    value = request.GET.get("id")
    if value:
        data_dict["mobile__contains"] = value
    res = Number.objects.filter(**data_dict)[0:10]
    print(res)


def get_page(request):
    page = int(request.GET.get('page', 1))
    page_size = 10
    start = (page - 1) * 10
    end = page * 10
    # 切片分页
    query = Number.objects.all()[start:end]
    print(query)

    # 获取符合条件的数据
    total_count = Number.objects.all().count()
    # divmod函数 返回(商，余数)， 如果有余数则商加一（向上取整）
    total_page_count, div = divmod(total_count, page_size)
    if div:
        total_page_count += 1


def admin_list(request):
    queryset = Admin.objects.all()
    context = {
        "queryset": queryset
    }
    return context


# 定义加密函数
def my_md5(data_string):
    obj = hashlib.md5(settings.SECRET_KEY.encode("utf-8"))
    obj.update(data_string.encode("utf-8"))
    return obj.hexdigest()


class AdminModelForm(ModelForm):
    # 隐藏输入确认密码
    confirm_password = CharField(label="确认密码", widget=PasswordInput)

    class Meta:
        model = models.Admin
        fields = ["username", "password", "confirm_password"]
        # 将密码隐藏输入
        widgets = {
            "password": PasswordInput
        }

    # 定义钩子方法
    def clean_confirm_password(self):
        # cleaned_data函数：验证通过之后所有的数据
        pwd = self.cleaned_data.get("password")
        confirm = my_md5(self.cleaned_data.get("confirm_password"))
        if pwd != confirm:
            raise ValidationError("密码不一致")
        return confirm

    def clean_password(self):
        pwd = self.cleaned_data.get("password")
        # 将加密后的密码入库
        return my_md5(pwd)


def admin_add(request):
    if request.method == "GET":
        form = AdminModelForm()
        return form
    form = AdminModelForm(data=request.POST)
    # is_valid校验表单数据
    if form.is_valid():
        form.save()


class LoginForm(Form):
    # required为True代表必填字段
    username = CharField(label="用户名", widget=TextInput, required=True)
    password = CharField(label="密码", widget=PasswordInput, required=True)

    def clean_password(self):
        password = self.cleaned_data.get("password")
        return my_md5(password)


def login(request):
    if request.method == "GET":
        form = LoginForm()
        print(form)
        return form
    form = LoginForm(data=request.POST)
    if form.is_valid():
        # 验证成功后获取到的用户信息
        print(form.cleaned_data)
        admin_object = Admin.objects.filter(**form.cleaned_data).first()
        if not admin_object:
            form.add_error("password", "用户名或密码错误")
        # 用户名密码正确
        # 网站生成随机字符串，写道用户浏览器cookie中，再写道session中
        request.session["info"] = admin_object.username


def admin_list_test(request):
    info = request.session.get("info")
    # 如果未登录，info获取不到信息，重定向到登陆页面
    if not info:
        return redirect("/login/")


def logout(request):
    """ 注销 """
    # 清除session
    request.session.clear()
    # 设置session60秒超时
    request.session.set_expiry(60)
    # 校验信息完毕后，修改超时时间，7天免登录
    request.session.set_expiry(60 * 60 * 24 * 7)
    # 重定向回登录页面
    return redirect("/login/")


class TaskModelForm:
    class Meta:
        model = models.Task
        fields = "__all__"


def task(request):
    data_dict = {"status": True, "data": [1, 2, 3]}
    # json_str = json.dumps(data_dict)
    # return HttpResponse(json_str)
    return JsonResponse(data_dict)


def upload_list(request):
    print(request.POST)  # 请求体中的数据
    print(request.FILES)  # 请求发过来的文件
    file_object = request.FILES.get("xxx")
    print(file_object.name)  # 输出文件名
    # 文件中的分段数据 chunks
    # 分段写入文件中
    f = open("a1.png", mode="wb")
    for chunk in file_object.chunks():
        f.write(chunk)
    f.close()


class UpModelForm(Form):
    class Meta:
        model = models.City
        fields = "__all__"


def upload_model_form(request):
    """ 上传文件和数据 """
    title = "上传文件"
    if request.method == "GET":
        form = UpModelForm()
        return render(request, "index.html")

    form = UpModelForm(data=request.POST, files=request.FILES)
    if form.is_valid():
        # 自动上传路径并写入到数据库
        form.save()
        return HttpResponse("成功")
