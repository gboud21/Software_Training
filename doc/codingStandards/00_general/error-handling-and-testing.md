# Error Handling and Testing Standards

This document defines general standards for robust error propagation, defensive programming, and writing reliable unit tests.

---

## ⚠️ Error Handling & Defensive Programming

### 1. Exceptions vs. Return Codes
*   **Prefer Exceptions**: When using high-level languages that support them, prefer throwing exceptions over returning numeric error codes. This separates the "happy path" from error-handling paths.
*   *Note: For safety-critical embedded systems (e.g., C/C++), exceptions are often prohibited due to runtime size and timing unpredictability. Refer to the [01_embedded/](file:///home/gboud21/code/Software_Training/doc/codingStandards/01_embedded/) guidelines for domain-specific overrides.*

### 2. Null Safety
*   **Do Not Return Null**: Never return `null` (or a null pointer) from a method if it can be avoided. Return empty collections, default objects, or use `Option`/`Optional` wrappers instead.
*   **Do Not Pass Null**: Avoid passing `null` into methods. It forces code to be littered with defensive null-checking boilerplate.
*   **Special Case Pattern**: If a query returns no result, return a representation of a "null" object that responds safely to the interface, avoiding null check logic at the call site.

### 3. Assertions
Use assertions to enforce critical invariants and assumptions:
*   **Preconditions & Postconditions**: Verify function parameters at the entry point and output values before returning.
*   **No Side Effects**: Assertions must be side-effect free. They must not alter the system state, as they may be compiled out in production builds.

---

## 🧪 Unit Testing

Unit tests are as important as production code. They must be maintained with the same level of care, organization, and cleanliness.

### 1. The F.I.R.S.T. Principles
All unit tests must adhere to these five rules:
*   **F - Fast**: Tests must run quickly (in milliseconds) so developers can run them continuously during development.
*   **I - Independent**: Tests must not depend on the state or execution order of other tests. They must run reliably in isolation.
*   **R - Repeatable**: Tests must produce identical results in any environment (local machine, CI/CD server, or offline).
*   **S - Self-Validating**: Tests must have a binary outcome (pass or fail) requiring no manual log analysis.
*   **T - Timely**: Tests should be written just before the production code they verify (Test-Driven Development).

### 2. Test Structure: Given-When-Then (Given-When-Then)
Each test should be structured into three clear phases:
1.  **Given (Build)**: Arrange the necessary inputs, mocks, and state.
2.  **When (Operate)**: Act upon the target method or unit under test.
3.  **Then (Check)**: Assert the expected results or verify side-effects.

### 3. Focus (One Concept per Test)
*   Do not bundle multiple unrelated checks into a single test function.
*   Each test should verify **one specific concept** or behavior. If a test fails, it should be immediately obvious what requirement was violated.
