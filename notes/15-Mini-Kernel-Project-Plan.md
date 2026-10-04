# 15. Mini Kernel Project Plan

This is the practical project that ties together everything you have learned.
The goal is: build the smallest possible x86_64 kernel that can boot in QEMU and print output.

## Project goal

Create a minimal kernel that can:
- boot via a boot sector
- enter long mode
- set up paging
- print text to the screen
- call a C function from the kernel
- continue to a more advanced stage later

This project is intentionally small, but it touches all real OS concepts.

## Final target milestone

A barebones kernel that can say:

```text
Hello from mini kernel!
```

and then loop forever.

## Recommended project structure

```text
mini-kernel/
├── Makefile
├── src/
│   ├── boot.asm
│   ├── long_mode.asm
│   ├── paging.asm
│   ├── vga.c
│   ├── kernel.c
│   └── util.c
├── include/
│   └── vga.h
├── build/
│   └── output files
├── qemu.sh
└── README.md
```

## Milestone 1: Boot sector

### Goal
Load a minimal bootloader that prints a message in real mode.

### Tasks
- create a 512-byte boot sector
- use BIOS interrupt 0x10 to print text
- verify it boots in QEMU

### Files
- `src/boot.asm`

### Validation
- QEMU shows text output
- file is exactly 512 bytes + boot signature
- last two bytes are `0x55 0xAA`

### Learnings
- boot sector layout
- BIOS interrupts
- real mode execution

---

## Milestone 2: Build a long mode entry

### Goal
Transition from real mode to protected mode and then long mode.

### Tasks
- define a GDT
- enable protected mode
- enable PAE
- enable long mode via EFER
- jump to 64-bit kernel code

### Files
- `src/boot.asm`
- `src/long_mode.asm`

### Validation
- CPU reaches 64-bit code
- no immediate crash in QEMU

### Learnings
- CPU modes
- GDT structure
- EFER and CR0/CR4 configuration

---

## Milestone 3: Paging setup

### Goal
Set up identity mapping so virtual memory matches physical memory.

### Tasks
- allocate PML4, PDPT, PD tables
- map first 2MB or first 4MB region
- set CR3
- enable paging

### Files
- `src/paging.asm`

### Validation
- the kernel can execute after paging is enabled
- page tables are valid

### Learnings
- PML4/PDPT/PD/PT mapping
- page fault basics
- CR3 concept

---

## Milestone 4: VGA text output

### Goal
Print text to the screen without relying on BIOS interrupts.

### Tasks
- map VGA memory at known address
- write to text buffer
- implement `putchar` and `print_string`

### Files
- `src/vga.c`
- `include/vga.h`

### Validation
- text appears in QEMU display
- output is stable and controllable

### Learnings
- video memory abstraction
- direct hardware access in kernel mode
- text buffer writing

---

## Milestone 5: C kernel entry

### Goal
Transition from assembly startup to C kernel code.

### Tasks
- create a C `kernel_main()`
- call `print_string()` from C
- use a simple serial or VGA backend

### Files
- `src/kernel.c`

### Validation
- output appears from C code
- kernel is no longer pure assembly

### Learnings
- C kernel entrypoint
- linking assembly and C code
- how to call functions from kernel assembly

---

## Milestone 6: Serial output

### Goal
Add a serial port output path for easier debugging.

### Tasks
- implement serial port write function
- use `outb` and `inb` instructions
- print debug messages to serial output

### Files
- `src/serial.c`

### Validation
- QEMU logs show serial output
- debugging becomes easier than screen-only output

### Learnings
- I/O port access
- serial console debugging
- device driver mindset

---

## Milestone 7: Interrupts and keyboard input

### Goal
Learn how an OS handles interrupts and external events.

### Tasks
- install basic interrupt descriptor table (IDT)
- handle timer or keyboard interrupts
- print a message when key is pressed

### Files
- `src/idt.asm`
- `src/interrupts.c`

### Validation
- key press triggers interrupt handler
- output confirms keyboard event

### Learnings
- interrupts
- IDT
- hardware event handling

---

## Milestone 8: Basic memory manager

### Goal
Create a simple allocator or page frame tracker.

### Tasks
- track free pages
- allocate some pages for use
- print memory availability

### Files
- `src/memory.c`

### Validation
- allocator returns valid page ranges
- no crash when requesting memory

### Learnings
- physical memory tracking
- page allocation logic
- ownership of pages

---

## Milestone 9: Basic scheduler skeleton

### Goal
Create a minimal task model and scheduler stub.

### Tasks
- define task structs
- add a simple round-robin scheduler
- switch between tasks using context switching

### Files
- `src/scheduler.c`

