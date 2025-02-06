
/* IMPLEMENTATION OF CIRCULAR LINKED LIST */
import java.nio.channels.Pipe.SourceChannel;
import java.util.Scanner;

// create a node
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
  Node newnode;
  Node temp;

  CircularLL() {
    tail = null;
  }

  // length of the list
  int length() {
    int length = 0;
    temp = tail.next;
    while (true) {
      temp = temp.next;
      length++;

      if (temp == tail.next) {
        break;
      }
    }
    return length;
  }

  // display
  void display() {
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

  // create a circular linked list
  void createCll() {
    int[] list = { 10, 20, 30, 40, 50 };

    for (int i = 0; i < list.length; i++) {
      Node newnode = new Node(list[i]);

      if (tail == null) {
        tail = newnode;
        tail.next = newnode;
      } else {
        newnode.next = tail.next;
        tail.next = newnode;
        tail = newnode;
      }
    }
  }

  // insert at the beginning of the list
  void insertAtBeg(int item) {
    Node newnode = new Node(item);

    if (tail == null) {
      tail = newnode;
      tail.next = newnode;
    } else {
      newnode.next = tail.next;
      tail.next = newnode;
      tail = newnode;
    }
    display();
  }

  // insert at the end of the list
  void insertAtEnd(int item) {
    Node newnode = new Node(item);

    if (tail == null) {
      tail = newnode;
      tail.next = newnode;
    } else {
      newnode.next = tail.next;
      tail.next = newnode;
    }
    display();
  }

  // insert at the specific position in the list
  void insertAtPos(int pos, int item) {
    int len = length();
    if (pos < 0 || pos > len) {
      System.out.println("INVALID POSITION!!");
      return;
    } else if (pos == 1) {
      insertAtBeg(item);
    } else if (pos == len) {
      insertAtEnd(item);
    } else {
      Node newnode = new Node(item);
      int i = 1;
      temp = tail.next;

      while (i < pos - 1) {
        temp = temp.next;
        i++;
      }

      newnode.next = temp.next;
      temp.next = newnode;
    }
    display();
  }
}

public class java_03_insertion {
  public static void main(String[] args) {
    CircularLL lnkd = new CircularLL();
    lnkd.createCll();
    lnkd.insertAtBeg(222);
    lnkd.insertAtEnd(777);
    lnkd.insertAtPos(3, 555);
  }
}
