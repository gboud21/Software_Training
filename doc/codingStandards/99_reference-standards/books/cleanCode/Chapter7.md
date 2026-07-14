# Chapter 7: Error Handling

Error handling is important, but if it obscures the logic of the program, it is wrong. Clean code is structured to handle errors gracefully without cluttering the main logic flow.

---

## 🔑 Key Concepts

### 1. Use Exceptions Rather than Return Codes
Return codes force the caller to handle the error immediately, leading to nested checks and fragmented flow. Exceptions separate the "happy path" from the error resolution path.

### 2. Write Your Try-Catch-Finally Statement First
A `try-catch` block defines a transaction. Writing the `try-catch` structure first helps you define what the caller can expect, regardless of what goes wrong.
* It sets the scope for the block and helps maintain the execution invariants.

### 3. Use Unchecked Exceptions
Java's checked exceptions violate the Open/Closed Principle. If you throw a checked exception from a low-level method, every calling method up the stack must be modified to catch it or declare it in its signature, breaking encapsulation.
* Modern consensus (including languages like C#, Rust, and Go) avoids checked exception models.

### 4. Provide Context with Exceptions
Create informative error messages and pass them along with your exceptions. Mention the failed operation and the type of failure.
* Throw exceptions that map to the caller's level of abstraction, rather than passing raw system exceptions up the stack.

### 5. Define the Normal Flow: Special Case Pattern
Do not let exceptional handling derail the primary logic.
* **Special Case Pattern (Null Object Pattern)**: Instead of throwing an exception or returning `null` when a specific condition is not met, return an object that implements the expected interface but does "nothing" or represents the default case.
* This keeps the client code clean of check-for-exceptional-case blocks.

### 6. Don't Return Null & Don't Pass Null
* Returning `null` forces the caller to write null checks. One missing check can lead to a runtime crash (`NullPointerException`). Return empty collections or use Option types instead.
* Passing `null` into methods is even worse. Unless you are calling an API you do not control, avoid passing nulls, as it requires defensive argument checking in every method.
