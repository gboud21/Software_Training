# Functions and Classes Standards

This document defines the architectural limits and design practices for functions (methods) and classes.

---

## 📞 Functions

Functions are the primary unit of behavior. They must be kept simple, focused, and readable.

### 1. Function Size
*   **Line Limit**: Functions must be small. A standard function should fit on a single screen without scrolling, ideally **under 20 lines** of code. 
*   **Indentation Limit**: Functions should not exceed **two levels of nesting** (e.g., nested `if` inside a `for` loop). Deep nesting indicates that logic needs to be extracted into helper functions.

### 2. Do One Thing (Single Responsibility)
*   A function must do **one thing**, do it well, and do it only.
*   **Abstraction Level**: All statements within a function must reside at the same level of abstraction. Do not mix high-level business logic (e.g., `processTransaction()`) with low-level details (e.g., `.append("\n")`) in the same function.

### 3. Function Arguments (Arity)
Keep the number of function parameters as low as possible:
*   **Ideal (0-2 parameters)**: Highly readable and easy to unit test.
*   **Maximum (3 parameters)**: Acceptable if absolutely necessary.
*   **Polyadic (4+ parameters)**: Banned. Wrap the arguments in a configuration object, structure, or class.
*   **No Selector/Flag Arguments**: Do not pass booleans or enums as parameters to change function behavior (e.g., `render(boolean isSuite)`). This proves the function is doing more than one thing. Split it into two functions instead (e.g., `renderSuite()` and `renderSingle()`).

### 4. Command-Query Separation (CQS)
Functions must either **do something** (command) or **answer something** (query), but never both.
*   A function should not return a value if it modifies the state of the system, and it should not modify the state of the system if it returns a value.
*   ❌ **Bad**: `if (set("username", "bob"))` (sets state and returns success status)
*   ✅ **Good**: 
    ```java
    if (!attributeExists("username")) {
        setAttribute("username", "bob");
    }
    ```

---

## 🏛️ Classes

Classes are the primary unit of encapsulation and structure.

### 1. The Single Responsibility Principle (SRP)
*   A class must have **one, and only one, reason to change**.
*   Do not bundle unrelated responsibilities into a single class (e.g., a `User` class should not handle both database persistence and password validation).

### 2. Cohesion
*   A class should have a small number of instance variables, and most of its methods should manipulate one or more of those variables.
*   **High Cohesion**: When methods and variables are highly interdependent, the class acts as a single, unified module.
*   **Low Cohesion**: If a subset of methods only interacts with a subset of variables, it is a strong sign that the class should be split into two or more smaller classes.

### 3. Organizing for Change
*   **Open/Closed Principle (OCP)**: Design classes so that behavior can be extended without modifying the existing, verified source code (e.g., via subclassing or interfaces).
*   **Dependency Inversion Principle (DIP)**: High-level policy classes must not depend on low-level detail classes. Both must depend on abstractions (interfaces).
