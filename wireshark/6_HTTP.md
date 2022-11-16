### HTTP

http是TCP的上层协议，基于TCP，所以过滤HTTP协议也会包含TCP的数据包

发送http数据包，方便抓取

```bash
curl -I baidu.com
```

客户端给服务器发送HEAD  HTTP请求

服务器回复客户端200 HTTP协议状态码