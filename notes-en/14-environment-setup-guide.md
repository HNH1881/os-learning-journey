# 14. Environment Setup Guide

## Why this matters / 为什么重要

A working toolchain is required for all experiments.

一个可用的工具链是所有实验的前提。

## Required tools / 必需工具

- GCC
- NASM
- QEMU
- GDB
- objdump
- readelf

## Install / 安装

```bash
sudo pacman -S qemu nasm gcc gdb binutils
```

```bash
sudo apt-get install qemu-system-x86 nasm gcc gdb binutils
```

## Verify / 验证

```bash
qemu-system-x86_64 --version
nasm -version
gcc --version
```

## Summary / 总结

The OS lab is only meaningful when the environment is reliable.

只有环境可靠，操作系统实验才有意义。
