# 04. Memory and Paging

## 1. Why memory management matters

If user programs directly accessed physical memory, they could overwrite each other or corrupt the kernel.
The OS solves this with abstraction and protection.

## 2. Virtual memory

Programs use virtual addresses, not physical addresses.
The OS maps virtual addresses to physical memory via page tables.

This creates an illusion that each program has its own large and private memory space.

## 3. Paging

Paging divides memory into fixed-size pages.
Typical page size:
- 4 KB

This improves memory management and allows OS-controlled mapping.

## 4. Page tables

x86_64 uses hierarchical paging.
A typical translation uses:
- PML4
- PDPT
- PD
- PT

Each level is a table with 512 entries.

## 5. Virtual address layout

A 48-bit virtual address is typically split into:
- 9 bits for PML4 index
- 9 bits for PDPT index
- 9 bits for PD index
- 9 bits for PT index
- 12 bits for page offset

## 6. Example translation flow

A virtual address goes through:
1. PML4 lookup
2. PDPT lookup
3. PD lookup
4. PT lookup
5. final physical page + offset

## 7. CR3

`CR3` stores the physical address of the current page table.
It tells the CPU which address space is active.

This is essential for process isolation.

## 8. Page fault

A page fault occurs when a page is not mapped, is not present, or lacks permission.
Common causes:
- page not allocated
- page not loaded into memory
- writing to read-only page
- invalid access

The OS handles page faults by:
- allocating a page
- loading data into memory
- updating the page table
- resuming execution

## 9. Identity mapping

Early kernel boot code often uses identity mapping:
- virtual address == physical address

This is simpler for initial setup.

## 10. Why paging is so important

Paging enables:
- memory isolation
- process virtual address spaces
- page-level permissions
- page fault handling
- lazy allocation
- demand paging
- security boundaries

## 11. Key relationship

Paging connects the CPU execution model and OS memory management.
It is one of the most important ideas in operating systems.

## Quick summary

Paging is the mechanism that maps virtual addresses to physical memory and allows the OS to isolate processes and manage memory safely.
