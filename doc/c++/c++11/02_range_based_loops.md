# Ranged Based Loops
In C++03 developers had a few different options available to implement looping behaviors:
- For Loops
- While/Do While Loops
For Loops allowed some behavior to be executed at the end of the for loop to move the index of the element being operated on to the next index. In many cases this took the form of some mathematical operation such as incrementing an integer to access the next index in an array. Alternatively for more complex data structures iterators were defined that encapsulated the element being analyzed as well as the behavior to advance to the next element within the data structure. While a step in the correct direction, iterators have been known to cause confusion, particularly for junior developers.

C++11 added range based for loops to allow cleaner iteration over collections. 

# Benefits
- Compressed syntax makes it easier to read
- Less error prone for read operations where you want to access every element

# Drawbacks
- Can't be used in all scenarios, but to be fair, it is not intended to be
- Will iterate over all elements for the colleciton without additional logic specified.
- Modifying the colleciton being iterated over or the current iterator can still cause the same issues as using For Loops with iterators. Particularly when removing elements from the collection.

# Example
````cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
for (auto number : numbers) {
    std::cout << number << "\n";
}

// Prints out
// 1
// 2
// 3
// 4
// 5
```