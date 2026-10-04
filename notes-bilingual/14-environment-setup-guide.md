# 14. Environment Setup Guide / 环境搭建指南

## Tools / 工具

English:
- GCC
- NASM
- QEMU
- GDB
- objdump
- readelf

中文:
- GCC
- NASM
- QEMU
- GDB
- objdump
- readelf

## Install commands / 安装命令

English:
```bash
# Arch
sudo pacman -S qemu nasm gcc gdb binutils

# Ubuntu / Debian
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils
```

中文:
```bash
# Arch
sudo pacman -S qemu nasm gcc gdb binutils

# Ubuntu / Debian
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils
```

## Validation / 验证

English:
```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
gdb --version
objdump --version
readelf --version
```

中文:
```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
gdb --version
objdump --version
readelf --version
```

## Practical recommendation / 实践建议

English:
Use a small Makefile, keep build artifacts separate, and document the experiments in a progress log.

中文:
使用小型 Makefile，把构建产物和笔记分别存放，并在实验日志中记录过程。
