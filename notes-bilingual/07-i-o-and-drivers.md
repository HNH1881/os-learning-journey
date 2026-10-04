# 07. I/O and Drivers / I/O 与设备驱动

## 1. I/O basics / 1. I/O 基础

English:
I/O is how the OS interacts with devices such as keyboards, displays, disks, audio, and network interfaces.

中文:
I/O 是操作系统与键盘、显示器、磁盘、音频和网络接口等设备交互的方式。

## 2. Device driver / 2. 设备驱动

English:
A device driver is the software layer that translates OS requests into device-specific commands.

中文:
设备驱动是软件层，用于将操作系统请求转换成设备特定的控制命令。

## 3. Block vs character / 3. 块设备与字符设备

English:
Block devices transfer data in fixed-size blocks; character devices transfer byte streams.

中文:
块设备按固定大小块传输数据；字符设备按字节流传输数据。

## 4. Interrupts / 4. 中断

English:
An interrupt is an asynchronous notification from hardware to the CPU, usually used for keyboard, timer, and disk events.

中文:
中断是硬件发给 CPU 的异步通知，常用于键盘、定时器和磁盘事件。

## 5. DMA / 5. DMA

English:
DMA allows devices to move data directly to and from memory without CPU copying every byte.

中文:
DMA 允许设备直接访问内存，不需要 CPU 逐字节复制数据。

## 6. Buffering and caching / 6. 缓冲区与缓存

English:
The OS uses buffers and caches to smooth the speed mismatch between the CPU, memory, and devices.

中文:
操作系统使用缓冲区和缓存来平滑 CPU、内存和设备之间的速度差异。

## 7. I/O scheduling / 7. I/O 调度

English:
When many I/O requests are queued, the OS may reorder them to improve throughput or reduce seek time.

中文:
当多个 I/O 请求排队时，操作系统可能会重排它们以提高吞吐量或减少寻道时间。

## Summary / 总结

English:
Drivers, interrupts, DMA, and buffering together allow the OS to manage hardware in a safe and efficient way.

中文:
设备驱动、中断、DMA 和缓冲区共同作用，使操作系统能够安全、高效地管理硬件。
