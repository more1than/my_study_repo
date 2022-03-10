### 哑协议与智能协议

> 直观区别：哑协议传输进度不可见；智能协议传输进度可见
>
> 传输速度：智能协议比哑协议传输速度快

#### 哑协议备份举例

`git clone --bare /d/git_study/work_/.git ya.git`

回显：

`Cloning into bare repository 'ya.git'...
warning: You appear to have cloned an empty repository.
done.`

其中 bare表示不克隆工作区，第一个参数为被克隆文件 第二个参数为克隆文件期望地址

#### 智能协议备份举例

` git clone --bare file:///d/git_study/work_/.git zhineng.git`

回显：

` Cloning into bare repository 'zhineng.git'...
remote: Enumerating objects: 37, done.
remote: Counting objects: 100% (37/37), done.
remote: Compressing objects: 100% (28/28), done.
remote: Total 37 (delta 9), reused 0 (delta 0), pack-reused 0
Receiving objects: 100% (37/37), done.
Resolving deltas: 100% (9/9), done.`