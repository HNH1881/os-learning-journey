# 15. Mini Kernel Project Plan / mini-kernel 项目计划

## Goal / 目标

English:
Build a minimal x86_64 kernel that can boot in QEMU, enter long mode, set up paging, and print text.

中文:
构建一个最小 x86_64 内核，能在 QEMU 中启动，进入长模式，设置分页，并输出文本。

## Milestones / 里程碑

English:
1. boot sector output
2. long mode entry
3. paging
4. VGA text output
5. C kernel entry
6. interrupts
7. memory manager
8. scheduler

中文:
1. 启动扇区输出
2. 进入长模式
3. 分页
4. VGA 文本输出
5. C 内核入口
6. 中断
7. 内存管理器
8. 调度器

## Recommended order / 推荐顺序

English:
Start with a boot sector, then long mode, then paging, then output, then C integration, then interrupts.

中文:
先从启动扇区开始，再进入长模式，然后分页，再输出，接着集成 C 代码，最后处理中断。

## Final thinking / 终极思路

English:
A kernel project is not about finishing a full OS immediately; it is about learning the real building blocks of an operating system one layer at a time.

中文:
内核项目不是为了立刻做出完整操作系统，而是一步一步理解操作系统真正的构建模块。
