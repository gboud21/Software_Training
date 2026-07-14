# Chapter 13: Concurrency

"Objects are abstractions of processing. Threads are abstractions of schedule." — James O. Coplien.
Writing clean concurrent programs is hard. This chapter details principles and patterns for keeping concurrent code clean.

---

## 🔑 Key Concepts

### 1. Why Concurrency?
Concurrency is a decoupling strategy. It helps us decouple *what* gets done from *when* it gets done.
* In web applications, it improves throughput by handling multiple requests concurrently.
* In embedded systems, it allows handling asynchronous events (e.g., interrupts, sensor readings) without blocking the main execution path.

### 2. Concurrency Myths vs. Realities
* **Myth**: Concurrency always improves performance.
  * *Reality*: It only improves performance when there is significant wait time or CPU sharing that can be parallelized.
* **Myth**: Design does not change when writing concurrent programs.
  * *Reality*: The design of concurrent systems can be dramatically different from single-threaded systems, requiring careful lock management and shared-state design.
* **Myth**: Concurrency bugs are easy to reproduce.
  * *Reality*: Concurrency bugs (data races, deadlocks) are highly non-deterministic and hard to reproduce.

### 3. Concurrency Defense Principles
* **Single Responsibility Principle (SRP)**: Keep concurrent code separate from non-concurrent code. Limit thread-management logic to a dedicated module.
* **Limit the Scope of Data**: Use encapsulation and strictly limit access to shared data. Minimize the size of critical sections (synchronized blocks).
* **Use Copies of Data**: Avoid sharing data altogether by copying objects or passing read-only data structures.
* **Threads Should Be as Independent as Possible**: Partition data so that each thread operates on its own subset of data, requiring no synchronization.

### 4. Know Your Execution Models
* **Producer-Consumer**: Producers place work in a queue; consumers take work from the queue. The queue is a bound resource.
* **Readers-Writers**: Readers read shared data; writers modify it. Balance is needed to prevent starvation of either readers or writers.
* **Dining Philosophers**: A classic model for resource contention and deadlock prevention.

### 5. Deadlock Prevention
Deadlock occurs when four conditions are met. To prevent deadlock, we must break at least one of these conditions:
1. **Mutual Exclusion**: Resources can only be used by one thread at a time.
2. **Hold and Wait**: A thread holding a resource can request additional resources.
3. **No Preemption**: A resource cannot be forcibly taken from a thread.
4. **Circular Wait**: Thread A waits for Thread B, which waits for Thread A.
