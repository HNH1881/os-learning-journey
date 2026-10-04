# 02. Assembly Language

## 1. What is assembly?

Assembly is a low-level representation of machine instructions.
It is closer to the CPU than C, Java, Python, or other high-level languages.

## 2. Why learn assembly?

Because assembly helps you understand:
- CPU instructions
- memory addresses
- registers
- function calls
- system calls
- the difference between source code and machine code

## 3. Registers

Registers are CPU-internal storage.
Common x86_64 registers:
- RAX, RBX, RCX, RDX
- RSI, RDI
- RSP, RBP
- RIP
- R8-R15

Important points:
- registers are very fast
- there are only a small number of them
- they are heavily used during execution

## 4. Common instruction categories

### Data movement
- MOV
- LEA
- PUSH
- POP

### Arithmetic
- ADD
- SUB
- INC
- DEC
- IMUL

### Logic
- AND
- OR
- XOR
- NOT
- SHL
- SHR

### Comparison and jumps
- CMP
- JMP
- JE
- JNE
- JG
- JL

### Function calls
- CALL
- RET

## 5. System calls

System calls allow user programs to ask the kernel to do privileged work.
On Linux x86_64:
- `rax` = syscall number
- `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` = arguments
- `syscall` triggers the transition to kernel mode

Example:
- `write` uses syscall number 1
- `exit` uses syscall number 60

## 6. Example: Linux assembly hello world

```asm
section .data
    msg db "Hello, World!", 0x0a
    len equ $ - msg

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    lea rsi, [msg]
    mov rdx, len
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
```

## 7. Why assembly matters for OS study

Assembly makes the following visible:
- function call mechanics
- stack usage
- CPU register behavior
- memory data movement
- system call invocation
- kernel entry points

## 8. C to assembly

A C compiler translates code into assembly and then into machine code.
This is how high-level code becomes CPU-specific instructions.

Example:
```c
int add(int a, int b) {
    return a + b;
}
```

might compile into something like:
```asm
add:
    mov eax, edi
    add eax, esi
    ret
```

## 9. Stack frame model

A function call typically does this:
- save return address
- allocate stack space for locals
- use base pointer and stack pointer
- restore state on return

## 10. Key idea

Assembly reveals the actual machine behavior under every high-level program.

## Quick checklist

- [ ] Understand registers
- [ ] Understand jump instructions
- [ ] Understand stack operations
- [ ] Understand syscall convention
- [ ] Connect C code to assembly output
