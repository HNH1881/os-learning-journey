# 07. I/O and Drivers

## 1. I/O basics

I/O is how the OS interacts with external devices.
Examples:
- keyboard
- display
- disk
- sound
- network card

## 2. Device driver

A device driver is the software layer that talks to a specific device.
It translates OS requests into device-specific control and data transfer.

## 3. Why drivers are needed

Devices differ dramatically in protocol and behavior.
The OS hides this complexity behind a common API.

Examples:
- read
- write
- open
- close
- ioctl

## 4. Block devices vs character devices

### Block devices
- transfer data in chunks
- used for disks, USB devices
- support random access

### Character devices
- transfer streams of bytes
- used for terminal, serial, keyboard

## 5. Interrupts

An interrupt is an asynchronous notification from hardware to the CPU.
Examples:
- disk read completed
- key press occurred
- timer expired
- network packet arrived

The CPU pauses current work, handles the interrupt, and returns.

## 6. DMA

DMA stands for Direct Memory Access.
It allows a device to move data to/from memory without CPU copying each byte.

This is very important for:
- storage devices
- network cards
- graphics pipelines
- audio/video streaming

## 7. Buffering and caching

The OS often uses buffers to smooth out differences between producer and consumer speeds.
Examples:
- page cache
- kernel read/write buffers
- network buffers

## 8. I/O scheduling

When many I/O requests are queued, the OS may reorder them to improve throughput.
Examples:
- elevator scheduling
- shortest seek time first

## 9. Why I/O abstraction matters

Programs should not have to know every hardware detail.
The OS provides a stable, structured interface that hides hardware differences.

## Key idea

I/O management is how the kernel turns raw hardware into usable resources for user programs.

## Quick summary

Interrupts, DMA, drivers, and buffers are all part of the OS's mechanism for managing devices efficiently and safely.
