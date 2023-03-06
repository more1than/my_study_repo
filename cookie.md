### 基于单点登录

### cookie:

不能跨域共享，这样的话实现单点登录要麻烦很多

### token：

实现单点登录要简单很多，向服务器调用登录接口获取token，在header中的authorize字段加上token即可完成站点认证



### token缺点

token太长了，很有可能超出cookie的大小限制，token携带的信息越长，token就会越长，这样每次请求带上token对请求是一个不小的负担

token不安全，token存储在浏览器端，并且不会携带在cookie中，所以只能存储在local storage里，这会造成严重的安全问题，token一旦生成便无法让其失效，只能等到她过期

所以token更适合一次性的命令，设置一个较短的周期



