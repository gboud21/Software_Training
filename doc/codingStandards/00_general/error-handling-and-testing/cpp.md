# Error Handling and Testing in C++

This document defines the language-specific standards for error propagation, resource management, and unit testing in **C++**.

---

## ⚠️ Error Handling in C++

C++ supports exceptions, but also provides modern, non-throwing alternatives. The strategy must be chosen based on the application's domain constraints.

### 1. Exceptions vs. Value-based Error Handling
*   **Application Code (Standard Systems)**: Use exceptions (`throw`, `try`, `catch`) for unexpected runtime errors that are outside the program's control (e.g., file not found, network timeout).
*   **Performance-Critical & Embedded Code**: Disable exceptions (`-fno-exceptions`) to guarantee execution timing and minimize binary size. Use value-based alternatives:
    *   **`std::optional` (C++17)**: Use when a function might not return a value, but the reason for absence is trivial or irrelevant.
    *   **`std::expected` (C++23)**: Use when a function can fail, and you need to return either the successful result or a detailed error type.
    *   **Custom Result Types**: For projects targeting older C++ standards, use a custom variant-based `Result<T, E>` pattern.

### 2. Resource Management: RAII
*   **Zero Raw Delete**: Never manually manage resources using raw pointers, `new`, and `delete`.
*   **RAII Guards**: Wrap every resource (memory, locks, file descriptors, sockets) in an object whose destructor handles the release (e.g., `std::unique_ptr`, `std::shared_ptr`, `std::lock_guard`).
*   This guarantees that resources are released safely when exceptions are thrown or functions exit early.

### 3. Custom Errors
*   When using exceptions, define custom exception classes that inherit from `std::exception` or its subclasses (e.g., `std::runtime_error`).
*   Always catch exceptions by **const reference** (`const std::exception& e`) to prevent object slicing.

---

## 🧪 Unit Testing in C++

### 1. Frameworks
*   Standardize on modern C++ testing frameworks:
    *   **Google Test (gTest)**: Best for large-scale test suites requiring parameterized testing.
    *   **Catch2**: Excellent for quick setup and expressive, BDD-style testing.

### 2. Mocking
*   Use **Google Mock (gMock)** or **trompeloeil** to create mock implementations of abstract classes (interfaces).
*   Prefer virtual interfaces and Dependency Injection over global state to make testing straightforward.

### 3. Assertion Styles
*   ** gTest Assertions**:
    *   Use `EXPECT_*` (e.g., `EXPECT_EQ`) for non-fatal assertions that allow the test to continue and report further failures.
    *   Use `ASSERT_*` (e.g., `ASSERT_NE`) only if the failure makes subsequent test execution impossible or dangerous (e.g., asserting a pointer is not null before dereferencing it).
