# Chapter 5: Formatting

Code formatting is about communication. Communication is the professional developer's first order of business. A well-formatted codebase is easier to read, navigate, and debug.

---

## 🔑 Key Concepts

### 1. Vertical Formatting
Think of a source file like a newspaper article. It should read top-to-bottom, starting with high-level summaries and ending with implementation details.
* **File Size**: Most files should be between 200 and 500 lines. Smaller files are easier to grasp.
* **Vertical Openness**: Use blank lines to separate logical concepts (e.g., between functions, imports, and variables).
* **Vertical Density**: Code that is tightly related should appear vertically close (no blank lines between closely associated variable declarations).
* **Vertical Distance**:
  * **Variable Declarations**: Declare variables close to their usage (local variables). Instance variables should be declared at the top or bottom of the class depending on language conventions.
  * **Dependent Functions**: If function `A` calls function `B`, they should be vertically close, with `A` above `B`.
  * **Conceptual Affinity**: Code with strong conceptual affinity (e.g., overloaded methods) should be grouped together.

### 2. Horizontal Formatting
* **Line Width**: Keep lines short. Robert Martin recommends a limit of 100-120 characters per line.
* **Horizontal Openness and Density**:
  * Use spaces to associate things that are closely related, and dissociate things that are weakly related (e.g., spaces around assignment operators: `int lineCount = 0;`).
  * No spaces between function names and opening parentheses: `calculatePage(width);`.
  * Put spaces between arguments to highlight distinction: `doSomething(a, b, c);`.
* **Indentation**: Indentation represents the hierarchy of code (classes, methods, control blocks). Never skip indenting short `if` statements or loops.
* **Dummy Loops**: If a loop must have an empty body, format it with a visible semicolon on a separate indented line, or use empty curly brackets `{}`.
