### DHCP

DHCP使用C/S方式，在DHCP服务器进程，在客户主机上运行DHCP客户进程，DHCP使用UDP的方式传输数据，DHCP服务器使用的端口号是67，DHCP客户使用端口为68

客户端发送DHCP发现报文中封装事务ID和DHCP客户端的MAC地址，DHCP服务器发送DHCP OFFER给DHCP客户，DHCP客户发送DHCP REQUEST（请求）给DHCP服务器 

