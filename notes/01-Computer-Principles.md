# 01. Computer Principles

## 1. What is a computer?

A computer is a machine that executes instructions on data. It takes input, processes it, and produces output.

Core idea:
- hardware executes instructions
- software gives instructions
- the OS coordinates resources

## 2. Major components

- CPU: executes instructions
- RAM: working memory
- Disk: persistent storage
- Bus: data pathway
- I/O devices: keyboard, mouse, display, network, etc.

## 3. Why binary?

Computers are electronic devices. Basic electrical states are easy to represent as:
- 0 = low voltage
- 1 = high voltage

This makes binary a natural representation for logic and arithmetic.

## 4. Number systems

- binary
- octal
- decimal
- hexadecimal

Hex is especially useful in systems work because:
- 1 hex digit = 4 bits
- it compresses binary values and is easier to read

## 5. Boolean logic

Basic gates:
- AND
- OR
- NOT
- XOR

Boolean logic is the foundation for all digital circuits, CPU operations, and arithmetic.

## 6. CPU internals

A CPU typically contains:
- ALU: arithmetic and logical unit
- control unit: decodes instructions and coordinates execution
- registers: fast temporary storage
- cache: fast memory close to CPU

## 7. Fetch-decode-execute

A processor performs a loop like:
1. fetch instruction from memory
2. decode it
3. execute it
4. update state

This is the core behavior of every machine.

## 8. Data representation

- integers are stored in binary
- signed integers often use two's complement
- floats follow IEEE 754 format

## 9. Registers

Registers are fast storage inside the CPU.
Examples:
- general-purpose registers
- instruction pointer
- stack pointer
- frame pointer

## 10. Memory hierarchy

Memory is layered:
- CPU registers
- L1 / L2 / L3 cache
- RAM
- disk
- network storage

Tradeoff:
- faster memory is smaller and more expensive

## 11. Stack vs heap

### Stack
- LIFO
- stores local variables and return addresses
- very fast
- limited size

### Heap
- used for dynamically allocated objects
- larger space
- slower than stack
- managed manually or by GC

## 12. Von Neumann architecture

The classic architecture stores both data and instructions in memory.
This makes the system programmable and flexible.

## 13. Why do we need an OS?

The system needs a mediator between hardware and programs.
The OS provides:
- abstraction
- resource management
- protection
- scheduling

## Key idea

The OS turns raw hardware into usable, safe, shared resources.

## Quick summary

The CPU executes instructions, memory stores data, and the OS orchestrates access to those resources.
