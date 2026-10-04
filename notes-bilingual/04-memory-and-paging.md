# 04. Memory and Paging / 内存与分页

## 1. Why memory management matters / 1. 为什么内存管理很重要

English:
If user programs directly touch physical memory, they can overwrite each other or destroy kernel data. The OS introduces virtual memory and protection.

中文:
如果用户程序直接访问物理内存，它们可能覆盖彼此的内存，甚至破坏内核数据。因此操作系统引入虚拟内存和保护机制。

## 2. Virtual memory / 2. 虚拟内存

English:
Each process sees virtual addresses instead of physical ones. The OS maps those addresses via page tables.

中文:
每个进程看到的是虚拟地址，而不是直接使用物理地址。操作系统通过页表把虚拟地址映射到真实内存。

## 3. Paging / 3. 分页

English:
Paging divides memory into fixed-size pages, often 4 KB. It enables flexible management, safety, and virtual memory.

中文:
分页将内存划分为固定大小的页，常见页面大小为 4 KB。它使内存管理更灵活，也为虚拟内存和保护提供基础。

## 4. Page tables / 4. 页表

English:
x86_64 uses hierarchical paging: PML4, PDPT, PD, and PT.

中文:
x86_64 使用分层分页：PML4、PDPT、PD 和 PT。

## 5. Address translation / 5. 地址翻译

English:
A virtual address is split into indexes for page-table levels plus a page offset, and the CPU translates it into a physical address.

中文:
虚拟地址会被拆成多个页表索引和页内偏移，然后由 CPU 翻译成物理地址。

## 6. CR3 / 6. CR3

English:
`CR3` holds the physical address of the current page table and tells the CPU which address space is active.

中文:
`CR3` 保存当前页表的物理地址，告诉 CPU 当前使用哪个地址空间。

## 7. Page fault / 7. 缺页异常

English:
A page fault occurs when a page is not mapped, is invalid, or lacks permission. The kernel resolves it by allocating or loading a page.

中文:
缺页异常发生在页未映射、非法访问或无权限访问时。内核会通过分配或加载页面来处理它。

## 8. Identity mapping / 8. 恒等映射

English:
Early boot code often uses identity mapping, where virtual and physical addresses are equal, to simplify initialization.

中文:
早期启动代码常使用恒等映射，即虚拟地址等于物理地址，以简化初始化过程。

## 9. Why paging is critical / 9. 为什么分页至关重要

English:
Paging enables memory isolation, virtual address spaces, permission control, and page-fault handling.

中文:
分页使得内存隔离、虚拟地址空间、权限控制和缺页处理成为可能。

## Summary / 总结

English:
Paging is the mechanism that turns virtual memory into a safe and manageable abstraction over physical memory.

中文:
分页机制把虚拟内存变成安全且可管理的物理内存抽象。
