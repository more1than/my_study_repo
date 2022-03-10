### 暂存区回复成HEAD(清空暂存区的提交)

`git  reset HEAD -- <file>`

file为可选参数

### 暂存区与HEAD做比较

`git diff --cached`

若为空，则暂存区与HEAD一致

### 工作区的新变更想要替换为暂存区同步

`git checkout -- <filename>`
注意：--后是有空格然后在指定文件名称

### 查看现有分支

`git branch -av`

### 创建新分支并切换到新分支

`git checkout -b branch_name`

参数后接期望分支名称

#### 与远端链接

`git remote add origin https://github.com/more1than/my_study_repo.git`

`git remote add github git@github.com:more1than/my_study_repo.git`

注：其中origin和github均是代指，个人理解为类似变量赋值

#### 查看项目已链接的远程项目

`git remote -v`

