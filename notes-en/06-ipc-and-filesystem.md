# 06. IPC and Filesystem

## 1. IPC

IPC means Inter-Process Communication.

IPC 表示进程间通信。

It allows separate programs to exchange data, signals, or messages.

它允许不同程序交换数据、信号或消息。

## 2. Common IPC mechanisms

Pipes, FIFOs, message queues, shared memory, sockets, and signals are common examples.

常见 IPC 机制包括管道、FIFO、消息队列、共享内存、Socket 和信号。

Each mechanism is suited to a different communication pattern.

每种机制适合不同的通信模式。

## 3. Filesystem

A filesystem turns raw disk blocks into files and directories.

文件系统把原始磁盘块转换成文件和目录。

This is the abstract layer between users and storage hardware.

这是用户和存储硬件之间的抽象层。

## 4. Inode

An inode is the metadata record for a file.

inode 是文件的元数据记录。

It stores size, ownership, permissions, timestamps, and block addresses.

它存储大小、所有者、权限、时间戳和数据块位置。

## 5. Summary / 总结

IPC is about communication between processes, while the filesystem is about persistent storage and naming.

IPC 关注进程之间的通信，文件系统关注持久化存储和命名。
