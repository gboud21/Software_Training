# Chapter 17: Smells and Heuristics

This chapter serves as a master reference catalog of "code smells" and heuristics. These are signs that something is wrong with the design or implementation of the code.

---

## 👃 The Code Smells Catalog

### 1. Comments
* **C1: Inappropriate Information**: Comments should contain only technical information (not meta-data, author logs, or general banter).
* **C2: Obsolete Comment**: Comments that are no longer true should be deleted immediately.
* **C3: Redundant Comment**: Comments that say no more than the code does.
* **C4: Poorly Written Comment**: Comments that are hard to read or understand.
* **C5: Commented-Out Code**: Code that is commented out should be deleted.

### 2. Environment
* **E1: Build Requires More Than One Step**: Building a project should be a single simple command (e.g., `make`, `mvn clean install`, `cargo build`).
* **E2: Tests Require More Than One Step**: Running unit tests should be a single command.

### 3. Functions
* **F1: Too Many Arguments**: Functions should have as few arguments as possible (ideally zero, max three).
* **F2: Output Arguments**: Avoid modifying arguments passed into a function.
* **F3: Flag Arguments**: Passing boolean flags to functions indicates they do more than one thing. Split them.
* **F4: Dead Function**: Uncalled methods should be deleted.

### 4. General
* **G1: Multiple Languages in One Source File**: Try to keep each file restricted to a single language.
* **G2: Obvious Behavior is Unimplemented**: Follow the Principle of Least Surprise. A function should do exactly what a developer expects based on its name.
* **G3: Incorrect Behavior at the Boundaries**: Write tests to cover boundary conditions (don't rely on intuition).
* **G4: Overridden Safety**: Disabling warnings, compiler checks, or tests is dangerous.
* **G5: Duplication (DRY Principle)**: **Never duplicate code.** Extract common code to functions, classes, or patterns.
* **G6: Code at Wrong Level of Abstraction**: Do not mix high-level policy code with low-level implementation details in the same class/function.
* **G8: Too Much Information**: Keep class interfaces small and clean. Limit scope.
* **G9: Dead Code**: Delete unused variables, unreachable catch blocks, and unused classes.
* **G10: Vertical Separation**: Declare variables and define functions close to where they are used.
* **G11: Inconsistency**: If you do something a certain way, do it that way everywhere.
* **G12: Clutter**: Remove variables that aren't used, functions that aren't called, and comments that add no value.
* **G13: Artificial Coupling**: Don't couple two things that don't depend on each other (e.g., general enums inside specific classes).
* **G14: Feature Envy**: A method of one class should not envy the variables and methods of another class, calling them excessively.
* **G15: Selector Arguments**: Similar to flag arguments—avoid passing arguments that select the behavior of the function.
* **G16: Obscured Intent**: Code should be as expressive as possible. Avoid tricks, magic numbers, and complex syntax.
* **G17: Misplaced Responsibility**: Place code in the location that a reader would naturally expect it to be.
* **G18: Inappropriate Static**: Avoid making methods static unless they do not operate on any instance data.

### 5. Names
* **N1: Choose Descriptive Names**: Make sure names are clear and reveal intent.
* **N2: Choose Names at the Appropriate Level of Abstraction**: Don't use names that imply an implementation (e.g., `SqlUserRepository` is bad if we might switch to Mongo; use `UserRepository`).
* **N3: Use Standard Nomenclature Where Possible**: Use terms that are common in your domain or pattern names (e.g., `Factory`, `Decorator`).
* **N4: Unambiguous Names**: Do not choose names that are easy to misinterpret.
* **N5: Use Long Names for Long Scopes**: The length of a name should relate to the size of its scope.
* **N6: Avoid Encodings**: Avoid prefixes, suffixes, Hungarian notation, etc.

### 6. Tests
* **T1: Insufficient Tests**: A test suite should test everything that can break.
* **T2: Use a Coverage Tool**: Use code coverage tools to find untested paths.
* **T3: Don't Skip Trivial Tests**: They are easy to write and document behavior.
* **T4: An Ignored Test is a Question about an Ambiguity**: Do not ignore/disable tests. Fix the code or update the test.
* **T5: Test Boundary Conditions**: Test negative inputs, overflow cases, null parameters, and empty collections.
* **T6: Exhaustively Test Near Bugs**: Bugs tend to group together. If you find a bug in a function, test that function exhaustively.
