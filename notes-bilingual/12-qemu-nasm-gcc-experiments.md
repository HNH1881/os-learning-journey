# 12. QEMU + NASM + GCC Experiments / QEMU + NASM + GCC 实验清单

## 1. Environment setup / 1. 环境准备

English:
Install `qemu`, `nasm`, `gcc`, `gdb`, `binutils` and validate the commands.

中文:
安装 `qemu`、`nasm`、`gcc`、`gdb` 和 `binutils`，并验证命令可用。

## 2. Hello World in assembly / 2. 汇编版 Hello World

English:
Use a minimal Linux assembly program to understand syscalls and output behavior.

中文:
编写最小 Linux 汇编程序，理解系统调用和输出行为。

## 3. C to assembly / 3. C 到汇编

English:
Compile a small C function and inspect the generated assembly to see the CPU-level representation of source code.

中文:
编译一个小的 C 函数，并检查生成的汇编，看到源码在 CPU 层面的表示方式。

## 4. Boot sector in QEMU / 4. QEMU 中的启动扇区

English:
Write a 512-byte boot sector and test it inside QEMU to observe BIOS boot behavior.

中文:
编写 512 字节启动扇区，并在 QEMU 中测试，观察 BIOS 启动行为。

## 5. Paging experiment / 5. 分页实验

English:
Build a small page-table model and understand translation from virtual to physical addresses.

中文:
构造一个小型页表模型，理解从虚拟地址到物理地址的转换。

## 6. GDB and ELF inspection / 6. GDB 与 ELF 检查

English:
Use `gdb`, `objdump`, and `readelf` to view registers, stack frames, and ELF layout.

中文:
使用 `gdb`、`objdump` 和 `readelf` 查看寄存器、栈帧和 ELF 结构。

## 7. fork / 7. fork

English:
Explore process creation, parent/child behavior, and the relationship between process state and execution.

中文:
探索进程创建、父子进程行为，以及进程状态和执行关系。

## 8. Multi-threading / 8. 多线程

English:
Study race conditions and the reason mutexes exist.

中文:
研究竞态条件，以及互斥锁存在的意义。

## 9. Filesystem and inode / 9. 文件系统与 inode

English:
Observe how names map to files and how inode metadata describes the file object.

中文:
观察文件名如何映射到文件，以及 inode 元数据如何描述文件对象。

## 10. IPC with pipe / 10. 使用管道进行 IPC

English:
Use a shell pipeline to witness one-way process communication.

中文:
使用 shell 管道来观察单向进程通信。

## Final goal / 最终目标

English:
The lab sequence should help you connect theory with real execution, including boot, paging, process creation, and debugging.

中文:
实验序列旨在把理论与真实执行连接起来，包括启动、分页、进程创建和调试。
