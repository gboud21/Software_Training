# Chapter 11: Systems

"Complexity kills. It sucks the life out of developers, it makes products difficult to plan, build, and test." — Ray Ozzie.
This chapter discusses how to maintain cleanliness and abstraction at the system-wide architecture level.

---

## 🔑 Key Concepts

### 1. Separate Constructing a System from Using It
Software systems should separate the startup process (when objects are constructed and dependencies are wired together) from the runtime logic (when the system is running).
* **The Main Separation Pattern**: Move all construction logic to `main` (or a dedicated initialization module). The application simply uses the objects passed to it, knowing nothing about how they were constructed.
* **Dependency Injection (DI)**: Inversion of Control (IoC) delegates construction to an external mechanism, passing dependencies via constructors or setters.

### 2. Scaling Up
It is a myth that we can get systems "right the first time." Instead, we should build systems that can scale and evolve.
* Architectures can grow incrementally if we maintain clean separation of concerns.
* **Cross-Cutting Concerns**: Aspects like security, transaction management, and logging can bleed into the domain logic. We can use techniques like Aspect-Oriented Programming (AOP), Proxies, or Decorators to separate these concerns from our core business logic.

### 3. Optimize Decision Making
Modularity and separation of concerns allow us to decentralize management and optimize decision-making. It is best to **postpone decisions until the last possible moment**. This is not lazy; it allows us to make decisions with the maximum amount of information and customer feedback.

### 4. Use Standards Wisely
Standards make it easier to reuse ideas and find people with relevant skills. However, you should not follow a standard blindly just because it exists. Ensure the standard actually adds value and fits the scope of your system.
