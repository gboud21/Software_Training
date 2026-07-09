# Hash Maps
- Key Value pair data structure
- Executes an algorithm to convert the key into an integer index into the data set
- Two keys that calculate into the same hash cause a collision. The collision resolution strategy is dependent on the hash map implementation, but linked lists are commonly used to resolve the keys

## Use Cases
- 

## Strengths
- Constant lookup time

## Weakness
- Can be misleading, small hash maps with complex lookups can actually take longer than array search

## Patern
1. Storing something
2. Looking something up
3. Updating/initializing values

- When optimizing ask: "What can I store to avoid searching later"
- "Have I seen XXX before"
### Frequency Map
- Go through a list, keeping track of how many of something there is

```python
my_map = {}

for item in data:
    if item not in my_map:
        my_map[item] = 1
    else:
        my_map[item] += 1
```

```cpp

```