# 05. Processes and Threads / 进程与线程

## 1. Program vs process / 1. 程序与进程的区别

English:
A program is static code on disk; a process is an executing instance of that program with its own state.

中文:
程序是磁盘上的静态代码；进程是程序执行时的实例，带有自己的状态。

## 2. Process creation / 2. 进程创建

English:
The OS allocates process metadata, page tables, and execution state, then loads the program image and places it in the ready queue.

中文:
操作系统会分配进程元数据、页表和执行状态，然后加载程序镜像，并将其放入就绪队列。

## 3. Process states / 3. 进程状态

English:
Common states include new, ready, running, waiting, and terminated.

中文:
常见状态包括新建、就绪、运行、等待和终止。

## 4. Threads / 4. 线程

English:
A thread is an execution context inside a process. Threads share the process address space but have their own stack and registers.

中文:
线程是进程里面的执行上下文。线程共享进程地址空间，但各自拥有自己的栈和寄存器。

## 5. Process vs thread / 5. 进程和线程的区别

English:
Processes have stronger isolation and more expensive creation/switching. Threads are lighter and share address space.

中文:
进程隔离更强，创建和切换成本更高；线程更轻量，并共享同一地址空间。

## 6. Context switch / 6. 上下文切换

English:
A context switch saves the current execution state and restores the next task's state before resuming CPU execution.

中文:
上下文切换会保存当前执行状态，并恢复下一个任务的状态，然后继续执行。

## 7. Scheduler / 7. 调度器

English:
The scheduler chooses which runnable task gets CPU time next, balancing fairness and responsiveness.

中文:
调度器决定哪个可运行任务下一步获得 CPU 时间，并平衡公平性和响应性。

## 8. Time slices / 8. 时间片

English:
A time slice is a period of CPU time given to a task before the scheduler preempts it.

中文:
时间片是调度器给任务分配的一段 CPU 时间，之后会进行抢占切换。

## 9. Why threads are useful / 9. 为什么线程常见

English:
Threads allow concurrency inside one process and are used for servers, GUI responsiveness, and background workloads.

中文:
线程允许一个进程内并发执行多个任务，常用于 Web 服务器、图形界面和后台工作。

## 10. Why threads are dangerous / 10. 为什么线程也危险

English:
Threads share memory, which creates race conditions, deadlocks, and inconsistent state.

中文:
线程共享内存，因此可能出现竞争条件、死锁和状态不一致。

## Summary / 总结

English:
Processes provide isolation, threads provide concurrency, and the scheduler coordinates CPU time among them.

中文:
进程提供隔离，线程提供并发，调度器负责协调它们在 CPU 上的时间分配。
