# Embedded Rust Coding Standards

This document establishes the standards for writing **Rust** in bare-metal and resource-constrained embedded systems. Rust provides compile-time safety guarantees, making it a powerful language for writing reliable hardware drivers and runtimes.

---

## 🎯 Core Principles

1. **Memory Safety Without GC**: Leverage Rust's borrow checker to manage memory and hardware access rules at compile time.
2. **Safe Concurrency**: Use `Send` and `Sync` traits to prevent data races in multi-threaded or interrupt-driven contexts.
3. **Encapsulate Unsafe**: Restrict and audit code that interacts directly with hardware registers or performs raw operations.

---

## 📏 Key Standards

### 1. The `no_std` Environment
* All embedded crates must use the `#![no_std]` attribute to exclude the standard library.
* Use the `core` library and `alloc` (only if a heap allocator is explicitly approved and implemented).

### 2. Managing `unsafe` Code
* **Isolate Unsafe**: Keep `unsafe` blocks as small as possible. Implement them only inside safe abstraction wrappers.
* **Documentation**: Every `unsafe` block must be preceded by a `// SAFETY:` comment explaining why the block is safe to execute and what invariants must hold.
* **Avoid Raw Pointers**: Use safe PACs (Peripheral Access Crates) or HALs (Hardware Abstraction Layers) instead of raw pointer casting for register access.

### 3. Concurrency & Interrupts
* **Share Safely**: Protect shared resources with safe abstraction types (e.g., `Mutex` from critical-section crates).
* **Interrupt Handlers**: Keep interrupt service routines (ISRs) small and fast. Offload complex processing to the main loop or RTIC (Real-Time Interrupt-driven Concurrency) tasks.

---

## 🔍 Linting & Formatting

* Format all code with `cargo fmt`.
* Enable strict linting with `cargo clippy` and configure `deny(warnings)` in CI/CD pipelines.
