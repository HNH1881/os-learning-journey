# 03. Boot and CPU Modes

## 1. Boot process

When a computer powers on, the CPU begins in a minimal state and the bootloader sets up the execution environment.

当计算机上电时，CPU 以一个极简状态启动，引导程序随后建立执行环境。

This usually includes BIOS/UEFI setup and loading the kernel from disk.

这通常包括 BIOS/UEFI 初始化以及从磁盘加载内核。

## 2. Real mode

Real mode is the original x86 mode with 16-bit execution and limited memory addressing.

实模式是 x86 最早的模式，运行在 16 位并且地址空间有限。

It lacks modern memory protection and paging.

它没有现代的内存保护和分页机制。

## 3. Boot sector

The boot sector is the first 512-byte sector executed after the BIOS loads it.

启动扇区是 BIOS 加载后首先执行的 512 字节区域。

It must end with the signature `0xAA55`.

它的最后必须包含 `0xAA55` 这个签名。

## 4. BIOS interrupt 0x10

BIOS interrupt 0x10 is commonly used to print text to the screen.

BIOS 中断 0x10 常用于在屏幕上输出文本。

This makes it possible to create the earliest possible display output in boot code.

这使得在启动代码中能实现最早的显示输出。

## 5. Protected mode

Protected mode introduces address protection, segmentation, and privilege checks.

保护模式引入地址保护、分段和特权检查。

It is the foundation of modern OS memory design.

它是现代操作系统内存设计的基础。

## 6. GDT

The Global Descriptor Table defines segment metadata such as base, limit, and access rights.

全局描述符表定义了段的基址、界限和访问权限等元数据。

It tells the CPU how to interpret memory segments.

它告诉 CPU 如何解释内存段。

## 7. Long mode

Long mode is the x86_64 execution mode with 64-bit registers and pointers.

长模式是 x86_64 的执行模式，拥有 64 位寄存器和指针。

This is the mode used by modern Linux kernels.

这是现代 Linux 内核所使用的模式。

## 8. Summary / 总结

Operating systems do not jump directly to a modern mode. They move step by step from a minimal boot environment into a protected, managed runtime.

操作系统不会直接跳到现代运行模式，而是从一个最小启动环境逐步过渡到受保护的管理运行环境。
