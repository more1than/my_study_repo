### gitignore

gitignore文件指定了那些文件无需被git版本管理

`vi .gitignore`

注意：该文件为隐藏文件

.gitignore需要与.git同级

#### 特例：

`test_dir/`

后面有/，代表文件夹下的文件均不接受管理，但该文件夹接受管理

假如文件夹和下属文件都不希望被管理，可以如下操作

`test_dir`

