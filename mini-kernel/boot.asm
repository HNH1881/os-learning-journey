# Minimal boot sector for QEMU

[ORG 0x7C00]
[BITS 16]

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    mov si, message
    call print_string

hang:
    jmp hang

print_string:
    lodsb
    or al, al
    jz done
    mov ah, 0x0E
    int 0x10
    jmp print_string

done:
    ret

message:
    db 'Hello from mini kernel!', 0x0D, 0x0A, 0

; Boot sector signature
TIMES 510 - ($ - $$) db 0
DW 0xAA55
