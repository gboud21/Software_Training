# Chapter 8: Boundaries

We seldom control all the software in our systems. Sometimes we buy third-party packages or use open-source libraries. This chapter is about how to clean-wrap these boundaries to protect our core system.

---

## 🔑 Key Concepts

### 1. Using Third-Party Code
Providers of third-party packages strive for broad applicability so they can appeal to many users. Users, on the other hand, want an interface that is focused on their specific needs. This tension can lead to problems at the boundary.
* **Wrap Map/Collections**: If you use a generic `Map` interface, you expose all of its methods (like `clear()`), which you might not want users to call. Wrap the collection in a class that only exposes the methods your application actually needs.

### 2. Exploring and Learning Boundaries
Instead of writing production code directly using a third-party library, write **learning tests**.
* Learning tests are simple unit tests where you call the third-party API the way you expect to use it in your application.
* This helps verify your understanding of the library and catches breaking changes when the library is upgraded.

### 3. Using Code that Does Not Yet Exist
Sometimes we need to interface with a system component that hasn't been built or defined yet.
* Define an **adapter interface** that represents what *we* want the interface to look like.
* Write a mock implementation of this interface for our own testing.
* Once the external team delivers the API, write an implementation class that bridges our adapter interface to their API. This isolates the rest of our application from changes in their design.

### 4. Clean Boundaries
* Code at the boundaries needs clear separation and tests that define expectations.
* Avoid letting third-party details leak into the core of your application. Wrap them or use an Adapter to minimize the points of contact.
