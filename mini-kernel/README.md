# Mini Kernel Skeleton

This project is a practical kernel skeleton that grows with your OS knowledge.
It starts from a boot sector that works in QEMU, and it is intentionally designed so you can extend it step by step.

## What this contains

- `boot.asm`: minimal 16-bit bootloader that prints a message
- `kernel.c`: C kernel skeleton for future long mode / paging work
- `Makefile`: builds the boot image and runs QEMU
- `qemu.sh`: quick launch helper

## Quick start

```bash
make run
```

## Expected output

```text
Hello from mini kernel!
```

This is the first milestone: booting a kernel-like binary in QEMU.

## Next milestones

After this works, the next steps are:

1. move into protected mode
2. enable long mode
3. set up paging
4. print to VGA text memory
5. add a C kernel entrypoint
6. handle interrupts
7. add a basic scheduler

## Notes

This is intentionally small and beginner-friendly. It is designed to teach the real structure of a kernel, not just the final result.
