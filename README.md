# 1337
This repo contains my 1337 projects
This is my effort on 42! so it's private
----
# My Libft Project

The libft project is a coding challenge where you create your own C library by re-implementing standard C functions to better understand their inner workings.

### What is static Library ?
A static library is a collection of object files that are linked into a program at compile time, resulting in a single executable. It allows for code reuse without needing to recompile the library each time the program is run.

Libft is typically a static library. In the project, you compile your custom functions into a static library (usually named libft.a), which is then linked to your programs at compile time. It doesn't involve runtime linking like dynamic libraries.

# Static vs Dynamic Libraries

## Overview

Libraries are collections of precompiled code that programs can use. They help promote code reuse and modular programming. There are two main types of libraries:

1. **Static Libraries**
2. **Dynamic Libraries**

This document explains the key differences between the two types.

## Key Differences

| **Feature**                | **Static Library**                                | **Dynamic Library**                                |
|----------------------------|--------------------------------------------------|---------------------------------------------------|
| **Linking Time**            | Linked at **compile time**, becoming part of the executable. | Linked at **runtime**, loaded when the program starts or during execution. |
| **File Extension**          | `.a` (Unix/Linux) or `.lib` (Windows)            | `.so` (Unix/Linux) or `.dll` (Windows)            |
| **Memory Usage**            | Increases the executable size as the library code is included in each program. | Shared across multiple programs, reducing overall memory usage. |
| **Update Process**          | Requires recompilation of the program when the library is updated. | No need to recompile; the updated library is automatically used at runtime. |
| **Performance**             | Typically faster, as the code is part of the executable and no runtime loading is needed. | Slight overhead at runtime due to loading and linking of the library. |

## Static Library

A **static library** is a collection of object files that are bundled together into a single file. When a program is compiled, the necessary library code is copied into the program's executable.

- **Pros**: 
  - Faster execution because all code is in the executable.
  - No external dependencies at runtime.
- **Cons**: 
  - Larger executable size.
  - Needs recompilation when the library is updated.

## Dynamic Library

A **dynamic library** is a separate file that is linked to the program at runtime. The library is loaded into memory when the program starts or during its execution.

- **Pros**: 
  - Smaller executable size since the code isn’t copied into the program.
  - Programs automatically use updated libraries without recompilation.
  - Shared across multiple programs, saving memory.
- **Cons**: 
  - Adds a small performance overhead during the runtime linking process.
  - Programs rely on the availability of the external library at runtime.

Both static and dynamic libraries serve different purposes depending on the needs of the program. Static libraries provide simplicity and performance, while dynamic libraries offer flexibility and memory efficiency.

----

