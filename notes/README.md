# OS Learning Notes

This folder is an Obsidian vault for learning computers and operating systems from the ground up.

## Vault overview

This vault is designed to help you study from the lowest level of computing upward:

- digital logic and binary
- CPU and registers
- machine instructions and assembly
- boot process and CPU modes
- memory and paging
- processes and threads
- IPC
- filesystem
- I/O and drivers
- operating system design patterns

## Suggested reading order

1. [[00-Index]]
2. [[01-Computer-Principles]]
3. [[02-Assembly-Language]]
4. [[03-Boot-and-CPU-Modes]]
5. [[04-Memory-and-Paging]]
6. [[05-Processes-and-Threads]]
7. [[06-IPC-and-Filesystem]]
8. [[07-I-O-and-Drivers]]
9. [[08-Study-Checklist]]
10. [[09-Note-Template]]
11. [[10-Weekly-Review]]
12. [[11-Knowledge-Map]]

## Recommended environment

- Arch Linux + Hyprland
- QEMU
- NASM
- GCC
- GDB
- objdump
- readelf
- vim / nvim

## Core idea

The OS sits between hardware and user programs. It abstracts complex hardware into useful interfaces and manages resources safely.

The learning path is:
- understand hardware
- understand CPU execution
- understand memory and boot process
- understand processes and synchronization
- understand filesystem and I/O
- then understand OS design as a whole

## Use in Obsidian

- Keep each note focused on one topic.
- Add backlinks to related topics.
- Add code examples where helpful.
- Add quick summary blocks at the end of each note.
- Use the review template after each study session.

## Questions to keep revisiting

- What is the CPU actually doing?
- What is the difference between a program and a process?
- Why are virtual addresses needed?
- Why does the kernel exist?
- How does booting work?
- Why does file access use inode and directory mapping?
- Why do interrupts and DMA matter?
