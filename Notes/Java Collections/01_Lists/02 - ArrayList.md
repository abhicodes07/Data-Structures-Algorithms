---
tags:
  - Java
  - Data-structures
Note Tags: "[[LIST]]"
Time Created: 10:39 AM
Date Created: February 15, 2026
---
# 🌺 ArrayList
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

## 🌼 Internal Working of ArrayList

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

## 🌼 Methods

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

## 🌼 Time Complexity

- Access by index : **O(1)**
- Adding element : **O(n)**
- Removing element : **O(n)**
- Iteration : **O(n)**

# 🌺 Comparator
---
- Comparator is a interface that can be used for custom sorting.
- When we use `list.sort(null)`, by default, it's sorts the ArrayList in *Natural order* i.e., ascending order.
- To sort the elements in custom order or logic we can use **Comparator**.
- Java provides a Functional Interface *Comparator* that implements a *Compare()* method that compares to objects of same type and determines there order.
- To use this interface, we either need to create a class that implements this interface or use a lambda expression.

```java
import java.util.ArrayList;  
import java.util.Arrays;  
import java.util.List;  
import java.util.Collections;  
import java.util.Comparator;  

// create a class that implements Comparator interface
class MyComparator implements Comparator<String> {  

	// descending order
    @Override  
    public int compare(String o1, String o2) {
	    // if this method returns negative, o1 comes before o2
	    // if this method returns positive, o1 comes after o2

		// eg - 5, 3 -> 3 - 5 = -2 (negative) -> 5, 3
		// eg - 3, 5 -> 3 - 5 = 2 (positive) -> 5, 3 
        return o2 - o1;  
    }  
}

public class Arraylist {  
    public static void main(String[] args) {
    
		// Comparator ===================================  
		// by default, sorting in ascending order  
		List<Integer> num = Arrays.asList(4, 3, 7, 2, 1);  
		num.sort(null);  
		System.out.println(num);  
  
		// custom order: implement a class extending  
		// using Comparator functional interface for descending order of numbers  
		num.sort(new MyComparator());  
		System.out.println("Descending using comparator: " + num);

		// using lambda comparator (descending)  
		num.sort((a, b) -> b - a);  
		System.out.println("Descending using comparator (lambda): " + num);
    }
}
```

- The above **`compare(String o1, String o2)`** based on condition that if the function returns a positive value then the order of `o1` and `o2` will be `o2 -> o1` (**o1 comes after o2**) and if it returns a negative value then the order of `o1` and `o2` will be `o1 -> o2` (**o1 comes before o2**) 

- Now if we want the values in descending order we can simply pass: `o2 - o1`.

# 🖇️Resources
![](https://raw.githubusercontent.com/catppuccin/catppuccin/main/assets/palette/macchiato.png)

- **Source** : 