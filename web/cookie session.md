### Http

> http是无状态的，即访问服务器后关闭网页，再次访问服务器，服务器是意识不到再次访问的操作的

### Cookie

浏览器发送http请求到服务器，服务器进行Set-Cookie设置，其中包含Name和Value两个重要的属性，浏览器收到后会保存起来，此后发送的每次请求都会自动附带上Cookie,也就是说Cookie就是存储在浏览器中的数据。用户名和密码放在Cookie相对不安全，便有了Session(会话)

### Session

浏览器访问服务器是会话的开始

浏览器将用户名密码发送给服务器请求登录，服务器验证成功后进行Set-Cookie设置，包含SessionID和会话结束的时间，将该Cookie返回给浏览器，如果该Cookie被黑客获取到并篡改了里面的SessionID也没有太大的意义，因为签名的存在，SessionID被修改服务器就没法识别该ID，该ID就失去了意义，浏览器以后每次请求服务器也是会自动附带Cookie，在Cookie失效后，用户就需要重新输入用户名密码了

### Token

用户登录网页后请求到服务器后，服务器生成一个JWT，并将JWT签名的密文保存到数据库（JWT无需入库），并将JWT返回给浏览器，浏览器以**Cookie或Storage**的形式进行存储，后续的每次请求都可以自动携带JWT给到服务器，用户无需输入密码，与Session类似

JWT:

header：使用什么算法来生成签名

payload：有效期之类的数据

signature：签名