# Chapter 2: Meaningful Names

This chapter focuses on the importance of naming variables, functions, classes, and packages. Names should reveal intent, avoid disinformation, and be easy to read and search.

---

## 🔑 Key Concepts

### 1. Use Intention-Revealing Names
The name of any variable, function, or class should answer three questions: why it exists, what it does, and how it is used. If a name requires a comment, then the name does not reveal its intent.
* **Bad**: `int d; // elapsed time in days`
* **Good**: `int elapsedTimeInDays;`

### 2. Avoid Disinformation
Do not leave false clues that obscure the meaning of code.
* Do not refer to a grouping of accounts as an `accountList` unless it is actually a `List`. Use `accounts` or `accountGroup` instead.
* Avoid using names that vary only slightly (e.g., `XYZControllerForEfficientHandlingOfStrings` vs. `XYZControllerForEfficientStorageOfStrings`).

### 3. Make Meaningful Distinctions
Avoid lazy suffixing or numbering just to satisfy the compiler.
* Do not use noise words like `a`, `an`, `the`, `Info`, or `Data` if they do not add meaning.
* **Bad**: `getActiveAccount()`, `getActiveAccounts()`, `getActiveAccountInfo()` (what is the difference?).

### 4. Use Pronounceable & Searchable Names
* If you can't pronounce a name, you can't discuss it without sounding silly.
* Single-letter names and numeric constants are hard to find in a large codebase. Use searchable names for global or class-scope variables. Single-letter names should only be used as local variables inside short loops (e.g., `i`, `j`).

### 5. Avoid Encodings
Do not encode type or scope information into names.
* **Hungarian Notation**: Modern IDEs render type information; prefixes like `m_` or `f_` are unnecessary noise.
* **Interfaces and Implementations**: Do not prefix interfaces with `I` (e.g., `IShapeFactory`). If you must distinguish, suffix the implementation (e.g., `ShapeFactoryImp`).

### 6. Parts of Speech
* **Classes**: Class names should be nouns or noun phrases (e.g., `Customer`, `WikiPage`, `Account`). Avoid verbs.
* **Methods**: Method names should be verbs or verb phrases (e.g., `postPayment()`, `deletePage()`, `save()`). Accessors, mutators, and predicates should be prefixed with `get`, `set`, and `is` (e.g., `getName()`, `isReady()`).

### 7. One Word per Concept
Pick one word for one abstract concept and stick with it. 
* Do not mix `fetch`, `retrieve`, and `get` for the same operation across different classes.
* Do not mix `controller`, `manager`, and `driver` interchangeably.
