# Coding Standards & Best Practices

Welcome to the **Coding Standards** directory. The ultimate goal of this repository is to define general, high-quality coding standards across a variety of programming languages. 

Initial focus is placed on **Embedded Systems Development** utilizing **C**, **C++**, and **Rust**. Embedded environments impose unique constraints (e.g., real-time deadlines, limited memory, hardware safety boundaries) that require specialized, deterministic coding practices.

---

## 📂 Directory Structure

To keep standards modular, actionable, and easily expandable to other domains (e.g., web development, cloud infrastructure) in the future, we organize the standards into **00_general principles**, **01_embedded standards**, and **99_reference-standards**.

```mermaid
graph TD
    Root["codingStandards/"] --> README["README.md (This File)"]
    Root --> Gen["00_general/"]
    Root --> Emb["01_embedded/"]
    Root --> Ref["99_reference-standards/"]

    Gen --> Naming["naming-conventions.md"]
    Gen --> Funcs["functions-and-classes.md"]
    Gen --> Form["formatting/comments-and-formatting.md"]
    Gen --> Err["error-handling-and-testing/"]

    Err --> ErrMain["error-handling-and-testing.md"]
    Err --> ErrC["c.md"]
    Err --> ErrCpp["cpp.md"]
    Err --> ErrRust["rust.md"]

    Emb --> EmbC["c/"]
    Emb --> EmbCpp["cpp/"]
    Emb --> EmbRust["rust/"]

    Ref --> NASA["nasa/"]
    Ref --> Books["books/cleanCode/"]
```

### Directory Taxonomy

1.  **[00_general/](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/)**: Platform and language-agnostic actionable standards.
    *   [naming-conventions.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/naming-conventions.md): Casing, naming constraints, and concept alignment rules.
    *   [functions-and-classes.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/functions-and-classes.md): Function and class size limits, parameter rules, and SRP/Cohesion limits.
    *   [formatting/comments-and-formatting.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/formatting/comments-and-formatting.md): Formatting layout, vertical/horizontal distance, and comments.
    *   [error-handling-and-testing/](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/): Structure for error handling and validation:
        *   [error-handling-and-testing.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/error-handling-and-testing.md): Common error philosophy, null-safety, and F.I.R.S.T. unit testing principles.
        *   [c.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/c.md): C error return codes, out pointers, and unity testing guidelines.
        *   [cpp.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/cpp.md): C++ optional/expected types, exception usage, and Google Test patterns.
        *   [rust.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/rust.md): Rust Result/Option types, panic avoidance rules, and cargo testing.
2.  **[01_embedded/](file:///home/gboud21/code/Software_Training/doc/codingStandards/01_embedded/)**: Domain-specific standards for embedded systems.
    *   [c/README.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/01_embedded/c/README.md): Safe C development, resource constraint management, and hardware safety.
    *   [cpp/README.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/01_embedded/cpp/README.md): Modern C++ best practices for embedded systems (e.g., avoiding RTTI/exceptions, using templates safely).
    *   [rust/README.md](file:///home/gboud21/code/Software_Training/doc/codingStandards/01_embedded/rust/README.md): Safety-critical systems development using `no_std`, safe concurrency patterns, and the ownership model.
3.  **[99_reference-standards/](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/)**: Curated industry-standard guidelines and background reference materials.
    *   [nasa/](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/nasa/): Safety-critical software standards.
        *   [TenCommandments.txt](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/nasa/TenCommandments.txt) (NASA's Power of 10 rules).
    *   [books/cleanCode/](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/): Summaries and adaptations of classic clean-code methodologies.
        *   [Chapter 1: Philosophy](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter1.md)
        *   [Chapter 2: Meaningful Names](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter2.md)
        *   [Chapter 3: Functions](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter3.md)
        *   [Chapter 4: Comments](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter4.md)
        *   [Chapter 5: Formatting](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter5.md)
        *   [Chapter 6: Objects & Data Structures](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter6.md)
        *   [Chapter 7: Error Handling](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter7.md)
        *   [Chapter 8: Boundaries](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter8.md)
        *   [Chapter 9: Unit Tests](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter9.md)
        *   [Chapter 10: Classes](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter10.md)
        *   [Chapter 11: Systems](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter11.md)
        *   [Chapter 12: Emergence](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter12.md)
        *   [Chapter 13: Concurrency](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter13.md)
        *   [Chapters 14–16: Refactoring Case Studies](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapters14_16.md)
        *   [Chapter 17: Smells & Heuristics](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/books/cleanCode/Chapter17.md)

---

## 🛠️ Language Specific Framework (Embedded Systems)

Embedded systems require code to be predictable, testable, and robust. Below is the framework outlining the standards for C, C++, and Rust.

### 1. Embedded C
C remains a cornerstone of embedded development, but its lack of safety features necessitates strict compliance rules.
*   **Predictable Execution**: Avoid recursion to ensure stack boundaries are statically analyzable.
*   **Deterministic Memory**: Strictly ban dynamic memory allocation (`malloc`, `free`) after the initialization phase to prevent heap fragmentation and memory leaks.
*   **References**: See NASA's [TenCommandments.txt](file:///home/gboud21/code/Software_Training/doc/codingStandards/99_reference-standards/nasa/TenCommandments.txt) for control flow and pointer restrictions.

> [!IMPORTANT]
> All Embedded C code should target compiler flags that treat warnings as errors (e.g., `-Wall -Wextra -Werror`).

### 2. Embedded C++
C++ introduces abstractions that can improve readability but must be used carefully in embedded contexts.
*   **Zero-Cost Abstractions**: Leverage template metaprogramming and inline functions to prevent runtime overhead.
*   **Restricted Features**: Disable Exceptions (`-fno-exceptions`) and Real-Time Type Information (`-fno-rtti`) to reduce binary size and ensure deterministic execution.
*   **Resource Management**: Use RAII (Resource Acquisition Is Initialization) to manage hardware resources (e.g., lock guards, peripheral ownership).

### 3. Embedded Rust
Rust provides compile-time safety guarantees, making it an excellent fit for modern embedded software.
*   **Environment**: Target `no_std` environments to run directly on bare metal without a standard library.
*   **Memory and Concurrency**: Leverage Rust's ownership model and the `Send` / `Sync` traits to prevent data races and memory corruption at compile time.
*   **Unsafe Code Boundaries**: Explicitly document and isolate `unsafe` blocks required for direct register or hardware access, ensuring they are wrapped in safe abstractions.

---

## 🚀 Implementation Roadmap

To build out this directory successfully, we will follow a phased approach:

- [x] **Phase 1: Structure Alignment**: Relocate reference materials and establish the core taxonomy.
- [x] **Phase 2: General Standards Extrapolation**: Author core language-agnostic standards for naming, functions, classes, comments, formatting, error handling, and testing.
- [ ] **Phase 3: Embedded C Guidelines Detail**: Author detailed guidelines for C, focusing on hardware register access and MISRA-C alignment.
- [ ] **Phase 4: Embedded C++ Guidelines Detail**: Establish rules for safe object-oriented design and memory management in C++.
- [ ] **Phase 5: Embedded Rust Guidelines Detail**: Create templates for `no_std` drivers and peripheral access crates.
- [ ] **Phase 6: Automation**: Integrate static analysis tool rulesets (e.g., `.clang-tidy`, `clippy.toml`, `.rustfmt.toml`) into each language directory.
