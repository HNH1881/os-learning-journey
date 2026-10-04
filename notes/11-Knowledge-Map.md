# 11. Knowledge Map

This file shows how the OS topics connect to each other.

## 1. Foundation layer

- binary logic
- CPU execution
- registers
- ALU
- memory hierarchy
- stack vs heap

## 2. Boot layer

- BIOS / UEFI
- bootloader
- boot sector
- real mode
- protected mode
- long mode
- GDT

## 3. Memory layer

- virtual memory
- paging
- page tables
- CR3
- page fault
- user space / kernel space

## 4. Process layer

- process vs program
- process lifecycle
- thread vs process
- context switch
- scheduler
- time slice

## 5. Concurrency layer

- race conditions
- mutexes
- semaphores
- condition variables
- deadlocks
- starvation

## 6. Resource abstraction layer

- system calls
- user mode / kernel mode
- fork
- exec
- IPC
- filesystem

## 7. Device layer

- device drivers
- interrupt handling
- DMA
- block devices
- character devices
- I/O scheduling

## 8. End-to-end mental model

The system looks like this:

```text
Program -> Assembly -> CPU -> Memory -> Page Tables -> Process
        -> System Call -> Kernel -> Device Driver -> Hardware
        -> File API -> Filesystem -> Storage
        -> IPC -> Other Processes
```

## 9. Key relationships

- Boot code creates the environment needed for OS execution.
- Paging enables process isolation and memory safety.
- System calls bridge user programs and kernel services.
- Processes and threads decide how work is scheduled.
- IPC and filesystem allow processes to cooperate and persist state.
- Device drivers and interrupt handling connect software to real hardware.

## 10. Long-term learning principle

Do not memorize isolated concepts. Always connect each concept to a lower-level mechanism and a higher-level purpose.

## 11. Example questions to test understanding

- How does a program become a process?
- How does the CPU know where the code is?
- Why does a user program not directly access device registers?
- Why is paging mandatory in modern OS design?
- Why is a filesystem needed if memory exists?
- How does an interrupt differ from a system call?
