#### JSON

json.dumps  将python序列化为json返回前端

```python
def task(request):
    data_dict = {"status": True, "data": [1, 2, 3]}
    json_str = json.dumps(data_dict)
    return HttpResponse(json_str)
```



利用django内置序列化方法JsonResponse

```python
def task(request):
    data_dict = {"status": True, "data": [1, 2, 3]}
    # json_str = json.dumps(data_dict)
    # return HttpResponse(json_str)
    return JsonResponse(data_dict)
```