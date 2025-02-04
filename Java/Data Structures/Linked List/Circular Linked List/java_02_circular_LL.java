/*
 * IMPLEMENTATION OF CIRCULAR LINKED LIST USING SINGLE POINTER
 */

import java.util.Scanner;

// create node
class Node {
  int data;
  Node next;

  Node(int item) {
    data = item;
    next = null;
  }
}

// circular linked list
class CircularLL {
  Node tail;
  Node temp;
  Node newnode;

  CircularLL() {
    tail = null;
  }

  // create circular linked list
  Node creatCLL() {
    int num;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of nodes in the list: ");
    num = sc.nextInt();

    for (int i = 0; i < num; i++) {
      int val;
      System.out.print("Enter the data for node " + i + ": ");
      val = sc.nextInt();
      newnode = new Node(val);

      if (tail == null) {
        tail = newnode;
        tail.next = newnode;
      } else {
        newnode.next = tail;
        tail.next = newnode;
        tail = newnode;
      }
    }
    sc.close();
    return tail;
  }

  void display(Node tail) {
    temp = tail.next;
    System.out.print("\nElements in the list: [ ");
    while (true) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;

      if (temp == tail.next) {
        break;
      }
    }
    System.out.print(tail.next.data + " ]");
  }
}

public class java_02_circular_LL {
  public static void main(String[] args) {
    CircularLL linked_list = new CircularLL();
    Node list = linked_list.creatCLL();
    linked_list.display(list);
  }
}
