# Environment Setup

## Tools

- GCC
- NASM
- QEMU
- GDB
- objdump
- readelf

## Linux examples

```bash
# Arch
sudo pacman -S qemu nasm gcc gdb binutils

# Ubuntu/Debian
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils
```

## Validate installation

```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
gdb --version
objdump --version
readelf --version
```
