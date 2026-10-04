# Environment Setup Guide

## Prerequisites

Before starting experiments, ensure you have the right environment.

## Arch Linux Setup

### 1. Install tools

```bash
sudo pacman -S qemu nasm gcc gdb binutils gnu-efi linux-headers
```

### 2. Verify installation

```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
gdb --version
objdump --version
readelf --version
```

### 3. Create workspace

```bash
mkdir -p ~/os-experiments/bin
mkdir -p ~/os-experiments/src
cd ~/os-experiments
```

## Ubuntu/Debian Setup

### 1. Install tools

```bash
sudo apt-get update
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils build-essential
```

### 2. Verify installation

```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
```

## macOS Setup

### 1. Install Homebrew (if not installed)

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### 2. Install tools

```bash
brew install qemu nasm gcc gdb binutils
```

### 3. Verify installation

```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
```

## Setting up shell aliases

Add to `~/.bashrc` or `~/.zshrc`:

```bash
alias qemu-run='qemu-system-x86_64 -drive format=raw,file='
alias nasm-compile='nasm -f elf64'
alias objdump-dis='objdump -d'
```

## Makefile template

Create `Makefile` in your experiment directory:

```makefile
.PHONY: all clean run debug

ASM_FLAGS = -f elf64
CC_FLAGS = -Wall -g -O0
LD_FLAGS = 

all: hello

hello: hello.o
	ld $< -o $@

hello.o: hello.asm
	nasm $(ASM_FLAGS) $< -o $@

clean:
	rm -f *.o hello

run: hello
	./hello

debug: hello
	gdb ./hello

.PHONY: all clean run debug
```

## QEMU commands reference

### Run a boot image

```bash
qemu-system-x86_64 -drive format=raw,file=boot.bin
```

### Run with debugging

```bash
qemu-system-x86_64 -drive format=raw,file=boot.bin -s -S
```

Then in another terminal:

```bash
gdb
(gdb) target remote localhost:1234
(gdb) continue
```

### Exit QEMU

```
Ctrl+A X
```

## GDB quick commands

```
break main          # Set breakpoint
run                 # Start execution
nexti               # Step one instruction
stepi               # Step into function
info registers      # Show register state
x/10x $rsp          # Show stack
disassemble         # Show assembly
continue            # Resume execution
quit                # Exit GDB
```

## objdump quick usage

```bash
objdump -d prog                    # Full disassembly
objdump -t prog                    # Symbol table
objdump -s prog                    # Section contents
objdump -h prog                    # Section headers
```

## readelf quick usage

```bash
readelf -h file                    # ELF header
readelf -l file                    # Program headers
readelf -S file                    # Section headers
readelf -s file                    # Symbol table
```

## strace usage

```bash
strace ./program                   # Trace all syscalls
strace -e trace=open,read ./prog   # Specific syscalls
strace -o log.txt ./program        # Save to file
```

## Useful environment variables

```bash
export EDITOR=vim
export CFLAGS="-Wall -g -O0"
export LDFLAGS=""
```

## Troubleshooting

### QEMU not found

```bash
which qemu-system-x86_64
```

If not found, reinstall with package manager.

### nasm syntax error

Make sure you're using the correct output format:
- `-f elf64` for 64-bit ELF
- `-f bin` for raw binary

### ld error

Check that object file format matches linker expectations.

### GDB connection refused

Make sure QEMU is running with `-s -S` flags first.

## Next steps

Once environment is set up:
1. Start with [[12-QEMU-NASM-GCC-Experiments]]
2. Follow the experiments in order
3. Keep notes in [[13-Experiment-Progress-Log]]
