# 06. IPC and Filesystem

## 1. IPC

IPC stands for Inter-Process Communication.
It allows separate processes to communicate and coordinate.

## 2. Why IPC is needed

A program often needs to exchange data or events with another process.
Examples:
- shell piping output from one command to another
- worker processes in a server
- producer/consumer models
- log collection

## 3. Common IPC mechanisms

### Pipe
- one-way data flow
- used in shell pipelines
- very common in Unix-like systems

### FIFO
- named pipe
- supports communication across unrelated processes

### Message queue
- structured messages
- good for asynchronous messaging

### Shared memory
- fast form of sharing
- requires synchronization for correctness

### Sockets
- general communication mechanism
- supports local or network communication

### Signals
- lightweight notifications
- often used for process control

## 4. Pipe example

```bash
ls | grep .c
```

The output of `ls` is written into a pipe, and `grep` reads from that pipe.

## 5. Filesystem overview

A filesystem organizes storage into:
- files
- directories
- permissions
- metadata

This lets the OS abstract raw disk blocks into user-facing objects.

## 6. File and directory abstraction

A file is a sequence of bytes.
A directory is a mapping from names to file entries.

This gives users an interface like:
- `/home/user/project/main.c`

instead of raw disk block addresses.

## 7. inode

An inode is a metadata record for a file.
It stores:
- file size
- ownership
- permissions
- timestamps
- block pointers

The directory stores names, but the inode stores the actual file metadata.

## 8. Why inode matters

The name itself is not the file content.
The inode is the real file object.
Directories map names to inodes.

## 9. Filesystem cache and performance

The OS uses caches to reduce disk traffic.
Popular examples include:
- page cache
- inode cache
- directory entry cache

## 10. Filesystem and security

The filesystem enforces:
- permission bits
- ownership
- directory access rules

This integrates with kernel/user privilege boundaries.

## Key idea

IPC lets processes communicate; filesystems let the OS present storage in a safe and usable form.

## Quick summary

Processes are isolated, but they can still cooperate through IPC. Filesystems provide long-term, structured storage across process boundaries.
