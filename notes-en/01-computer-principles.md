# 01. Computer Principles

## 1. What is a computer?

A computer is a machine that executes instructions on data. It takes input, processes it, and produces output.

计算机是一种对数据执行指令的机器。它接收输入，处理数据，并输出结果。

## 2. Major components

The main parts are the CPU, memory, storage, bus, and I/O devices.

主要部件包括 CPU、内存、存储器、总线和 I/O 设备。

- CPU: executes instructions. / CPU：执行指令。
- RAM: temporary working memory. / RAM：临时工作内存。
- Disk: persistent storage. / 磁盘：持久化存储。
- Bus: carries data and control signals. / 总线：传输数据和控制信号。
- I/O devices: keyboard, display, network, etc. / I/O 设备：键盘、显示器、网络等。

## 3. Why binary?

Because electrical signals are naturally two-state: high or low voltage.

因为电信号天然是双状态的：高电平或低电平。

This makes binary a natural way to represent information.

因此二进制成为自然的信息表示方式。

## 4. Number systems

Binary, octal, decimal, and hexadecimal are common.

二进制、八进制、十进制和十六进制都很常见。

Hex is especially useful because one hex digit represents four bits.

十六进制特别有用，因为一个十六进制位等于四个二进制位。

## 5. Boolean logic

Boolean algebra gives us logic gates such as AND, OR, NOT, and XOR.

布尔代数提供了与、或、非、异或等逻辑门。

These gates are the building blocks of digital circuits.

这些门电路是数字电路的基础构件。

## 6. CPU internals

A CPU usually contains the ALU, the control unit, registers, and cache.

CPU 通常包括 ALU、控制单元、寄存器和缓存。

The ALU performs arithmetic and logical operations.

ALU 负责算术和逻辑运算。

The control unit tells the CPU what to do next.

控制单元决定 CPU 下一步执行什么。

## 7. Fetch-decode-execute

The processor repeats a loop: fetch, decode, execute, update state.

处理器重复执行这四步：取指、译码、执行、更新状态。

This is the basic repeated cycle of all CPU work.

这是所有 CPU 工作的基本循环。

## 8. Data representation

Integers are stored in binary, and signed values often use two's complement.

整数以二进制方式存储，有符号整数通常使用补码。

Floating-point values follow IEEE 754 standards.

浮点数遵循 IEEE 754 标准。

## 9. Registers

Registers are fast storage inside the CPU.

寄存器是 CPU 内部的高速存储器。

They hold data currently being processed.

它们保存当前正在处理的数据。

## 10. Memory hierarchy

Memory is arranged from fastest to slowest: registers, cache, RAM, disk, storage network.

存储器按速度从快到慢排列为：寄存器、缓存、RAM、磁盘、网络存储。

Speed increases cost, so the design is a tradeoff.

速度越快，成本越高，因此需要做取舍。

## 11. Stack vs heap

The stack is LIFO and used for function calls and local variables.

栈是后进先出结构，用于函数调用和局部变量。

The heap is for dynamically allocated objects and grows more slowly.

堆用于动态分配对象，容量更大但管理更复杂。

## 12. Von Neumann architecture

The classic model stores both instructions and data in memory.

冯·诺依曼架构将指令和数据都存放在内存中。

This is what makes computers programmable.

这使计算机能够执行可编程任务。

## 13. Why do we need an OS?

We need an operating system to manage hardware and provide safe abstractions.

我们需要操作系统来管理硬件，并提供安全、统一的抽象。

It handles scheduling, memory protection, I/O, and process isolation.

它负责调度、内存保护、I/O 和进程隔离。

## Summary / 总结

The CPU executes instructions, memory stores information, and the OS coordinates the system.

CPU 执行指令，内存存储信息，而操作系统协调整个系统。
