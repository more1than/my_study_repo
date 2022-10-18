### namedtuple数据类型

比普通的tuple更具有可读性和维护性，又比字典轻量级和高效

```python
from collections import namedtuple

people = namedtuple("people", "name,age,like")
zhanghao = people(name="zhanghao", age=22, like="xiba")
print(zhanghao)
```

可变：内存地址值可变

不可变：内存地址值改变

可变参数作为函数