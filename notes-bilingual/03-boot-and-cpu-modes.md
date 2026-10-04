# 03. Boot and CPU Modes / 启动与 CPU 模式

## 1. Boot process / 1. 启动流程

English:
When the machine powers on, the CPU begins in a minimal state. The system usually runs UEFI/BIOS, loads a bootloader, loads the kernel, and starts user space.

中文:
机器上电后，CPU 从一个非常有限的状态开始。通常过程是：BIOS/UEFI 初始化硬件、加载引导程序、加载内核，并进入用户空间。

## 2. Real mode / 2. 实模式

English:
Real mode is the original x86 mode. It uses 16-bit execution and direct segment:offset addressing with very limited protection.

中文:
实模式是 x86 最原始的工作模式，使用 16 位执行，并以 segment:offset 方式直接寻址，保护能力很弱。

## 3. Boot sector / 3. 启动扇区

English:
The boot sector is the first code executed after BIOS loads it. It usually prints a message or loads the next stage.

中文:
启动扇区是 BIOS 加载后 CPU 执行的第一段代码。它通常只做很少的工作，例如打印字符或加载下一阶段代码。

## 4. BIOS interrupt / 4. BIOS 中断

English:
`int 0x10` is a BIOS service for video output; using `AH = 0x0E` prints a character.

中文:
`int 0x10` 是 BIOS 提供的视频输出中断；通过 `AH = 0x0E` 可以输出一个���符。

## 5. Why `0xAA55`? / 5. 为什么是 `0xAA55`？

English:
The last two bytes of a boot sector are `0x55 0xAA`, which marks the sector as bootable.

中文:
启动扇区最后两字节是 `0x55 0xAA`，它表示该扇区是可引导扇区。

## 6. Protected mode / 6. 保护模式

English:
Protected mode introduces memory protection, segmentation, and privilege rules. It is the foundation of modern operating systems.

中文:
保护模式引入了内存保护、分段和特权规则，是现代操作系统的基础。

## 7. GDT / 7. GDT

English:
GDT stands for Global Descriptor Table. It defines segment base, size, access flags, and privilege levels.

中文:
GDT 是全局描述符表，用于定义段基址、段大小、访问权限和特权级别。

## 8. Why mode switching is necessary / 8. 为什么必须切换模式

English:
Real mode lacks memory protection, large address spaces, and proper privilege separation required by modern systems.

中文:
实模式缺少现代系统所需的内存保护、大地址空间和合理特权分离。

## 9. Long mode / 9. 长模式

English:
Long mode is the x86_64 execution mode, with 64-bit registers, 64-bit pointers, and modern paging support.

中文:
长模式是 x86_64 的执行模式，提供 64 位寄存器、64 位指针和更现代的分页支持。

## 10. Mode progression / 10. 模式转换顺序

English:
Modern systems often progress from real mode to protected mode and then to long mode.

中文:
现代系统通常从实模式进入保护模式，再进入长模式。

## Key idea / 核心思想

English:
The OS does not begin in full modern mode; it starts in a minimal hardware state and gradually reaches a safe runtime environment.

中文:
系统不会直接从现代内核模式开始，而是从最小的硬件状态逐步过渡到安全的运行环境。
