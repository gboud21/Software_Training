# Auto Keyword
In C++03 developers would need to manually specify the type of every local variable. While more explicit, this does slightly increase costs to maintain due to the fact that any changes to variable names, or function signatures could drive additional development costs due to the compiler errors that will be generated due to the changing type. In addition, long type names can also lead to more verbose code that in some ways decreases readability.

C++11 added a new keyword to handle __Type Inference__. Type Inference offloads the assignment of types to the compiler. In order to use this new feature, the developer simply needs to specify **auto** in the place that a type would be specified.

# Benefits
- When using an API, it is possible for the API to change without impacting your code.
- Code readability can be improved if you are using types with long names, or using namespaces. It can effectively replace the use of type aliases.
- Can be useful for templates, but at this point you are likely in highly complex code.

# Drawbacks
- When using an API, if the API changes then it may allow the code to continue to compile, but could induce a runtime error if the type changes to something that is compatible, but has behavioral differences.
- Code inherently becomes less explicit since the true type is being masked by auto. This can be mitigate through the use of code plugins such as those used in VS Code.

# Example
````cpp
int main(){
    // This will automatically make myLong a "long" type
    // equivalent to long myLong = 5L;
    auto myLong = 5L;
    return 0;
}
```