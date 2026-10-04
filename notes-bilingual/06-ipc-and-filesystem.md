# 06. IPC and Filesystem / IPC 与文件系统

## 1. IPC / 1. IPC

English:
IPC stands for Inter-Process Communication. It lets processes exchange data and coordinate actions.

中文:
IPC 是 Inter-Process Communication 的缩写，表示进程间通信。它允许不同进程交换数据并协同工作。

## 2. Why IPC is needed / 2. 为什么需要 IPC

English:
Programs often need to pass output, events, or data between processes, such as shell pipelines or worker services.

中文:
程序常常需要在进程之间传递输出、事件或数据，例如 shell 管道和服务进程之间的协作。

## 3. Common mechanisms / 3. 常见机制

English:
Pipes, FIFOs, message queues, shared memory, sockets, signals, and semaphores are common IPC techniques.

中文:
常见 IPC 机制包括管道、FIFO、消息队列、共享内存、Socket、信号和信号量。

## 4. Filesystem overview / 4. 文件系统概述

English:
A filesystem abstracts raw storage into files, directories, paths, metadata, and permissions.

中文:
文件系统将原始存储抽象成文件、目录、路径、元数据和权限。

## 5. inode / 5. inode

English:
An inode stores file metadata such as size, type, ownership, timestamps, and data block locations.

中文:
inode 保存文件元数据，例如大小、类型、权限、时间戳和数据块位置。

## 6. Why names and inodes differ / 6. 为什么文件名和 inode 不同

English:
The directory maps names to inodes; the inode is the actual file object that stores the data and metadata.

中文:
目录负责把文件名映射到 inode，而 inode 才是实际的文件对象，负责保存数据和元数据。

## 7. Filesystem cache / 7. 文件系统缓存

English:
The OS uses page cache and inode caches to reduce disk traffic and improve read/write performance.

中文:
操作系统使用页缓存和 inode 缓存来减少磁盘访问并提高读写性能。

## 8. Security / 8. 安全性

English:
Filesystems enforce permission bits, ownership, and access control rules.

中文:
文件系统负责执行权限位、所有权和访问控制规则。

## Summary / 总结

English:
IPC enables cooperation between isolated processes, and the filesystem provides structured, secure, long-lived storage.

中文:
IPC 让相互隔离的进程能够协作，而文件系统提供结构化、安全且长期保存的数据存储。
