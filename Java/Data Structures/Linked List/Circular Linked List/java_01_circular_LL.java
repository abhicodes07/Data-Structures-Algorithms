/*
 * CIRCULAR LINKED LIST IMPLEMENTATION 
 * USING TAIL AND HEAD POINTERS
 */

import java.util.Scanner;

// create node type
class Node {
  int data;
  Node next;

  Node(int item) {
    data = item;
    next = null;
  }
}

// Circular Linked List
class CircularLinkedList {
  Node head;
  Node newnode;
  Node tail;

  // initialize head null
  CircularLinkedList() {
    head = null;
    tail = null;
  }

  // create circular linked list
  void createCLL() {
    int num;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of elements in the list: ");
    num = sc.nextInt();

    for (int i = 0; i < num; i++) {
      int val;
      System.out.print("Enter the data for node " + i + ": ");
      val = sc.nextInt();
      newnode = new Node(val);

      // check if list is empty
      if (head == null) {
        head = newnode;
        tail = newnode;
      } else {
        tail.next = newnode; // update next address of previous node
        tail = newnode; // move tail to newnode
      }
    }
    tail.next = head; // last node stores address of first node
    display();
    sc.close();
  }

  // display nodes
  void display() {
    if (head == null) {
      System.out.println("List is empty!!");
      return;
    }

    Node temp = head;
    System.out.print("\nElements in the list: [ ");

    while (true) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;

      if (temp == head) {
        break;
      }
    }
    // print head at the end to make it look circular
    System.out.print(temp.data + " ]");
  }
}

public class java_01_circular_LL {
  public static void main(String[] args) {
    CircularLinkedList cll = new CircularLinkedList();
    cll.createCLL();
  }
}
