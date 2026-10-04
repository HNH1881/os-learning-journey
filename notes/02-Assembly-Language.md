# 02. 汇编语言

## 1. 什么是汇编

汇编是一种接近机器指令的低级语言，它比 C、Java、Python 这些高层语言更贴近 CPU。

## 2. 为什么要学汇编

因为汇编能帮助你理解：
- CPU 指令如何工作
- 内存如何访问
- 函数调用是怎么发生的
- 系统调用怎么触发
- 高层代码如何变成机器代码

## 3. 寄存器

寄存器是 CPU 内部的高速存储器。常见 x86_64 寄存器：
- RAX, RBX, RCX, RDX
- RSI, RDI
- RSP, RBP
- RIP
- R8-R15

关键点：
- 寄存器非常快
- 数量有限
- 运行时高度活跃

## 4. 常见指令类别

### 数据搬运
- MOV
- LEA
- PUSH
- POP

### 算术运算
- ADD
- SUB
- INC
- DEC
- IMUL

### 逻辑运算
- AND
- OR
- XOR
- NOT
- SHL
- SHR

### 比较和跳转
- CMP
- JMP
- JE
- JNE
- JG
- JL

### 函数调用
- CALL
- RET

## 5. 系统调用

系统调用让用户程序请求内核执行特权操作。Linux x86_64 下：
- `rax`：系统调用号
- `rdi`、`rsi`、`rdx`、`rcx`、`r8`、`r9`：参数
- `syscall`：触发用户态到内核态切换

例如：
- `write`
- `exit`
- `read`

## 6. 简单示例：Linux 汇编版 Hello World

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

## 7. 为什么汇编对操作系统学习很重要

汇编能让你看到：
- 函数调用真实方式
- 栈的使用方式
- 寄存器的工作方式
- 系统调用如何进入内核
- 内核入口点的本质

## 8. C 到汇编

C 编译器会把高级代码翻译成汇编，然后再编译成机器码。

例如：

```c
int add(int a, int b) {
    return a + b;
}
```

可能编译成：

```asm
add:
    mov eax, edi
    add eax, esi
    ret
```

## 9. 栈帧模型

函数调用通常会：
- 保存返回地址
- 为局部变量分配栈空间
- 使用基址指针和栈指针
- 返回时恢复执行状态

## 10. 核心思想

汇编揭示了所有高级代码背后的真实 CPU 行为。

## 学习清单

- [ ] 理解寄存器
- [ ] 理解跳转指令
- [ ] 理解栈操作
- [ ] 理解系统调用约定
- [ ] 能把 C 代码和汇编对应起来
