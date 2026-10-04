# 07. I/O与设备驱动

## 1. I/O basics

I/O means input and output. It includes keyboard input, screen output, disk access, and network traffic.

I/O 表示输入和输出，包括键盘输入、屏幕输出、磁盘访问和网络流量。

## 2. Device drivers

A driver is the OS's software interface to a particular hardware device.

驱动程序是操作系统与特定硬件设备之间的软件接口。

It translates kernel requests into device-specific operations.

它把内核请求翻译成设备特定的操作。

## 3. Interrupts

An interrupt is an asynchronous signal from hardware to the CPU.

中断是硬件向 CPU 发出的异步信号。

It tells the CPU that some event needs attention.

它通知 CPU 某个事件需要处理。

## 4. DMA

DMA allows devices to move data directly to or from memory without CPU copying byte by byte.

DMA 允许设备直接在内存和设备间搬运数据，不需要 CPU 一字节一字节复制。

## 5. Summary / 总结

Drivers, interrupts, DMA, and buffering are the core of OS device management.

驱动程序、中断、DMA 和缓冲区是操作系统设备管理的核心。
