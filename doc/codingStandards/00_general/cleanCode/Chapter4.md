# Chapter 4: Comments

"Don't comment bad code—rewrite it." — Brian W. Kernighan and P. J. Plaugher.
This chapter covers the philosophy of comments, when they are useful, and when they represent failure.

---

## 🔑 Key Concepts

### 1. Comments Do Not Make Up for Bad Code
The proper use of comments is to compensate for our failure to express ourselves in code. 
* Code changes and evolves; comments often do not. The older a comment is, the more likely it is to be outright false.
* Clear and expressive code with few comments is far superior to cluttered and complex code with many comments.

### 2. Good Comments
Some comments are necessary or beneficial:
* **Legal Comments**: Copyright and authorship statements at the top of a file.
* **Informative Comments**: Explaining the format of a return value (e.g., regex pattern format).
* **Explanation of Intent**: Explaining *why* a particular decision was made (e.g., choosing a specific sorting algorithm for a real-time constraint).
* **Clarification**: Translating an obscure argument or return value from a library you cannot alter.
* **Warning of Consequences**: Warning other developers not to run a test because it takes too long, or not to invoke a method due to side-effects.
* **TODO Comments**: Explaining why a feature is not yet completed and what needs to be done.
* **Amplification**: Emphasizing the importance of something that might otherwise seem inconsequential.

### 3. Bad Comments (Noise & Clutter)
Most comments fall into this category. They are often signs of lazy programming:
* **Mumbling**: Writing a comment just because you feel you have to, without thinking through its clarity.
* **Redundant Comments**: Restating what the code already clearly states.
* **Misleading Comments**: Comments that are not accurate or are out of date.
* **Mandatory Comments**: Rules that require Javadocs/Doxygen for every single function, leading to useless boilerplate.
* **Journal Comments**: Log entries of changes at the top of the file (use Git/source control instead).
* **Noise Comments**: Useless statements like `// default constructor` or `// the name variable`.
* **Position Markers**: Banners like `// ---- Actions ----` should be used rarely, as they lose their visual impact.
* **Commented-Out Code**: Never comment out code. Delete it! Version control will remember it.
