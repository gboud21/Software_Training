# Strings
- In a lot of senses they are basically arrays of characters
- Where they are stored is language depedent
    - Most times it's actually a pointer with some metadata to the heap
    - Post C++17 strings of less than 15 characters are stored on the stack for small string optimization
- Generally string patterns revolve around smart windowing and access patterns

## Use Cases
- Find the longest substring without repeating characters
- Check if two strings are anagrams
- return all substrings that match a pattern

## Strengths

## Weaknesses
- Misleading due to string concatenation potentially causing new strings to be temporarily allocated
```python
# This actually has O(n^2) complexity due to the allocation of new strings every time you perform result += char
# Some languages may be a little different (ie C++ will gradually grow the string)
result = ""
for char in chars:
    result += char
```