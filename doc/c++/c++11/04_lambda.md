# Lambda Expressions
You can now write anonymous, inline functions right where you need them. This made working with standard library algorithms (like std::sort or std::count_if) vastly easier and more readable.

# Benifits

# Drawbacks

# Example
```cpp
std::vector<int> v = {4, 1, 3, 5, 2};

// Sorting in descending order using a quick lambda
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```