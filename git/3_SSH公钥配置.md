## SSH公钥配置

设置本机绑定SSH公钥，实现免密码登录，不然每次推送代码到远程仓库时，每次都要输入密码



生成公钥

```bash
# -t 指定加密算法
ssh-keygen -t rsa
```

将后缀名pub的公钥内容复制到git远程仓库中

