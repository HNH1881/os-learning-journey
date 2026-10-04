# Mini kernel skeleton

This is a C skeleton for future work.
It is intentionally minimal and will be extended as you learn long mode, paging, VGA output, and interrupts.

```c
void kernel_main(void) {
    // TODO: initialize VGA text mode
    // TODO: set up page tables
    // TODO: enter long mode
    // TODO: print messages from C
    // TODO: install interrupts
    // TODO: create initial scheduler state

    while (1) {
        __asm__ volatile ("hlt");
    }
}
```

In a real kernel, you would usually:
- initialize the text output backend
- set up the GDT
- enable paging
- install an IDT
- create a memory manager
- eventually schedule tasks
