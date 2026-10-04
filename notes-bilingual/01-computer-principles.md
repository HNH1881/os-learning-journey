# 01. Computer Principles / 计算机原理

## 1. What is a computer? / 1. 什么是计算机

English:
A computer is a machine that executes instructions on data. It takes input, processes it, and produces output.

中文:
计算机是一种对数据执行指令的机器。它接收输入、处理数据，并输出结果。

## 2. Major components / 2. 计算机的主要组成部分

English:
- CPU: executes instructions
- RAM: working memory
- disk: persistent storage
- bus: connects parts together
- I/O devices: keyboard, display, network, and more

中文:
- CPU：执行指令
- RAM：工作内存
- 磁盘：持久化存储
- 总线：连接各部件
- I/O 设备：键盘、显示器、网络等

## 3. Why binary? / 3. 为什么使用二进制

English:
Computers are electronic devices. Electrical states naturally map to 0 and 1, so binary is the most direct and stable representation.

中文:
计算机是电子设备，电平状态天然对应 0 和 1，所以二进制是最直接、最稳定的表示方式。

## 4. Number systems / 4. 数制

English:
Binary, decimal, octal, and hexadecimal are all used. Hexadecimal is especially common in systems programming because each hex digit is four bits.

中文:
二进制、十进制、八进制和十六进制都在计算机中使用。十六进制在系统编程中尤其常见，因为一个十六进制位等于四个二进制位。

## 5. Boolean logic / 5. 布尔逻辑

English:
Boolean logic is built on AND, OR, NOT, and XOR. It is the foundation of digital electronics and CPU arithmetic.

中文:
布尔逻辑建立在与、或、非和异或之上，是数字电子和 CPU 运算的基础。

## 6. CPU internals / 6. CPU 内部结构

English:
A CPU usually contains an ALU, a control unit, registers, and caches.

中文:
CPU 通常包含 ALU（算术逻辑单元）、控制单元、寄存器和缓存。

## 7. Fetch-decode-execute / 7. 取指令-解码-执行

English:
The CPU repeatedly fetches an instruction, decodes it, executes it, and updates its state.

中文:
CPU 会重复执行“取指令—解码—执行—更新状态”的循环。

## 8. Data representation / 8. 数据表示方式

English:
Integers are stored in binary, signed numbers often use two's complement, and floating-point numbers follow the IEEE 754 format.

中文:
整数以二进制存储，有符号整数通常使用补码，浮点数遵循 IEEE 754 格式。

## 9. Registers / 9. 寄存器

English:
Registers are tiny, fast storage inside the CPU used for active calculation and execution state.

中文:
寄存器是 CPU 内部的高速存储器，用于保存当前计算和执行状态。

## 10. Memory hierarchy / 10. 存储层次结构

English:
From fastest to slowest, memory is typically registers, cache, RAM, disk, and external storage.

中文:
从快到慢看，存储通常是寄存器、缓存、RAM、磁盘和外部存储。

## 11. Stack vs heap / 11. 栈和堆

English:
The stack is LIFO and is used for local variables and return addresses. The heap is used for dynamically allocated memory.

中文:
栈是后进先出结构，用于保存局部变量和返回地址；堆用于动态分配的内存。

## 12. Von Neumann architecture / 12. 冯·诺依曼结构

English:
The classic architecture stores both instructions and data in memory and executes them through one CPU.

中文:
经典的冯·诺依曼结构把指令和数据都存放在内存中，并由同一个 CPU 执行。

## 13. Why the OS matters / 13. 为什么需要操作系统

English:
The OS mediates between hardware and software by providing abstraction, scheduling, resource management, and protection.

中文:
操作系统在硬件和软件之间建立中介，提供抽象、调度、资源管理和保护。

## Summary / 总结

English:
The CPU executes instructions, memory stores data, and the OS gives those resources a safe and usable structure.

中文:
CPU 执行指令，内存存储数据，而操作系统让这些资源具有安全、统一和可管理的结构。
