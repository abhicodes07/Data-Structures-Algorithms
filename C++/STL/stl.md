# STL Libraries in C++

**STL** Libraries are divided into four major parts:

1. Algorithms
2. Containers
3. Functions
4. Iterators

## Containers

---

C++ containers are part of the Standard Template Library (STL) and provide ways to store and manage collections of data efficiently. They offer different structures suited to various use cases, enabling programmers to handle data dynamically and effectively.

### Types of C++ Containers

C++ containers are generally classified into three main categories:

1. Sequential Containers – Store elements in a linear fashion.

- `vector` – Dynamic array with fast random access.
- `deque` – Double-ended queue with fast insertions/removals at both ends.
- `list` – Doubly-linked list allowing efficient insertions and deletions anywhere.
- `array` – Fixed-size array with constant-time access.
- `forward_list` – Singly-linked list optimized for sequential access.

2. Associative Containers – Maintain elements in a structured way, often sorted.

- `set` – Stores unique elements in sorted order.
- `multiset` – Similar to set, but allows duplicate elements.
- `map` – Stores key-value pairs in sorted order.
- `multimap` – Similar to map, but allows duplicate keys.

3. Unordered Containers – Store elements using a hash table for fast lookups.

- `unordered_set` – Stores unique elements in an unsorted, hashed manner.
- `unordered_multiset` – Similar to unordered_set, but allows duplicates.
- `unordered_map` – Stores key-value pairs using hashing.
- `unordered_multimap` – Similar to unordered_map, but allows duplicate keys.

# Maps

In C++, the map is a container provided by the Standard Template Library (STL) that stores elements in key-value pairs. It is an ordered associative container, which means:

- Each element is a pair of key and value.
- **_Keys are unique._**
- Elements are stored in a sorted order based on the key (by default, in ascending order using < operator).

| Feature                       | Description                                 |
| ----------------------------- | ------------------------------------------- |
| **Key uniqueness**            | No duplicate keys allowed                   |
| **Sorted order**              | Sorted by keys using `operator<`            |
| **Underlying data structure** | Self-balancing BST (usually Red-Black Tree) |
| **Time complexity**           | O(log n) for insertion, deletion, search    |

- Map vs Unordered Map

| Feature             | `map`              | `unordered_map`          |
| ------------------- | ------------------ | ------------------------ |
| **Ordering**        | Sorted (by key)    | No order                 |
| **Time complexity** | O(log n)           | O(1) average, O(n) worst |
| **Underlying DS**   | Red-Black Tree     | Hash table               |
| **Use case**        | When order matters | When fast access matters |
