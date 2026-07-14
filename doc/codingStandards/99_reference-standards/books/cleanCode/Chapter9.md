# Chapter 9: Unit Tests

Unit tests are just as important as production code. They keep our code flexible, maintainable, and reusable. Without tests, every change is a potential bug.

---

## 🔑 Key Concepts

### 1. The Three Laws of TDD (Test-Driven Development)
1. You may not write production code until you have written a failing unit test.
2. You may not write more of a unit test than is sufficient to fail, and not compiling is failing.
3. You may not write more production code than is sufficient to pass the currently failing test.

### 2. Keeping Tests Clean
Test code is not a second-class citizen. It requires the same design, care, and cleanliness as production code. 
* **Dirty tests are worse than no tests**: As production code changes, dirty tests become harder to modify. Eventually, developers discard the test suite altogether, leading to code rot.
* **Readability**: Readability is the most important factor in test code. Make tests expressive, clear, and concise.

### 3. Build-Operate-Check Pattern (Given-When-Then)
A clean test structure typically has three parts:
1. **Build (Given)**: Set up the test data and state.
2. **Operate (When)**: Execute the action or function under test.
3. **Check (Then)**: Assert that the outcome is what was expected.

### 4. One Assert per Test
While not a dogmatic rule, having only a single assert (or a group of highly related assertions targeting a single concept) makes tests much easier to read and debug.
* **Single Concept per Test**: A better rule is that we should test only one concept per test function.

### 5. F.I.R.S.T. Rules
Clean tests follow these five rules:
* **F - Fast**: Tests must run quickly. If they are slow, developers won't run them frequently, and bugs will slip in.
* **I - Independent**: Tests should not depend on each other or run in a specific order. One test's failure shouldn't trigger a cascade of other failures.
* **R - Repeatable**: Tests must be repeatable in any environment (production, local, or offline).
* **S - Self-Validating**: Tests must have a boolean output (pass or fail). You shouldn't have to read a log file to determine if a test passed.
* **T - Timely**: Unit tests should be written *just before* the production code that makes them pass.
