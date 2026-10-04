# Experiment Progress Log

## Purpose

Track your hands-on experiments with QEMU, NASM, and GCC.
After each experiment, fill in this log.

## Experiment Template

### Experiment [Number]: [Title]

**Date:** YYYY-MM-DD
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

What are you trying to understand or build?

#### Tools used

- Tool 1 and version
- Tool 2 and version

#### Steps taken

1. Step 1
2. Step 2
3. Step 3

#### Code written

```asm
; assembly code here
```

or

```c
// C code here
```

#### Output

What did the program output?

#### Observation

What did you observe?
Did it match your expectation?

#### What I learned

- Insight 1
- Insight 2
- Insight 3

#### Issues encountered

- Issue 1: Description and how I solved it
- Issue 2: Description and how I solved it

#### Next step

What experiment comes next?

---

## Actual experiments

### Experiment 1: Hello World in Assembly

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Write and run a minimal x86_64 assembly program on Linux.

#### Tools used

- NASM
- ld (linker)
- Arch Linux

#### Steps taken

1. Write hello.asm
2. Assemble with nasm
3. Link with ld
4. Run ./hello
5. Verify exit code

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 2: C to Assembly

---

### Experiment 2: C to Assembly

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Compile C to assembly and understand the mapping.

#### Tools used

- GCC
- objdump

#### Steps taken

1. Write simple.c
2. Compile with gcc -S
3. Read simple.s
4. Compile and objdump

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 3: Boot Sector

---

### Experiment 3: Boot Sector in QEMU

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Write a minimal bootloader and run it in QEMU.

#### Tools used

- NASM
- QEMU

#### Steps taken

1. Write boot.asm
2. Assemble to boot.bin
3. Run in QEMU
4. See output

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 4: Debugging with GDB

---

### Experiment 4: Debugging with GDB

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Learn to use GDB to step through code and inspect state.

#### Tools used

- GCC
- GDB

#### Steps taken

1. Compile with -g flag
2. Start gdb
3. Set breakpoint at main
4. Step through code
5. Inspect registers

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 5: Fork and Process Creation

---

### Experiment 5: Fork and Process Creation

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Understand fork and parent-child process relationship.

#### Tools used

- GCC
- strace

#### Steps taken

1. Write fork_test.c
2. Compile
3. Run and see output
4. Trace with strace

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 6: Race Conditions

---

### Experiment 6: Race Conditions and Mutex

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Observe race conditions and test mutex protection.

#### Tools used

- GCC
- pthread

#### Steps taken

1. Write race.c (unprotected)
2. Run multiple times and observe different results
3. Write race_safe.c (with mutex)
4. Compare results

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 7: Pipes and IPC

---

### Experiment 7: Pipes and IPC

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Understand inter-process communication via pipes.

#### Tools used

- GCC
- shell

#### Steps taken

1. Write pipe_test.c
2. Compile and run
3. Test shell pipes like ls | grep
4. Observe data flow

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 8: File System and inode

---

### Experiment 8: Filesystem and inode

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Understand inodes, hard links, and soft links.

#### Tools used

- ls
- stat
- ln

#### Steps taken

1. Create a test file
2. Check its inode
3. Create hard link and soft link
4. Observe differences

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 9: Signal Handling

---

### Experiment 9: Signal Handling

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Understand signals and asynchronous event handling.

#### Tools used

- GCC
- signal

#### Steps taken

1. Write signal_test.c
2. Compile
3. Run and press Ctrl+C
4. Observe handler

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 10: ELF File Format Analysis

---

### Experiment 10: ELF File Format

**Date:** 
**Status:** [ ] Started [ ] In Progress [ ] Completed

#### Objective

Understand ELF executable file structure.

#### Tools used

- readelf
- objdump
- hexdump

#### Steps taken

1. Compile a simple program
2. Use readelf to view structure
3. Use objdump to view code
4. Check symbol table

#### Output

```
```

#### Observation


#### What I learned


#### Issues encountered


#### Next step

Experiment 11: Protected Mode and CPU Modes

---

## Summary

After completing all experiments, write a summary of what you've learned.
