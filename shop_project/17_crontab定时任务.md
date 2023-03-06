安装

```bash
pip install django-crontab
```

注册到app中

配置文件

```python
# 定时任务
CRONJOBS = [
    # 每5分钟执行一次生成主页静态文件
    ("*/5 * * * *", "contents.crons.generate_static_index_html", ">> 项目绝对路径/logs/crontab.log")
]
# 解决crontab中文问题
CRONTAB_COMMAND_PREFIX = "LANG_ALL=zh_cn.UTF-8"
```

```
基本格式：
* * * * *
分 时 日 月 周
55 16 * * *  # 每日的16：55执行
```

```python
# 添加定时任务到系统中
python manage.py crontab add
# 显示已经激活的定时任务
python manage.py crontab show
# 移除定时任务
python manage.py crontab remove
```

