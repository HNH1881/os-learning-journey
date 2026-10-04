# 14. 环境搭建指南

## 前置条件

在开始实验前，确保你的环境具备：
- gcc
- nasm
- qemu-system-x86_64
- gdb
- objdump
- readelf

## Arch Linux

```bash
sudo pacman -S qemu nasm gcc gdb binutils
```

### 验证安装

```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
gdb --version
objdump --version
readelf --version
```

## Ubuntu / Debian

```bash
sudo apt-get update
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils
```

## macOS

```bash
brew install qemu nasm gcc gdb binutils
```

## 推荐目录结构

```text
~/os-experiments/
├── src/
├── build/
├── notes/
└── Makefile
```

## Makefile 模板

```makefile
.PHONY: all clean run debug

AS = nasm
CC = gcc
QEMU = qemu-system-x86_64

all: hello

hello: hello.o
	ld hello.o -o hello

hello.o: hello.asm
	nasm -f elf64 hello.asm -o hello.o

run: hello
	./hello

debug: hello
	gdb ./hello

clean:
	rm -f *.o hello
```

## QEMU 常用命令

### 运行引导镜像

```bash
qemu-system-x86_64 -drive format=raw,file=boot.bin
```

### 串口输出

```bash
qemu-system-x86_64 -drive file=boot.bin,format=raw -serial stdio
```

### 调试模式

```bash
qemu-system-x86_64 -drive file=boot.bin,format=raw -s -S
```

## GDB 常用命令

```bash
gdb program
(gdb) break main
(gdb) run
(gdb) info registers
(gdb) x/10x $rsp
(gdb) disassemble
(gdb) nexti
(gdb) continue
```

## objdump 与 readelf 常用命令

```bash
objdump -d program
readelf -h program
readelf -l program
readelf -s program
```

## strace 使用示例

```bash
strace ./program
strace -e trace=write ./program
```

## 常见问题

### QEMU 找不到

```bash
which qemu-system-x86_64
```

### NASM 语法错误

检查输出格式：
- `-f elf64`：Linux 64 位 ELF
- `-f bin`：原始引导扇区二进制

### 链接失败

确认 object 文件格式和链接器版本匹配。

### GDB 无法连接

确保 QEMU 是用 `-s -S` 启动的。

## 下一步

接着进入：
- [[12-QEMU+NASM+GCC实验清单]]
- [[15-mini-kernel项目计划]]
