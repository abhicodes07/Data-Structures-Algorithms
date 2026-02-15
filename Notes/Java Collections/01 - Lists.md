---
tags:
  - Java
  - Data-structures
Note Tags: 
Time Created: 10:39 AM
Date Created: February 15, 2026
---
# 🌺 Lists
![](https://raw.githubusercontent.com/catppuccin/catppuccin/main/assets/palette/macchiato.png)

![[Collections.canvas|Collections]]

- The **List interface** in java is a part of the `java.util` package and is a sub-interface of the collection interface. It provides a way to store an ordered collection of elements (known as a sequence). Lists allow for precise control over where elements are inserted and can contain duplicate elements.
- The **List interface** is implemented by several classes in the Java Collection Framework, such as *ArrayList*, *LinkedList*, *Vector*, and *Stack*.

> Key Features
- Order Preservation
- Index-Based Access
- Allows Duplicates

## 🌼 ArrayList
---
- An ArrayList is a resizable array implementation of the List interface. Unlike arrays in Java, which have a fixed size, and **ArrayList can change its size dynamically** as elements are added or removed.
- This flexibility makes it a popular choice when the number of elements in a list isn't known in advance.

*Syntax*
```java
import java.util.ArrayList;
import java.util.List; 

// using parent
List<TYPE> VAR_NAME = new ArrayList<>();

// Using ArrayList class
ArrayList<TYPE> VAR_NAME = new ArrayList<>();

// or using arrays (unmodifiable)
List<TYPE> VAR_NAME = Arrays.asList(item1, item2, item3, ...);

```
### Internal Working of ArrayList
- Unlike a regular array, which has a fixed size, an ArrayList can grow and shrink as elements are added or removed.
- This dynamic resizing is achieved by **creating a new array when the current is full and copying the elements to the new array**.
- When you create an ArrayList, it has an initial capacity/size (default is 10). 
- When we add an element to an ArrayList, the following steps occur
	- Check capacity
	- Resize if necessary
	- Add the element and the size is incremented
- When removing elements:
	- Check Bounds (checks if the index is within the valid range.)
	- Remove the element (after removal, elements to the right of the removed element are shifted one position to the left to fill the gap)
	- Reduce size (size is decremented by 1)
### Methods
```java
ArrayList<Integer> list = new ArrayList<>();
```
- **`list.add()`**: add element.
- **`list.add(index, value)`**: add element on specific index.
- **`list.contains()`** : check the occurrence of element.
- **`list.remove()`** : remove element using both index and value.
- **`list.set(index, value)`** : set a value at particular index.

```java
List<Integer> list = List.of(1, 2, 3, 4, 5);
```
- **`List.of()`** : creates list of immutable objects separated by comma.

### Time Complexity
- Access by index : **O(1)**
- Adding element : **O(n)**
- Removing element : **O(n)**
- Iteration : **O(n)**

# 🖇️Resources
![](https://raw.githubusercontent.com/catppuccin/catppuccin/main/assets/palette/macchiato.png)

- **Source** : 

