配置pip

创建配置文件

```
C:\Users\zkf9676\AppData\Roaming\pip\pip.ini
```

```bash
[global]
index-url = http://pypi.douban.com/simple
proxy=http://zkf9676:zhang123.@proxy.h3c.com:8080
# proxy=http://proxy.h3c.com:8080
[install]
trusted-host = pypi.douban.com
```



```python
# 生成requirements.txt
pip freeze > requirements.txt
# 根据requirements.txt下载第三方库
pip3 install -r requirements.txt
```

