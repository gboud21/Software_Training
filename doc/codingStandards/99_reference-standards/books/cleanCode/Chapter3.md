# Chapter 3: Functions

Functions are the first line of organization in any program. This chapter outlines how to write functions that are easy to read, understand, and maintain.

---

## 🔑 Key Concepts

### 1. Small!
The first rule of functions is that they should be small. The second rule is that they should be *smaller than that*.
* Functions should rarely be longer than 20 lines, and ideally under 10.
* Blocks within `if`, `else`, `while`, and other control flow statements should be one line long—usually a function call.

### 2. Do One Thing
**A function should do one thing. They should do it well. They should do it only.**
* If a function does only those steps that are one level of abstraction below the stated name of the function, then the function is doing one thing.
* If you can extract another function from it with a name that is not merely a restatement of its implementation, it is doing more than one thing.

### 3. One Level of Abstraction per Function
Mixing levels of abstraction within a function is always confusing.
* **High level**: `getHtml()`
* **Intermediate level**: `String pagePathName = PathParser.render(pagePath);`
* **Low level**: `.append("\n")`

### 4. Reading Code from Top to Bottom: The Stepdown Rule
We want the code to read like a top-down narrative. Every function should be followed by those at the next level of abstraction so we can read the program, cascading down the list of functions.

### 5. Function Arguments
The ideal number of arguments for a function is zero (niladic). Next comes one (monadic), followed closely by two (dyadic). Three arguments (triadic) should be avoided where possible. More than three (polyadic) requires very special justification.
* **Arguments make testing hard**: Testing every combination of arguments is mathematically complex.
* **Output arguments**: Avoid output arguments. If a function must change the state of something, let it change the state of its owning object.

### 6. Have No Side Effects
Side effects are lies. Your function promises to do one thing, but it also does other, hidden things (e.g., modifying class-scope variables, changing system globals).
* This leads to temporal couplings and order-of-execution dependencies.

### 7. Command Query Separation
Functions should either do something or answer something, but not both.
* **Bad**: `if (set("username", "unclebob")) ...` (does this check if it was set, or set it and return status?)
* **Good**:
  ```java
  if (attributeExists("username")) {
      setAttribute("username", "unclebob");
  }
  ```

### 8. Prefer Exceptions to Returning Error Codes
Returning error codes leads to deeply nested `if` statements and forces the caller to deal with the error immediately.
* **Separate Try/Catch Blocks**: Extract the bodies of `try` and `catch` blocks into functions of their own to isolate error processing from normal control flow.