### Validation
- scheduler can run multiple tasks conceptually
- context switch setup is in place

### Learnings
- scheduling
- process/task model
- context switching

---

## Milestone 10: Userspace skeleton

### Goal
Prepare for user mode and process isolation.

### Tasks
- create a user mode segment
- add a simple user stack model
- define a user program entrypoint

### Files
- `src/userspace.c`

### Validation
- user process model is conceptually workable
- kernel still runs correctly

### Learnings
- ring protection
- user mode vs kernel mode
- program execution model

---

## Suggested build flow

### 1. Start with boot sector only
Use the boot sector to print a message.

### 2. Add GDT and long mode
Transition to 64-bit mode.

### 3. Add paging
Enable virtual memory and identity mapping.

### 4. Add VGA output
Print to screen from C.

### 5. Add interrupts
Get keyboard and timer handling working.

### 6. Add a memory manager
Track pages and allocate memory.

### 7. Add task scheduling
Create a simple scheduler skeleton.

### 8. Think about user space
Prepare for process isolation and system calls.

---

## Makefile template

```makefile
CC = gcc
AS = nasm
QEMU = qemu-system-x86_64
CFLAGS = -m64 -ffreestanding -fno-pic -g -O2 -Wall -Wextra
ASFLAGS = -f elf64
LDFLAGS = -nostdlib -static

all: kernel.bin

boot.o: src/boot.asm
	$(AS) -f bin src/boot.asm -o build/boot.bin

long_mode.o: src/long_mode.asm
	$(AS) $(ASFLAGS) src/long_mode.asm -o build/long_mode.o

kernel.o: src/kernel.c
	$(CC) $(CFLAGS) -c src/kernel.c -o build/kernel.o

vga.o: src/vga.c
	$(CC) $(CFLAGS) -c src/vga.c -o build/vga.o

kernel.bin: build/boot.bin build/kernel.o build/vga.o build/long_mode.o
	ld -m elf_x86_64 -nostdlib -static -Ttext 0x100000 -o build/kernel build/long_mode.o build/kernel.o build/vga.o
	objcopy -O binary build/kernel build/kernel.bin

run: kernel.bin
	$(QEMU) -drive file=build/kernel.bin,format=raw -serial stdio

clean:
	rm -rf build/*
```

---

## QEMU launch command

```bash
qemu-system-x86_64 -drive file=build/kernel.bin,format=raw -serial stdio
```

For graphical output:

```bash
qemu-system-x86_64 -drive file=build/kernel.bin,format=raw
```

---

## Debugging commands

### Disassembly

```bash
objdump -d build/kernel
```

### GDB attach

```bash
qemu-system-x86_64 -drive file=build/kernel.bin,format=raw -s -S
```

Then in another terminal:

```bash
gdb build/kernel
(gdb) target remote :1234
(gdb) break kernel_main
(gdb) continue
```

---

## Challenges you will face

1. Bootloader size limit: 512 bytes
2. Mode transition complexity
3. Paging mistakes
4. VGA memory addressing
5. C/assembly linkage problems
6. Segmentation and GDT definitions
7. Interrupt table setup
8. Context switching complexity

These are normal. They are the real learning process.

---

## Project checkpoints

### Checkpoint 1: boot sector prints text
- [ ] boot sector works in QEMU
- [ ] message appears on screen

### Checkpoint 2: long mode reached
- [ ] protected mode enabled
- [ ] long mode enabled
- [ ] kernel code executes in 64-bit mode

### Checkpoint 3: page tables valid
- [ ] identity mapping set
- [ ] CR3 set
- [ ] paging enabled

### Checkpoint 4: C kernel runs
- [ ] C function prints output
- [ ] assembly and C work together

### Checkpoint 5: interrupts handled
- [ ] keyboard/timer interrupt triggers
- [ ] handler runs

### Checkpoint 6: scheduler skeleton exists
- [ ] task model defined
- [ ] switch logic drafted

---

## What this project teaches

By the time you finish this project, you will have touched the real foundations of modern operating systems:
- startup
- mode transitions
- paging
- memory management
- device output
- interrupt handling
- process/task model

In other words: you will have built a realistic mental model of how an OS starts and runs.

## Suggested next step after finishing the mini kernel

After the minimal kernel works, the next step is to add:
- basic keyboard input
- a simple shell
- a page frame allocator
- a memory map
- a basic scheduler
- a user space program loader

This is the path toward a more serious kernel project.

## Final advice

Do not try to build everything at once.
Do the milestones one by one.
Every milestone is a learning checkpoint.

The real goal is not just to get code working. The real goal is to understand why each piece exists.
