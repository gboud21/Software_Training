# Chapter 6: Objects and Data Structures

This chapter explains the fundamental differences between objects and data structures, and how mixing them leads to architectural issues.

---

## 🔑 Key Concepts

### 1. Data Abstraction
Hiding implementation details is not just about putting variables behind getters and setters. It is about presenting abstract interfaces that allow users to manipulate the *essence* of the data without knowing its implementation.
* **Bad (Concrete)**:
  ```java
  public interface Point {
      double getX();
      double getY();
      void setCartesian(double x, double y);
  }
  ```
* **Good (Abstract)**:
  ```java
  public interface Point {
      double getR();
      double getTheta();
      void setPolar(double r, double theta);
  }
  ```

### 2. Objects vs. Data Structures
* **Objects**: Hide their data behind abstractions and expose functions that operate on that data.
* **Data Structures**: Expose their data directly and have no meaningful functions.
* **The Fundamental Duality**:
  * **Procedural code (using data structures)**: Makes it easy to add new functions without changing existing data structures. However, it makes it hard to add new data structures (as all functions must change).
  * **OO code (using objects)**: Makes it easy to add new classes without changing existing functions. However, it makes it hard to add new functions (as all classes must implement the new function).

> [!TIP]
> Use Objects when you expect to add new types/classes frequently. Use Data Structures (and procedural code) when you expect to add new behaviors/functions frequently.

### 3. The Law of Demeter
A method $f$ of a class $C$ should only call methods of:
* Class $C$ itself.
* An object created by $f$.
* An object passed as an argument to $f$.
* An object held in an instance variable of $C$.

The method should **not** call methods on objects returned by any of the allowed calls. In other words, **"talk to friends, not to strangers."**
* **Train Wrecks**: Deep chains of method calls like `ctxt.getOptions().getScratchDir().getAbsolutePath();` violate the Law of Demeter if these are objects. If they are simple data structures, they do not violate the law because they are just exposing data.

### 4. DTOs and Active Records
* **Data Transfer Objects (DTOs)**: Classes with public variables and no functions. They are used for translating raw data (e.g., database records, socket streams) into application structures.
* **Active Records**: DTOs with navigation methods (e.g., `save()`, `find()`). Treat these as data structures, not objects. Do not put business logic in them.
