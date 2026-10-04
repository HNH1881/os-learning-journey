# 12. QEMU + NASM + GCC 实验清单

这份清单帮你从零开始，用实际工具验证你学到的每个概念。

## 环境准备

### 安装工具

```bash
# Arch Linux
sudo pacman -S qemu nasm gcc gdb binutils

# Ubuntu / Debian
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils

# macOS (用 Homebrew)
brew install qemu nasm gcc gdb binutils
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

## 实验 1: 最小 Hello World 汇编程序

### 目标
- 写一个 x86_64 汇编程序
- 在 Linux 上直接运行
- 理解系统调用

### 步骤

1. 创建文件 `hello.asm`

```asm
section .data
    msg db "Hello, World!", 0x0a
    len equ $ - msg

section .text
    global _start

_start:
    mov rax, 1          ; write syscall
    mov rdi, 1          ; stdout
    lea rsi, [msg]
    mov rdx, len
    syscall

    mov rax, 60         ; exit syscall
    xor rdi, rdi        ; exit code 0
    syscall
```

2. 编译和链接

```bash
nasm -f elf64 hello.asm -o hello.o
ld hello.o -o hello
```

3. 运行

```bash
./hello
echo $?
```

4. 用 objdump 查看汇编

```bash
objdump -d hello
```

### 验证

- [ ] 程序输出 "Hello, World!"
- [ ] 退出码是 0
- [ ] objdump 能看到你写的指令

### 学到了什么

- syscall 的真实样子
- 寄存器用法
- 内存地址计算

---

## 实验 2: C 程序转汇编

### 目标
- 理解 C 怎样变成汇编
- 理解函数调用约定
- 理解栈

### 步骤

1. 创建 `simple.c`

```c
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);
    return result;
}
```

2. 编译成汇编

```bash
gcc -S simple.c -o simple.s
```

3. 查看生成的汇编

```bash
cat simple.s
```

4. 编译成目标文件并查看

```bash
gcc -c simple.c -o simple.o
objdump -d simple.o
```

5. 完整编译和运行

```bash
gcc simple.c -o simple
./simple
echo $?
```

### 验证

- [ ] simple.s 是可读的汇编
- [ ] objdump 输出中能看到 `add` 和 `main` 函数
- [ ] 程序返回 8（5+3）

### 学到了什么

- 高层 C 代码和汇编的对应关系
- 函数调用的真实样子
- 编译器优化

---

## 实验 3: 启动扇区和 QEMU

### 目标
- 写一个 real mode 启动扇区
- 在 QEMU 中运行
- 理解 BIOS 启动流程

### 步骤

1. 创建 `boot.asm`

```asm
[BITS 16]
[ORG 0x7C00]

start:
    mov ax, 0
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

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

2. 编译

```bash
nasm -f bin boot.asm -o boot.bin
```

3. 查看大小

```bash
ls -l boot.bin
hexdump -C boot.bin | tail
```

4. 在 QEMU 中运行

```bash
qemu-system-x86_64 -drive format=raw,file=boot.bin
```

### 验证

- [ ] boot.bin 大小正好 512 字节
- [ ] 最后两字节是 0x55 0xAA
- [ ] QEMU 显示 "Hello from bootloader!"
- [ ] 可以用 Ctrl+A X 退出 QEMU

### 学到了什么

- real mode 的感觉
- BIOS 中断的使用
- 启动流程的真实样子

---

## 实验 4: 从保护模式切换到 64 位

### 目标
- 理解从 real mode 到 protected mode 的过程
- 理解 GDT
- 理解长模式

### 步骤

这是一个较复杂的实验，需要多个文件。建议参考：
- OSDev wiki 上的 Bare Bones
- xv6 内核的启动代码
- 任何开源微内核的启动部分

### 验证

- [ ] 能进入保护模式
- [ ] 能进入 64 位模式
- [ ] 能输出字符

### 学到了什么

- CPU 模式切换
- 分段的作用
- 长模式的必要性

---

## 实验 5: 页表和虚拟地址

### 目标
- 理解页表
- 建立 identity mapping
- 理解 CR3

### 步骤

1. 建立最小页表（伪代码）

```c
// 分配 PML4 表
uint64_t pml4[512];

// 分配 PDPT 表
uint64_t pdpt[512];

// 分配 PD 表
uint64_t pd[512];

// 设置 PML4[0] -> PDPT
pml4[0] = (uint64_t)&pdpt | 0x3;

// 设置 PDPT[0] -> PD
pdpt[0] = (uint64_t)&pd | 0x3;

// 设置 PD[0] -> 2MB 页
pd[0] = 0x00000083;  // 2MB 页 + present + rw

// 设置 CR3
mov_to_cr3((uint64_t)&pml4);
```

2. 启用分页

```asm
mov rax, cr0
or rax, 0x80000000  ; 设置 PG 位
mov cr0, rax
```

### 验证

- [ ] 能进入分页模式
- [ ] 虚拟地址能正确映射
- [ ] 程序继续执行

