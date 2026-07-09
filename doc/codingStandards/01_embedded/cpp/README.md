# Embedded C++ Coding Standards

This document outlines the coding standards for using **C++** in resource-constrained and real-time embedded environments. C++ provides powerful abstraction mechanisms, but they must be selected and configured carefully to avoid runtime overhead.

---

## 🎯 Core Principles

1. **Zero-Cost Abstractions**: Only use features that do not introduce hidden performance or size overhead.
2. **Object Ownership**: Leverage RAII (Resource Acquisition Is Initialization) to manage peripherals, memory, and hardware locks.
3. **Type Safety**: Use strongly typed constructs (e.g., `enum class`, templates) instead of macros or raw pointers.

---

## 📏 Key Standards

### 1. Restricted Features (The "No-Go" List)
* **No Exceptions**: Compile with `-fno-exceptions`. Exceptions introduce non-deterministic execution times and large binary bloat. Use standard return codes, `std::optional`, or custom result types for error handling.
* **No RTTI (Run-Time Type Information)**: Compile with `-fno-rtti`. Avoid `dynamic_cast` and use static polymorphism (templates/CRTP) instead.
* **No Dynamic Memory**: Do not use `std::vector`, `std::string`, or other STL containers that allocate on the heap. Use static or fixed-capacity alternatives (e.g., `std::array`).

### 2. Modern C++ Best Practices
* **Constexpr**: Maximize the use of `constexpr` and `consteval` to push calculations, tables, and configuration validation to compile time.
* **Smart Pointers (Stack/Static)**: Use `std::unique_ptr` with custom deleters for managing hardware resources, avoiding raw ownership.
* **Namespaces**: Wrap all drivers and application modules in distinct namespaces to prevent naming collisions.

---

## 🔍 Tooling & Verification

* Use `clang-tidy` to enforce modern C++ practices and flag forbidden features.
* Inspect generated assembly for templates to ensure they do not cause code bloat (template instantiation explosion).
