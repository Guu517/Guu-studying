#Git学习笔记

## 1. 创建版本库

首先，选择一个合适的地方创建一个空目录：

*Windows系统避免目录名含中文*

```
$ mkdir learngit
$ cd learngit
$ pwd
```

`pwd`命令用于显示当前目录

第二步，通过`git init`命令把这个目录变成Git可以管理的仓库：

```
$ git init
```

Git就把仓库建好了，而且告诉你是一个空的仓库（empty Git repository）

*Windows系统不要用记事本编辑文本，文件开头被添加字符*

### 1.1. 创建一个文件readme.txt

```
$ touch readme.txt (创建新文件)
$ vim readme.txt(编辑该文件)
```

在编辑页面输入i进入编辑状态

esc退出编辑状态，输入ZZ退出文件

` $ cat readme.txt (查看文件内容)`

### 1.2.文件提交到本地仓库

` $ git status (查看当前git状态)`

两次提交：add提交到暂存区stage/index（可多次使用），commit提交到本地版本仓库

```
$ git add readme.txt
$ git commit -m "wrote a readme file"
```

 `git commit`命令，`-m`后面输入的是本次提交的说明，可以输入任意内容

`git commit`命令执行成功后会告诉你，`1 file changed`：1个文件被改动（我们新添加的readme.txt文件）；`2 insertions`：插入了两行内容（readme.txt有两行内容）



## 2. 版本回退

```
$ vim readme.txt
$ git add readme.txt
$ git commit -m "append GPL"
```

`git log`命令查看历史记录

在Git中，用`HEAD`表示当前版本，也就是最新的提交`1094adb...`（注意版本号不一样），上一个版本就是`HEAD^`，上上一个版本就是`HEAD^^`

先要将`append GPL`版本回退到`wrote a readme file`版本

```
$ git reset --hard HEAD^
```

查看readme.txt内容

```
$ cat readme.txt
```

用`git log`再看看现在版本库的状态，最新的那个版本`append GPL`已经看不到了

当你用`$ git reset --hard HEAD^`回退到`wrote a readme file`版本时，再想恢复到`append GPL`，就必须找到`append GPL`的commit id。Git提供了一个命令`git reflog`用来记录你的每一次命令：

```
$ git reflog
```



## 3. 管理修改

第一次修改 -> `git add` -> 第二次修改 -> `git commit`

提交后，再看看状态`$ git status`，此时会发现第二次修改的内容没有被提交

用`git diff HEAD -- readme.txt`命令可以查看工作区和版本库里面最新版本的区别

怎么提交第二次修改呢？你可以继续`git add`再`git commit`，也可以`git add`第一次修改再`git add`第二次修改，最后`git commit`，就相当于把两次修改合并后一块提交了



## 4. 撤销修改

### 4.1. 撤回工作区的内容

假如你在工作区添加了错误信息，先`git status`查看一下状态

接着撤回操作

```
$ git restore readme.txt
$ cat readme.txt
```

该指令无法撤回已经添加到暂存区的内容

### 4.2. 撤回暂存区的内容

```
$ git restore --staged readme.txt (撤回暂存区的修改)
$ git restore readme.txt (撤回工作区的修改)
```

假设你不但改错了东西，还从暂存区提交到了版本库，怎么办呢？还记得版本回退吗？可以回退到上一个版本。不过，这是有条件的，就是你还没有把自己的本地版本库推送到远程。



## 5. 删除文件

先添加一个新文件`test.txt`到Git并且提交：

```
$ git add test.txt
$ git commit -m "add test.txt"
```

可手动删除文件`rm`后使用`add`和`commit`，或者用`rm`命令删了：

```
$ rm test.txt
```

Git知道你删除了文件，因此，工作区和版本库就不一致了，`git status`命令会立刻告诉你哪些文件被删除了

两种情况：

一是确实要从版本库中删除该文件，那就用命令`git rm`删掉，并且`git commit`：

```
$ git rm test.txt
$ git commit -m "remove test.txt"
```

现在，文件就从版本库中被删除了

二是删错了，因为版本库里还有呢，所以可以很轻松地把误删的文件恢复到最新版本：

```
$ git checkout -- test.txt
```

`git checkout`其实是用版本库里的版本替换工作区的版本

*从来没有被添加到版本库就被删除的文件，是无法恢复的！*

