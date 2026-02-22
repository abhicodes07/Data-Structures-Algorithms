package com.corejava.notes.collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Collections;
import java.util.Comparator;

class StringLengthComparator implements Comparator<String> {

    // sort strings based on their lengths
    @Override
    public int compare(String o1, String o2) {
        // logic for custom sorting is written here
        // o1     o2
        // "ok" "bye"
        // len: 2, 3
        // when it returns positive o1 comes after o2
        // when it returns negative o1 comes before o2
        // 2 - 3 = -1 (negative) -> order: ok -> bye
        return o1.length() - o2.length();
    }
}

// create a class that implements Comparator interface
class MyComparator implements Comparator<Integer> {

    // descending order
    @Override
    public int compare(Integer o1, Integer o2) {
        // if this method returns negative, o1 comes before o2
        // if this method returns positive, o1 comes after o2

        // eg - 5, 3 -> 3 - 5 = -2 (negative) -> 5, 3
        // eg - 3, 5 -> 3 - 5 = 2 (positive) -> 5, 3
        return o2 - o1;
    }
}

public class Arraylist {
    public static void main(String[] args) {
        // initialize ArrayList of integers
        ArrayList<Integer> list = new ArrayList<>();

        // Insertion =====================================
        // Adding elements to the end of the list
        list.add(400);
        list.add(2);
        list.add(3);

        // Adding element at specific index
        list.add(2, 50);
        System.out.println(list);

        // access elements
        System.out.println(list.get(2));

        // get size of the list
        System.out.println(list.size());

        // traverse ======================================
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }

        // traverse over each element
        for (int x: list) {
            System.out.println(x);
        }

        // we can print list without using loop
        // as list extends one of the classes implementing
        // toString() function
        System.out.println(list);

        // check for elements ============================
        System.out.println(list.contains(5));
        System.out.println(list.contains(10));

        // Deletion ======================================
        // remove element using index
        list.remove(2);
        System.out.println(list);

        // remove elements using value
        // for integers, the method by default takes the
        // parameter to index
        // list.remove(400);
        // so we need convert it to the wrapper class
        list.remove(Integer.valueOf(400));
        System.out.println(list);

        // replace an element
        list.set(2, 100);
        System.out.println(list);

        // initialize using Arrays =======================
        // add or removal not allowed as this; unmodifiable
        // creates a private fixed size array list
        String[] array = {"Apple", "Banana", "Cherry"};
        List<String> list1 = Arrays.asList(array);
        System.out.println(list1.getClass().getName());
        list1.add("Mango"); // throws exception

        // make unmodifiable list modifiable
        List<String> list2 = new ArrayList<>(list1);
        list2.add("Mango");

        // create list of immutable objects
        List<Integer> list3 = List.of(1, 2, 3, 4, 5);
        list3.set(1, 5); // throws an exception

        // sort a ArrayList =============================
        Collections.sort(list);
        System.out.println(list);

        // Comparator ===================================
        // by default, sorting in ascending order
        List<Integer> num = Arrays.asList(4, 3, 7, 2, 1);
        num.sort(null);
        System.out.println("Ascending (by default): " + num);

        List<String> fruits = Arrays.asList("banana", "apple", "kiwi");
        fruits.sort(null);
        System.out.println("Unsorted: " + fruits);

        // custom order: implement a class extending
        // using Comparator functional interface for descending order of numbers
        num.sort(new MyComparator());
        System.out.println("Descending using comparator: " + num);

        // sorting based on length using comparator
        fruits.sort(new StringLengthComparator());
        System.out.println("Sorting based on length using comparator: " + fruits);

        // Comparator using lambda expression ===========
        // using lambda comparator (descending)
        num.sort((a, b) -> b - a);
        System.out.println("Descending using comparator (lambda): " + num);

        // using lambda comparator (descending based on length)
        fruits.sort((a, b) -> b.length() - a.length());
        System.out.println("Sorting based on length using comparator (lambda): " + fruits);

    }
}
