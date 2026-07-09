# Embedded C Coding Standards

This document establishes the coding standards and best practices for writing robust, safety-critical, and resource-constrained **C** code for embedded systems.

---

## 🎯 Core Principles

1. **Deterministic Execution**: Eliminate runtime unpredictability (avoid recursion, unbounded loops, dynamic memory).
2. **Compile-Time Verification**: Rely heavily on the compiler and static analysis tools.
3. **Hardware Safety**: Write safe wrappers around memory-mapped registers.

---

## 📏 Key Standards

### 1. Control Flow & Stack Safety
* **No Recursion**: Functions must not call themselves directly or indirectly. This creates a predictable call graph and enables static stack-use bounds checking.
* **Bounded Loops**: Every loop (`for`, `while`, `do-while`) must have a hard upper bound that can be statically verified.
* **Simple Flow**: Avoid complex jumps. Ban `goto`, `setjmp`, and `longjmp`.

### 2. Memory Management
* **No Dynamic Allocation**: Functions like `malloc()`, `calloc()`, `realloc()`, and `free()` are banned after system initialization. All memory must be statically allocated or allocated on the stack within bounded limits.

### 3. Pointer & Parameter Safety
* **Single Level of Dereferencing**: Avoid deep pointer nesting (e.g., `***ptr`). Do not use function pointers unless absolutely necessary for callbacks/interrupts, as they hinder static analysis.
* **Input Validation**: Check all function arguments (e.g., check pointers for `NULL`, assert integer ranges) before use.
* **Return Value Verification**: Never ignore the return value of non-void functions.

---

## 🔍 Static Analysis & Compilers

* All code must compile with pedantic warning flags enabled (e.g., `-Wall -Wextra -Werror -pedantic`).
* Integrate a static analyzer (e.g., `clang-tidy`, `cppcheck`) into the build pipeline.

---

## 📚 References
* [NASA's Power of 10 Rules](file:///home/gboud21/code/Software_Training/doc/codingStandards/reference-standards/nasa/TenCommandments.txt)
* MISRA C:2012 Guidelines
