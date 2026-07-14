# Chapters 14–16: Refactoring Case Studies

Chapters 14, 15, and 16 of *Clean Code* are hands-on case studies. They do not introduce new theoretical concepts; instead, they demonstrate the practical, iterative process of refactoring real code using the principles discussed in previous chapters.

---

## 📂 Summary of Case Studies

### Chapter 16: Refactoring `SerialDate`
This chapter covers the refactoring of a large utility class, `SerialDate` (from the JFreeChart library), which handles dates and days.
* **The Refactoring Process**:
  * Cleaning up compile-time constants (replacing magic numbers with enums).
  * Fixing accessibility modifiers (moving public variables to private/protected).
  * Correcting logical errors and memory leaks found during test suite construction.
  * Moving helper methods to their correct classes.
* **Key Lesson**: Large legacy classes often have hidden dependencies, structural flaws, and poor cohesion. Writing a comprehensive unit test suite is a prerequisite before attempting any refactoring of legacy code.
