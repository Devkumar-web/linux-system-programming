# System Software Lab

A collection of hands-on implementations exploring Linux System Programming
and Operating System internals using C.

This repository contains implementations of:

- File Management System Calls
- File Descriptors
- Process Management
- Process Creation and Synchronization
- File Locking
- Scheduling Policies
- Daemon Processes

## Topics Covered

### File Management
- creat()
- open()
- read()
- write()
- close()
- lseek()
- stat()
- dup()
- dup2()
- fcntl()
- select()

### Process Management
- fork()
- exec() family
- wait()
- waitpid()
- Zombie Processes
- Orphan Processes
- Process Priority
- Scheduling Policies
- Daemon Processes

## Environment

- OS: Linux
- Language: C
- Compiler: GCC

## How to Compile

```bash
gcc program.c -o program
./program
