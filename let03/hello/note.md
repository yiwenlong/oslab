#### 注意点
* 需要首先设置 AM_HOME 环境变量，abstract_machine 项目中的 abstract_machine 子目录
* ubuntu 系统可能缺少 `bits/libc-header-start.h` 头文件，可以执行 `sudo apt install gcc-multilib` 安装相关的依赖

#### 相关的命令
``` shell
# make 只打印需要执行的命令，但是不执行
# -n选项告诉 make 不要真正执行命令，而是只显示将要执行的命令，以供预览
# -B选项用于强制重新构建所有目标
make -nB

# -A选项告诉vim在启动时进入附加（read-only）模式，以便查看输出而不进行编辑
make -nB | vim -A

# vim 设置不换换行命令
:set nowrap

make -nB \
  | grep -ve '^\(\#\|echo\mkdir\|make\)' \
  | sed "s#$AM_HOME#\$AM_HOME#\g"
  | vim -

# vim 命令
# %：这表示命令将在整个文档范围内执行，而不仅仅是当前行
# s/ /\r /g：这是替换命令的格式
#   在这个模式下，s 表示替换操作
#   第一个斜杠 / 后面的空格 是要查找的模式
#   第二个斜杠 / 后面的 \r 是要替换的内容
#   最后的 g 表示全局替换，即替换所有匹配项而不仅仅是第一个
:%s/ /\r /g

# vim 命令，no highlight 的缩写，它的作用是取消当前搜索高亮显示
:nohl
```
