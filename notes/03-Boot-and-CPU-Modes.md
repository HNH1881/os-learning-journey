# 03. Boot and CPU Modes

## 1. Boot process

When the machine powers on, the CPU begins in a very minimal state.
The startup flow is usually:

1. BIOS or UEFI initializes hardware
2. bootloader is loaded
3. kernel is loaded from disk
4. kernel sets up system state
5. user space starts

## 2. Real mode

Real mode is the original x86 mode.
It has:
- 16-bit execution
- very limited memory space
- no real memory protection
- direct segment:offset addressing

The boot sector is normally loaded to `0x7C00`.

## 3. Why boot sector matters

The boot sector is the first code the CPU runs after the BIOS loads it.
It is tiny and often just enough to:
- print something
- load more code
- jump into the next stage

Example boot sector:
```asm
[BITS 16]
[ORG 0x7C00]

start:
    mov si, msg
    call print_string
    jmp $

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp print_string
.done:
    ret

msg db "Hello from boot sector!", 0x0D, 0x0A, 0

times 510-($-$$) db 0
dw 0xAA55
```

## 4. BIOS interrupt 0x10

`int 0x10` is a BIOS service for video output.
Using `AH = 0x0E` prints a character in teletype mode.

## 5. Why `0xAA55`?

The last two bytes of the boot sector are `0xAA55`.
This marks the sector as a valid boot sector.

## 6. Protected mode

Protected mode is the true foundation of modern OSes.
It introduces:
- 32-bit execution
- better memory management
- segmentation
- protection checks
- privilege concepts

## 7. GDT

GDT = Global Descriptor Table.
It defines code and data segments and their properties.
It tells the CPU:
- where code/data segments begin
- how large they are
- what permissions they have

A basic GDT entry structure includes:
- base address
- limit
- access rights
- type
- privilege level

## 8. Why switch modes?

Real mode is not enough for modern operating systems because it lacks:
- memory protection
- large address spaces
- flexible privilege models
- paging support

## 9. Long mode

Long mode is the x86_64 execution mode.
It adds:
- 64-bit registers
- 64-bit pointers
- modern paging support
- aggressive address space management

## 10. The mode progression

A modern system typically transitions:
- real mode
- protected mode
- long mode

This progression reflects the evolution from minimal booting to full OS execution.

## Key idea

The system does not start in a modern OS mode. It starts in a minimal hardware mode and gradually moves into a safe, managed execution environment.

## Quick summary

Boot sector code runs in real mode, then the system moves into protected mode and long mode as the OS prepares the environment for real execution.
