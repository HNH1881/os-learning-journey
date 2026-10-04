# 08. Study Checklist

## Core foundation

- [ ] Binary number system and hex
- [ ] Boolean logic and gates
- [ ] CPU structure and purpose
- [ ] Registers and instruction execution
- [ ] Memory hierarchy and cache
- [ ] Stack and heap

## Assembly and low-level execution

- [ ] x86_64 register basics
- [ ] MOV, ADD, CMP, JMP, CALL, RET
- [ ] Stack frame understanding
- [ ] Linux syscall convention
- [ ] writing a hello world in assembly
- [ ] running assembly in QEMU or on Linux

## Startup and boot

- [ ] BIOS / UEFI startup flow
- [ ] real mode
- [ ] boot sector layout
- [ ] 0x7C00 loading convention
- [ ] boot sector magic 0xAA55
- [ ] protected mode
- [ ] GDT basics
- [ ] long mode

## Memory and paging

- [ ] virtual memory
- [ ] page size and page tables
- [ ] PML4, PDPT, PD, PT
- [ ] CR3
- [ ] page fault
- [ ] identity mapping
- [ ] process isolation via paging

## Processes and threads

- [ ] process lifecycle
- [ ] thread vs process
- [ ] context switch
- [ ] scheduler basics
- [ ] time slice
- [ ] race condition
- [ ] mutex and semaphores

## OS abstractions

- [ ] fork
- [ ] exec
- [ ] system call flow
- [ ] user mode vs kernel mode
- [ ] IPC mechanisms
- [ ] filesystem and inode
- [ ] device drivers and interrupts
- [ ] DMA and I/O scheduling

## Practice goals

- [ ] Run a minimal boot sector in QEMU
- [ ] Compile a simple C program and inspect the assembly
- [ ] Understand a page table at a conceptual level
- [ ] Explain how a process is created and scheduled
- [ ] Explain how a filesystem maps names to inodes
- [ ] Describe how interrupts and DMA work in a simple device pipeline

## Final objective

By the end of the journey, you should be able to explain how a computer boots, how memory is virtualized, how processes run, and how the OS manages hardware resources safely and efficiently.