### 学到了什么

- 页表的真实结构
- 地址翻译的过程
- 保护��隔离的基础

---

## 实验 6: 系统调用测试

### 目标
- 理解系统调用如何从用户态进入内核态
- 测试不同的系统调用
- 理解参数传递

### 步骤

1. 创建 `syscall_test.asm`

```asm
global test_write
global test_read

section .text

test_write:
    ; rdi = fd
    ; rsi = buffer
    ; rdx = count
    mov rax, 1
    syscall
    ret

test_read:
    ; rdi = fd
    ; rsi = buffer
    ; rdx = count
    mov rax, 0
    syscall
    ret
```

2. 创建 C 程序调用它

```c
#include <stdio.h>
#include <unistd.h>

extern long test_write(int fd, const char *buf, size_t count);
extern long test_read(int fd, char *buf, size_t count);

int main() {
    char msg[] = "Hello from syscall!\n";
    test_write(1, msg, sizeof(msg));
    return 0;
}
```

3. 编译和运行

```bash
nasm -f elf64 syscall_test.asm -o syscall_test.o
gcc syscall_test.o -c test_main.c -o test_main.o
gcc syscall_test.o test_main.o -o test_syscall
./test_syscall
```

### 验证

- [ ] 直接调用 write 系统调用成功
- [ ] 能看到输出
- [ ] strace 能看到系统调用

### 学到了什么

- 系统调用约定
- 用户态到内核态的边界
- 参数传递机制

---

## 实验 7: gdb 调试

### 目标
- 用 gdb 单步执行程序
- 理解栈和寄存器状态
- 跟踪函数调用

### 步骤

1. 用调试符号编译

```bash
gcc -g simple.c -o simple_debug
```

2. 启动 gdb

```bash
gdb simple_debug
```

3. 在 gdb 中

```
(gdb) break main
(gdb) run
(gdb) disassemble
(gdb) nexti
(gdb) info registers
(gdb) x/10x $rsp
(gdb) continue
(gdb) quit
```

### 验证

- [ ] 能在 main 处断点
- [ ] 能单步执行
- [ ] 能查看寄存器
- [ ] 能查看栈

### 学到了什么

- 调试工具的使用
- 运行时的真实状态
- 寄存器和内存的实际值

---

## 实验 8: objdump 和 readelf 分析

### 目标
- 理解可执行文件格式
- 理解符号表
- 理解节

### 步骤

1. 用 readelf 查看 ELF 结构

```bash
readelf -h simple_debug
readelf -l simple_debug
readelf -S simple_debug
readelf -s simple_debug
```

2. 用 objdump 查看细节

```bash
objdump -d simple_debug
objdump -t simple_debug
objdump -s simple_debug
```

3. 查看具体函数

```bash
objdump -d simple_debug | grep -A 20 "<main>:"
```

### 验证

- [ ] 能看到 ELF 头
- [ ] 能看到所有节
- [ ] 能看到符号表
- [ ] 能看到汇编代码

### 学到了什么

- 可执行文件的内部结构
- 符号的含义
- 节和段的区别

---

## 实验 9: 进程创建和 fork

### 目标
- 理解 fork 系统调用
- 理解父子进程
- 理解进程隔离

### 步骤

1. 创建 `fork_test.c`

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("Child process, PID: %d\n", getpid());
    } else {
        printf("Parent process, PID: %d, child PID: %d\n", getpid(), pid);
        wait(NULL);
    }
    
    return 0;
}
```

2. 编译和运行

```bash
gcc fork_test.c -o fork_test
./fork_test
```

3. 用 strace 跟踪

```bash
strace -e trace=fork,wait4,exit_group ./fork_test
```

### 验证

- [ ] 看到两个 PID
- [ ] 子进程输出和父进程输出都出现
- [ ] strace 显示 fork 调用

### 学到了什么

- fork 的真实行为
- 进程隔离
- 系统调用的实际应用

---

## 实验 10: 多线程和同步

### 目标
- 理解竞态条件
- 理解互斥锁
- 理解线程同步

### 步骤

1. 创建 `race.c` （无保护版）

```c
#include <pthread.h>
#include <stdio.h>

int counter = 0;

