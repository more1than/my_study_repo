#### 创建socket

```python
socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

其中socket.AF_INET标识ipv4

socket.SOCK_STREAM标识TCP协议

socket.SOCK_DGRAM标识UDP协议

```python
# 创建套接字对象
udp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 使用套接字发送数据
udp.sendto(b"hello", ("192.168.1.100", 8080))
# 从键盘获取字符串
data = input("请输入:")
udp.sendto(data.encode("utf-8"), ("192.168.1.100", 8080))
# 绑定固定端口号, 传入ip地址和端口号，ip一版不用写，表示所有ip都可以，端口需要指定
local_addr = ("", 7788)
udp.bind(loacl_addr)
# 等待接受对方发送的数据,1024表示接收数据的最大值
recv_data = udp.recvfrom(1024)
print(recv_data[0].decode("utf-8"))
# 关闭套接字
udp.close()
```

 socket套接字是全双工

 