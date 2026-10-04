# 05. Processes and Threads

## 1. Program vs process

A program is static code on disk.
A process is a running instance of a program.

A process has:
- code
- data
- heap
- stack
- page table
- process ID
- execution state

## 2. Process creation

The OS creates a process by:
- allocating a new task structure
- setting up page tables
- loading the program image
- setting initial registers
- placing it in the ready queue

## 3. Process state model

Common states:
- new
- ready
- running
- waiting/blocked
- terminated

## 4. Threads

A thread is the execution unit inside a process.
Threads share:
- process address space
- heap
- global data

Threads have:
- their own stack
- their own registers
- their own execution context

## 5. Process vs thread

Process:
- isolated virtual memory
- heavier switching cost
- strong isolation

Thread:
- same address space
- lighter switching cost
- easier shared-state communication

## 6. Context switch

Context switch is the process of:
- saving the current process/thread state
- restoring the next process/thread state
- switching the CPU to the next execution context

## 7. Scheduler

The scheduler chooses which runnable task should execute next.
Typical goals:
- fairness
- throughput
- responsiveness
- low waiting time

## 8. Scheduling algorithms

Common algorithms:
- round robin
- FCFS
- shortest job first
- priority scheduling
- multilevel feedback queue

## 9. Time slice

A time slice is the amount of CPU time a task receives before the scheduler preempts it.

Too short:
- heavy context switching overhead

Too long:
- poor responsiveness

## 10. Why threads are useful

Threads enable concurrency in a single process.
They are used for:
- server workloads
- UI responsiveness
- background tasks
- data processing

## 11. Why threads are dangerous

Threads share memory, so they can interfere with each other.
This introduces:
- race conditions
- deadlocks
- starvation
- inconsistent data

## Key idea

Processes provide isolation, and threads provide concurrency inside that isolation boundary.

## Quick summary

The OS schedules tasks, manages their state, and switches processor context so many tasks appear to run at the same time.
