# Smart Pointers
In C++03 developers manually manged and accessed memory through the use of pointers, now known as Raw Pointers. Pointers are a type of variable that contain an address in memory that an object is stored at. A pointer that contains no address is known as a NULL pointer. The allocation and deallocation of memory, as well as, the cleanup of pointers was the responsibility of the developer. The manual management introduces infinite opportunities for bugs in C++ applications that often time take the form of either crashes, or vulnerabilities within the software.

C++11 enhanced memory safety through the introduction of Smart Pointers. Smart pointers take some of the honess of memory management off of the developer and instead builds it into the language itself by automatically managing memory cleanup. The introduction of smart pointers mostly eliminated the need to manually call **new** and **delete**, drastically reducing memory leaks within a C++ application. C++11 introudced the following Smart Pointers:
- std::unique_ptr -- Used for exculsive ownership of the object. The object pointed to by the Unique Pointer is destroyed when the object goes out of scope.
- std::shared_ptr -- Used for shared ownership of an object. A reference counter is built inside the object. The reference counter is incremented when the pointer is shared to a new scope. The reference counter is decremented when a pointer goes out of scope. The object pointed to by the Shared Pointer is destroyed when the reference counter reaches 0.

# Benefits
- Compressed syntax makes it easier to read
- Less error prone for read operations where you want to access every element

# Drawbacks
- Can't be used in all scenarios, but to be fair, it is not intended to be
- Will iterate over all elements for the colleciton without additional logic specified.
- Modifying the colleciton being iterated over or the current iterator can still cause the same issues as using For Loops with iterators. Particularly when removing elements from the collection.

# Example
````cpp
#include <memory>
void doSomething() {
    // Memory is automatically freed when the function ends!
    std::unique_ptr<int> myPtr(new int(10)); 
}
```