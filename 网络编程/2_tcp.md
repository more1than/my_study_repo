#### TCP

1.建立连接，2.发送数据，3.关闭连接

```python
def main():
    # 1.创建TCP套接字
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 2.连接服务器
    server_ip = input("请输入需要连接的服务器ip:")
    server_port = int(input("请输入需要连接的服务器port:"))
    server_addr = (server_ip, server_port)
    tcp_socket.connect(server_addr)  # 传入数据元组
    # 3.发送数据/接收数据
    send_data = input("请输入要发送的数据：")
    tcp_socket.send(send_data.encode("utf-8"))
    # 4.关闭套接字
    tcp_socket.close()


if __name__ == '__main__':
    main()
```

监听和发送关系

被动接收模型

```python
def main():
    # 1.创建TCP套接字
    tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 绑定本地
    tcp_server_socket.bind(("", 7890))
    # 将套接字转为被动接收数据
    tcp_server_socket.listen(128)
    # 监听套接字负责等待新的连接，accept创建的套接字用来为连接来的客户服务
    # 等待其他机器连接本地
    client_socket, client_addr = tcp_server_socket.accept()
    # 接收客户端发送的请求
    recv_data = client_socket.recv(1024)
    print(recv_data)
    # 回送一部分数据给客户端
    client_socket.send("copy that".encode("utf-8"))
    # 4.关闭套接字
    tcp_server_socket.close()
    client_socket.close()


if __name__ == '__main__':
    main()
```

循环等待多个客户端

```python
def main():
    # 1.创建TCP套接字
    tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 绑定本地
    tcp_server_socket.bind(("", 7890))
    # 将套接字转为被动接收数据
    tcp_server_socket.listen(128)
    # 监听套接字负责等待新的连接，accept创建的套接字用来为连接来的客户服务
    # 等待其他机器连接本地
    while True:
        client_socket, client_addr = tcp_server_socket.accept()
        # 接收客户端发送的请求
        recv_data = client_socket.recv(1024)
        print(recv_data)
        # 回送一部分数据给客户端
        client_socket.send("copy that".encode("utf-8"))
        # 4.关闭套接字
        tcp_server_socket.close()
    client_socket.close()
```



  