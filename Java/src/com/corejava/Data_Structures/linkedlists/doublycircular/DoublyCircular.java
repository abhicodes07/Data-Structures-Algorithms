package com.corejava.Data_Structures.linkedlists.doublycircular;
import java.util.*;

public class DoublyCircular {
    Node head;
    Node tail;
    Node temp;
    Node newnode;
    int count;

    public DoublyCircular() {
        head = tail = temp = null;
    }

    public void createDoublyCircularList() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the nodes in the list: ");
        count = sc.nextInt();

        int data;
        for (int i = 0; i < count; i++) {
            System.out.print("Enter the " + i + " node data: ");
            data = sc.nextInt();
            newnode = new Node(data);

            if (head == null) {
                head = tail = newnode;
                head.next = newnode; // initially new node points to itself
                head.prev = newnode;
            } else {
                newnode.next = head; // last node points to first node in the list
                newnode.prev = tail; // last node points to previous node
                tail.next = newnode; // previous node points to next node
                head.prev = newnode; // first node points to the last node
                tail = tail.next; // move tail
            }
        }
    }

    // display list
    public void display() {
        temp = head;
        System.out.print("Elements in the list: ");
        while (temp.next != head) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        // print the last node as the above loop
        // will not execute at the last node
        System.out.println(temp.data);
    }
}
