INSTALLED_APPS中添加

```python
INSTALLED_APPS = [

    "ckeditor",  # 富文本编辑器
    "ckeditor_uploader",  # 富文本编辑器上传图片模块
    
]
```

settings中

```python
# 富文本编辑器ckeditor
CKEDITOR_CONFIGS = {
    "default": {
        "toolbar": "full",  # 工具条功能
        "height": 300,  # 编辑器高度
        # width: 300, # 编辑器宽度
    }
}

CKEDITOR_UPLOAD_PATH = ""  # 上传图片保存路径，使用了FastDFS,所以此处设为''
```

总路由中

```python
urlpatterns = [

    re_path(r"^ckeditor/", include("ckeditor_uploader,urls")),  # 富文本编辑器
    
]
```

model中添加富文本相关字段

```python
    desc_detail = RichTextUploadingField(default="", verbose_name="详情介绍")
    desc_pack = RichTextField(default="", verbose_name="包装信息")
    desc_service = RichTextUploadingField(default="", verbose_name="售后服务")
```

