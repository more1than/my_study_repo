## Ping通回环地址代表了什么

ping通本地回环地址并不能代表本地计算机网络是通的，即使拔掉网卡也是能ping通的

ping外部地址是经过真实网卡，向其他计算机发送数据包，而ping本地回环地址是使用本地的虚拟回环网卡

正常情况下，数据包数据包经过用户态进入内核态，内核态中的传输层网络层数据链路层，最后进入网卡的发送队列 Ring Buffer ，顺着网卡发送出数据，而ping本地回环地址时，其他流程依旧，只是到了最后未经过Ring Buffer ，而虚拟网卡会把数据推送到一个叫做input_pkt_queue的链表中，这个链表时所有网卡共享的，上面会挂着发送给本机的各种消息



127.0.0.1是一个回环地址，但不能说回环地址就是127.0.0.1，因为127.*，也就是127开头的ip均时回环地址

0.0.0.0 代表了网段内所有主机

localhost并不是一个ip，而是一个域名，localhost不一定必须关联127.0.0.1，而是默认会被指向这个地址

