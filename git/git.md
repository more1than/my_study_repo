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

