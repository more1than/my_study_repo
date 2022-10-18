#### 多任务UDP通信

实现双线程同时进行收和发

```python
def rec_msg(udp_socket):
    # 接收数据并显示
    while True:
        recv_data = udp_socket.recvfrom(1024)
        print(recv_data)


def send_msg(udp_socket, dest_ip, dest_port):
    # 发送数据
    while True:
        send_data = input("请输入想要发送的数据：")
        udp_socket.sendto(send_data.encode("urf-8"), (dest_ip, dest_port))


def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.bind(("", 7890))
    dest_ip = input("请输入ip：")
    dest_port = int(input("请输入port："))
    # 创建两个线程去执行收发操作
    t_rec = threading.Thread(target=rec_msg, args=(udp_socket,))
    t_send = threading.Thread(target=send_msg, args=(udp_socket, dest_ip, dest_port))
    t_rec.start()
    t_send.start()


if __name__ == '__main__':
    main()
```

