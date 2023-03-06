## ‘任务追踪管理



项目使用本地配置

setting同目录下创建local_settings文件夹

在local_settings文件中，仅需写入需要修改覆盖的配置字段

```python
try:
    from .local_settings import *
except ImportError:
    pass
```



安装虚拟环境配置，让每个项目都使用一个独立的虚拟环境，隔离环境减少影响

```bash
pip install virtualenv
```



配置pip全局

```bash
C:\Users\zkf9676\AppData\Roaming\pip

[global]
proxy=http://zkf9676:h3c@123.@proxy.h3c.com:8080
index-url = https://pypi.tuna.tsinghua.edu.cn/simple
[install]
trusted-host = https://pypi.tuna.tsinghua.edu.cn 
```



创建一个虚拟环境文件夹，把所有虚拟环境都放在文件夹下

```shell
mkdir py_venv
cd py_venv
virtualenv my_project_venv
```

```
cd 到虚拟环境中的Scripts目录中，activate激活虚拟环境， deactivate 退出虚拟环境
```



忽略部分文件，创建,gitignore文件

```bash
# Django stuff:
local_settings.py
*.sqlite3

# database migrations
*/migrations/*.py
!*/migrations/__init__.py

__pycache__/
*py[cod]
*$py.class
```



```bash
 # 给某个仓库起别名绑定origin名称
 git remote add origin https://gitee.com/zh270193053/task_manage.git
 
 git push origin master 
```



项目附带requirements.txt

```
pip freeze > requirements.txt
# 下载文件中的库
pip install -r requirements.txt
```



发送短信报错

```python
import ssl
ssl._create_default_https_context = ssl._create_unverified_context
```



发短信示例

```python
import random
from django.http import HttpResponse

from task_manage import settings


def send_sms(request, phone):
    """
    发送短信
    """
    tpl = request.GET.get("tpl")
    template_id = settings.TENCENT_SMS_TEMPLATE.get(tpl)
    if not template_id:
        return HttpResponse("模板不存在")

    code = random.randrange(1000, 9999)
    res = send_sms_single(phone, template_id, [code, ])
    if res["result"] == 0:
        return HttpResponse("成功")
    else:
        return HttpResponse(res['errmsg'])

	
```

