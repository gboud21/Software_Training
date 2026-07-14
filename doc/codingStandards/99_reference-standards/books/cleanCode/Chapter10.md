# Chapter 10: Classes

This chapter focuses on the clean organization, size, and cohesion of classes.

---

## 🔑 Key Concepts

### 1. Class Organization
Following standard Java/C++ conventions, a class should be organized in this order:
1. Public static constants.
2. Private static variables.
3. Private instance variables.
4. Public functions.
5. Private utility functions (placed immediately after the public function that calls them).

* **Encapsulation**: We like to keep our variables and utility functions `private`, but we are not fanatical about it. Sometimes we make them `protected` or package-private so they can be accessed by tests. However, loosening encapsulation should always be a last resort.

### 2. Classes Should Be Small!
Like functions, classes should be small.
* With functions, we measure size by counting lines. With classes, we measure size by counting **responsibilities**.
* If a class name contains words like "And", "Or", "If", or "But", it likely has too many responsibilities.
* **Single Responsibility Principle (SRP)**: A class or module should have one, and only one, *reason to change*.

### 3. Cohesion
Classes should have a small number of instance variables. Each method of a class should manipulate one or more of those variables.
* A class in which each variable is used by each method is highly cohesive.
* When cohesion is high, it means that the methods and variables of the class are co-dependent and hang together as a logical whole.
* **Maintaining Cohesion Results in Many Small Classes**: If you find that a subset of methods only uses a subset of instance variables, it is a strong sign that you should split those variables and methods into a new class.

### 4. Organizing for Change
In a clean system, we organize our classes to reduce the risk of change.
* **Open/Closed Principle (OCP)**: Classes should be open for extension but closed for modification. We restructure classes to introduce interfaces and subclasses so we can add new behavior without editing existing, working classes.
* **Dependency Inversion Principle (DIP)**: Classes should depend on abstractions, not on concrete details. Use interfaces to isolate classes from the implementation details of external systems.
