# Error Handling and Testing Standards

This directory defines standards for robust error propagation, defensive programming, and writing reliable unit tests. 

While core design philosophies are universal, implementation details are highly dependent on language features. This document establishes the **common, language-agnostic standards**, while language-specific patterns are detailed in the sub-documents below.

---

## 🔗 Language-Specific Standards

Select the specific language standards below for detailed implementation patterns:

*   [Error Handling & Testing in C](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/c.md) (Status codes, out parameters, `goto cleanup` pattern)
*   [Error Handling & Testing in C++](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/cpp.md) (RAII, exception safety levels, expected/optional types)
*   [Error Handling & Testing in Rust](file:///home/gboud21/code/Software_Training/doc/codingStandards/00_general/error-handling-and-testing/rust.md) (Result/Option types, panic avoidance, inline testing)

---

## ⚠️ Common Error Handling Principles

Regardless of language, all code must follow these foundational defensive programming patterns:

### 1. Null Safety
*   **Do Not Return Null**: Avoid returning raw null pointers or references to signify empty or missing states. Use wrapper option types (e.g., `std::optional` in C++, `Option` in Rust) or empty structures.
*   **Do Not Pass Null**: Avoid passing raw null values into functions as parameters. Passing null forces call sites and implementations to write defensive boilerplate checks.
*   **Special Case/Null Object Pattern**: Instead of returning null when an entity is missing, return a dummy object that conforms to the expected interface but does nothing (e.g., a `NullLogger` that simply ignores messages).

### 2. Assertions
Use assertions to document and enforce system invariants at development and testing time:
*   **Preconditions & Postconditions**: Assert that function arguments are valid before processing, and verify output constraints before returning.
*   **No Side Effects**: Assertions must never mutate the program state, as they are typically disabled or compiled out in release/production builds.
*   **Safety Boundaries**: Assertions are not a replacement for runtime recovery. Only use assertions for logical bugs that represent programmer errors, never for runtime errors (like connection dropouts).

---

## 🧪 Common Unit Testing Principles

Unit tests are production code. They must be maintained with the same level of care, formatting, and reviews as the application source.

### 1. The F.I.R.S.T. Rules
Every unit test must adhere to the following properties:
*   **F - Fast**: Tests must run quickly (in milliseconds) so developers can execute the test suite continuously.
*   **I - Independent**: Tests must not depend on the execution state or order of other tests. Any test must be able to run and pass in isolation.
*   **R - Repeatable**: Tests must execute identically in any environment (local host, container, or CI runner) without relying on external real-world resources (e.g., databases or networks).
*   **S - Self-Validating**: Tests must have a binary pass/fail output requiring no manual inspection of log output.
*   **T - Timely**: Tests should be written concurrently with or just prior to (TDD) the production code being written.

### 2. Test Structure: Given-When-Then
Every test body should be visually organized into three distinct, commented phases:
1.  **Given (Build)**: Arrange the environment, inputs, mock expectations, and initial state.
2.  **When (Operate)**: Invoke the specific target action or function under test.
3.  **Then (Check)**: Assert that the return values, state changes, or mock interactions match expectations.

### 3. Concept Focus
*   Test **one concept** per test function.
*   Avoid grouping multiple assertions testing unrelated behaviors in a single test block. This ensures that when a test fails, the root cause is immediately obvious from the test name.
