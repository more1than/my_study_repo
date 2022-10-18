```python
class StudentAPIView(APIView):
    def get(self, request):
        print(request)
        return Response({"msg": "OK"})

    def post(self, request):
        # 获取请求体中的数据
        data = request.data
        # 获取get中的数据
        get_info = request.query_params
```

data  获取请求体中的数据

query_params  获取get中的数据