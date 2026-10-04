# 02. Assembly Language / 汇编���言

## 1. What is assembly? / 1. 什么是汇编

English:
Assembly is a low-level language near the CPU instruction set. It is closer to machine behavior than high-level languages.

中文:
汇编是一种接近 CPU 指令集的低级语言，比 C、Java、Python 等高级语言更接近机器行为。

## 2. Why learn assembly? / 2. 为什么学习汇编

English:
Assembly helps explain registers, memory addressing, function calls, system calls, and how source code becomes machine instructions.

中文:
汇编有助于解释寄存器、内存寻址、函数调用、系统调用，以及高级代码如何变成机器指令。

## 3. Registers / 3. 寄存器

English:
Registers are CPU-internal fast storage. Common x86_64 registers include RAX, RBX, RCX, RDX, RSI, RDI, RSP, RBP, and RIP.

中文:
寄存器是 CPU 内部的高速存储器。常见的 x86_64 寄存器包括 RAX、RBX、RCX、RDX、RSI、RDI、RSP、RBP 和 RIP。

## 4. Common instruction sets / 4. 常见指令类别

English:
- MOV, LEA, PUSH, POP for data movement
- ADD, SUB, INC, DEC for arithmetic
- AND, OR, XOR, SHL, SHR for logic
- CMP, JMP, JE, JNE, JG, JL for branch logic
- CALL and RET for function calls

中文:
- MOV、LEA、PUSH、POP：用于数据搬运
- ADD、SUB、INC、DEC：用于算术运算
- AND、OR、XOR、SHL、SHR：用于逻辑运算
- CMP、JMP、JE、JNE、JG、JL：用于分支逻辑
- CALL 和 RET：用于函数调用

## 5. System calls / 5. 系统调用

English:
System calls let user code request privileged services from the kernel. The syscall number is in `rax`, arguments are passed in registers, and `syscall` triggers the switch.

中文:
系统调用允许用户代码请求内核提供特权服务。系统调用号放在 `rax`，参数放在寄存器中，`syscall` 触发用户态到内核态切换。

## 6. Example / 6. 示例

English:
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

中文:
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

## 7. Why assembly matters / 7. 为什么汇编对操作系统学习很重要

English:
Assembly shows function call mechanics, stack usage, register behavior, system call flow, and kernel entry points.

中文:
汇编能让你看到函数调用机制、栈的使用、寄存器行为、系统调用过程和内核入口点。

## 8. C to assembly / 8. C 到汇编

English:
A high-level compiler translates source code into assembly and then into machine code.

中文:
高级语言编译器会把源码翻译成汇编，再进一步翻译成机器码。

## 9. Stack frame / 9. 栈帧

English:
A function call usually saves the return address, allocates local storage, and restores state when returning.

中文:
函数调用通常会保存返回地址、为局部变量分配栈空间，并在返回时恢复状态。

## 10. Key idea / 10. 核心思想

English:
Assembly reveals the real machine behavior underneath all high-level programs.

中文:
汇编揭示了所有高级程序背后的真实机器行为。

## Learning checklist / 学习清单

English:
- understand registers
- understand jumps
- understand stack operations
- understand syscall conventions
- map C code to assembly

中文:
- 理解寄存器
- 理解跳转指令
- 理解栈操作
- 理解系统调用约定
- 能把 C 代码和汇编对应起来