void* worker(void* arg) {
    for (int i = 0; i < 100000; i++) {
        counter++;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Counter: %d (expected 200000)\n", counter);
    return 0;
}
```

2. 编译和多次运行

```bash
gcc -pthread race.c -o race
for i in {1..5}; do ./race; done
```

3. 创建 `race_safe.c` （有互斥锁）

```c
#include <pthread.h>
#include <stdio.h>

int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Counter: %d (expected 200000)\n", counter);
    return 0;
}
```

4. 编译和运行

```bash
gcc -pthread race_safe.c -o race_safe
for i in {1..5}; do ./race_safe; done
```

### 验证

- [ ] race 的结果不总是 200000
- [ ] race_safe 的结果总是 200000
- [ ] 理解竞态条件的真实后果

### 学到了什么

- 竞态条件的真实表现
- 互斥锁的必要性
- 同步的重要性

---

## 实验 11: 文件系统和 inode

### 目标
- 理解文件和目录的关系
- 理解 inode
- 理解硬链接

### 步骤

1. 创建测试文件

```bash
echo "Hello" > testfile.txt
```

2. 查看 inode

```bash
ls -i testfile.txt
stat testfile.txt
```

3. 创建硬链接

```bash
ln testfile.txt testfile_link.txt
ls -i testfile.txt testfile_link.txt
```

4. 修改一个，看另一个

```bash
echo "Modified" >> testfile.txt
cat testfile_link.txt
```

5. 创建软链接

```bash
ln -s testfile.txt testfile_soft.txt
ls -l testfile_soft.txt
cat testfile_soft.txt
```

### 验证

- [ ] 硬链接有相同 inode
- [ ] 修改一个文件另一个也变
- [ ] 软链接是不同的 inode
- [ ] 软链接指向原文件

### 学到了什么

- inode 的实际意义
- 文件系统的设计
- 链接的工作原理

---

## 实验 12: IPC - 管道

### 目标
- 理解管道通信
- 理解进程间数据流

### 步骤

1. 创建 `pipe_test.c`

```c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child: write to pipe
        close(pipefd[0]);
        const char* msg = "Hello from child!";
        write(pipefd[1], msg, strlen(msg));
        close(pipefd[1]);
    } else {
        // Parent: read from pipe
        close(pipefd[1]);
        char buf[100];
        int n = read(pipefd[0], buf, sizeof(buf));
        printf("Received: ");
        write(1, buf, n);
        printf("\n");
        close(pipefd[0]);
        wait(NULL);
    }
    
    return 0;
}
```

2. 编译和运行

```bash
gcc pipe_test.c -o pipe_test
./pipe_test
```

3. Shell 管道示例

```bash
ls | grep .c
ps aux | grep bash
```

### 验证

- [ ] 子进程能给父进程发送数据
- [ ] 管道正确传输数据
- [ ] Shell 管道工作正常

### 学到了什么

- 管道是单向的
- 进程间通信的真实机制
- 后台工作的基础

---

## 实验 13: 中断和信号

### 目标
- 理解信号处理
- 理解异步事件

### 步骤

1. 创建 `signal_test.c`

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("\nCaught SIGINT!\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    
    printf("Press Ctrl+C to test signal handling...\n");
    
    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    
    return 0;
}
```

2. 编译和运行

```bash
gcc signal_test.c -o signal_test
./signal_test
```

3. 按 Ctrl+C 测试

### 验证

- [ ] 按 Ctrl+C 触发信号处理
- [ ] 程序继续运行而不是退出
- [ ] 理解信号的异步特性

### 学到了什么

- 信号的基本用法
- 异步事件处理
- 中断的高层抽象

---

## 实验 14: 完整的启动流程

### 目标
- 结合前面所有知识
- 创建一个最小内核
- 在 QEMU 上启动

### 步骤

这是一个大项目，需要：
1. 启动扇区代码
2. 进入保护模式
3. 进入 64 位模式
4. 设置页表
5. 输出字符

### 建议资源

- OSDev Bare Bones tutorial
- xv6 内核源码
- Writing an OS in Rust

### 验证

- [ ] 能在 QEMU 中启动
- [ ] 能输出信息
- [ ] 能进入 C 代码

### 学到了什么

- 整个启动流程
- 如何从汇编过渡到 C
- 内核的真实样子

---

## 实验进度跟踪

- [ ] 实验 1: Hello World 汇编
- [ ] 实验 2: C 到汇编
- [ ] 实验 3: 启动扇区
- [ ] 实验 4: 模式切换
- [ ] 实验 5: 页表
- [ ] 实验 6: 系统调用
- [ ] 实验 7: gdb 调试
- [ ] 实验 8: 文件格式分析
- [ ] 实验 9: 进程和 fork
- [ ] 实验 10: 多线程
- [ ] 实验 11: 文件系统
- [ ] 实验 12: 管道通信
- [ ] 实验 13: 信号处理
- [ ] 实验 14: 完整启动流程

---

## 学习建议

1. 按顺序做实验，不要跳过
2. 每个实验后复习笔记
3. 修改代码并看结果
4. 用 gdb 和 objdump 深入理解
5. 记录你的发现和困惑
6. 定期回顾和总结

---

## 常见问题

### Q: QEMU 怎样退出？
A: 按 Ctrl+A 然后按 X

### Q: objdump 输出太多怎么办？
A: 用 grep 过滤：`objdump -d prog | grep -A 20 "<function>:"`

### Q: gdb 怎样查看汇编？
A: `disassemble` 或 `disas /m`

### Q: 怎样追踪系统调用？
A: 用 `strace` 或 `ltrace`

### Q: 编译失败怎么办？
A: 先检查语法，再检查工具版本，最后看错误消息
