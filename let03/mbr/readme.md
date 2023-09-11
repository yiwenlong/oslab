### Makefile中内容的解释
#### mbr.img: mbr.S
* 这行代码定义了一个 Makefile 规则。它告诉 make 命令，当 mbr.S 文件被修改时，需要执行下面的命令来生成 mbr.img 文件。
#### gcc -ggdb -c $<
* 这行命令使用 GCC 编译器来编译 mbr.S 汇编文件
* -ggdb 标志用于生成调试信息
* -c 标志表示只编译而不链接
* $< 是一个 make 命令的自动变量，表示当前目标的依赖项中的第一个文件，也就是 mbr.S
#### ld mbr.o -Ttext 0x7c00
* 这行命令使用链接器 ld 来将编译后的 mbr.o 目标文件链接成可执行文件。
* -Ttext 0x7c00 标志用于指定链接后的程序的起始地址为 0x7c00，这是 MBR 执行的标准加载地址。
#### objcopy -S -O binary -j .text a.out $@
* 这行命令使用 objcopy 工具将链接后的可执行文件 a.out 中的代码段（.text 段）提取出来，然后以二进制格式保存到 mbr.img 文件中。
* -S 标志表示去除符号表和重定位信息
* -O binary 表示输出为二进制文件
* -j .text 表示仅提取代码段，a.out 是输入文件
* $@ 表示目标文件，也就是 mbr.img

