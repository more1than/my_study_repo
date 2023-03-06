#### getattr魔法方法

当获取不存在的属性时，会抛出异常提示错误，而异常就是__getattr__魔法方法抛出的

下述代码并没有报错，而是返回期望值 not found

```
class A:
    def __init__(self, value):
        self.value = value

    def __getattr__(self, item):
        print("into getattr")
        return "not found"

a = A(10)
print(a.value)
# 10
print(a.name)
# into getattr
# not found
```

#### setattr魔法方法

当设置一个属性的设置值时，会调用到这个魔法方法，每个设置值的方式都会进入这个方法

```python
class A:
    def __init__(self, value):
        self.value = value

    def __getattr__(self, item):
        print("into getattr")
        return "not found"

    def __setattr__(self, key, value):
        print("into setattr")
        if value == 10:
            print("from init")
        object.__setattr__(self, key, value)

a = A(10)
```

#### getattr函数

获取当前对象的某个属性

```python
getattr(a, "value")
```

#### setattr函数

设置当前对象的某个属性

```python
setattr(a, "value", 11)
```