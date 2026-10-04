# 12. QEMU + NASM + GCC 实验清单

这份清单帮助你用真实工具验证学到的每个概念。

## 环境准备

### 安装工具

```bash
# Arch Linux
sudo pacman -S qemu nasm gcc gdb binutils

# Ubuntu / Debian
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils
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

## 实验 1：最小 Hello World 汇编程序

### 目标
- 编写一个 x86_64 汇编程序
- 在 Linux 上运行
- 理解系统调用

### 示例代码

```asm
section .data
    msg db "Hello, World!", 0x0a
    len equ $ - msg

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    lea rsi, [msg]
    mov rdx, len
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
```

### 编译

```bash
nasm -f elf64 hello.asm -o hello.o
ld hello.o -o hello
./hello
```

### 你要验证

- [ ] 输出 "Hello, World!"
- [ ] 退出码为 0
- [ ] 可以用 objdump 看反汇编

---

## 实验 2：C 程序转汇编

### 目标
- 理解 C 如何编译成汇编
- 理解函数调用和栈

```c
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);
    return result;
}
```

### 编译

```bash
gcc -S simple.c -o simple.s
cat simple.s
```

### 验证

- [ ] 能看到函数生成的汇编
- [ ] 能理解参数传递和返回值

---

## 实验 3：启动扇区与 QEMU

### 目标
- 运行一个最小引导扇区
- 理解 BIOS 启动逻辑

### 示例代码

```asm
[BITS 16]
[ORG 0x7C00]

start:
    mov si, msg
    call print_string
    jmp $

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp print_string
.done:
    ret

msg db "Hello from bootloader!", 0x0D, 0x0A, 0

times 510-($-$$) db 0
dw 0xAA55
```

### 编译和运行

```bash
nasm -f bin boot.asm -o boot.bin
qemu-system-x86_64 -drive format=raw,file=boot.bin
```

### 验证

- [ ] 文件大小 512 字节
- [ ] 最后两个字节为 0x55 0xAA
- [ ] QEMU 输出字符串

---

## 实验 4：保护模式和长模式

### 目标
- 理解从实模式到保护模式
- 理解 GDT 和长模式

### 验证

- [ ] 进入保护模式
- [ ] 进入长模式
- [ ] 能输出字符

---

## 实验 5：页表和虚拟地址

### 目标
- 理解分页
- 理解页表和 CR3

### 示例伪代码

```c
pml4[0] = (uint64_t)&pdpt | 0x3;
pdpt[0] = (uint64_t)&pd | 0x3;
pd[0] = 0x00000083;
```

### 验证

- [ ] 能配置页表
- [ ] 能开启分页
- [ ] 理解地址翻译

---

## 实验 6：系统调用测试

### 目标
- 观察 syscall 进入内核态的过程

### 重点

- `rax` 保存 syscall number
- `rdi` `rsi` `rdx` 保存参数
- `syscall` 真正触发内核服务

---

## 实验 7：gdb 调试

### 目标
- 查看寄存器
- 看栈
- 单步执行

### 示例命令

```bash
gdb simple_debug
(gdb) break main
(gdb) run
(gdb) info registers
(gdb) x/10x $rsp
(gdb) nexti
```

---

## 实验 8：objdump 与 readelf

### 目标
- 理解 ELF 文件结构
- 看符号和节

```bash
readelf -h simple_debug
objdump -d simple_debug
```

---

## 实验 9：fork 与进程创建

### 目标
- 理解进程复制
- 理解父子进程的不同返回值

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("child\n");
    } else {
        printf("parent, child=%d\n", pid);
    }
    return 0;
}
```

---

## 实验 10：多线程与竞态条件

### 目标
- 观察线程共享内存的问题
- 理解 mutex 的必要性

### 关键观测

- 无锁版本结果不稳定
- 加锁后结果稳定

---

## 实验 11：文件系统与 inode

### 目标
- 理解目录、文件和 inode 的关系

### 关键命令

```bash
ls -i file.txt
stat file.txt
ln file.txt hardlink
ln -s file.txt softlink
```

---

## 实验 12：IPC 管道

### 目标
- 理解 pipe 的单向通信模型

### 示例

```bash
ls | grep .c
```

---

## 实验 13：信号处理

### 目标
- 理解异步事件通知

### 示例

```c
signal(SIGINT, handler);
```

---

## 实验 14：完整最小内核

### 目标
- 把前面的所有知识串起来
- 在 QEMU 中启动最小内核

### 关键点

- boot sector
- long mode
- paging
- VGA 输出
- C kernel

## 实验进度跟踪

- [ ] 实验 1：Hello World 汇编
- [ ] 实验 2：C 到汇编
- [ ] 实验 3：启动扇区
- [ ] 实验 4：保护模式/长模式
- [ ] 实验 5：页表
- [ ] 实验 6：系统调用
- [ ] 实验 7：GDB 调试
- [ ] 实验 8：ELF 分析
- [ ] 实验 9：fork
- [ ] 实验 10：线程和锁
- [ ] 实验 11：文件系统
- [ ] 实验 12：IPC
- [ ] 实验 13：信号
- [ ] 实验 14：最小内核
