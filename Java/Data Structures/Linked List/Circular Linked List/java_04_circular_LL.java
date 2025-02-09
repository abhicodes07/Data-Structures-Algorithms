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
    System.out.print("Elements in the list: [ ");
    while (true) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;

      if (temp == tail.next) {
        break;
      }
    }
    System.out.println(tail.next.data + " ]");
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
    display();
  }

  // delete from the beginning of the list
  void deleteFromBeg() {
    temp = tail.next;
    if (tail == null) {
      System.out.println("List is already empty");
      return;
    }

    // if there's only single node
    if (tail.next == tail) {
      System.out.println("Deleted Node: " + tail.data);
      tail = null;
      return;
    }

    tail.next = temp.next;
    System.out.println("\nDeleted Node: " + temp.data);
    temp = null; // free node
    display();
  }

  // delete from the end of the linked list
  void deleteFromEnd() {
    Node current = tail.next;
    Node prevnode = null;
    if (tail == null) {
      System.out.println("LIST IS EMPTY");
      return;
    }

    // if there's only single node
    if (tail.next == tail) {
      System.out.println("Deleted Node: " + tail.data);
      tail = null;
      return;
    }

    while (current.next != tail.next) {
      prevnode = current; // move prevnode to one node back
      current = current.next;
    }
    prevnode.next = tail.next;
    tail = prevnode;
    System.out.println("\nDeleted Node: " + current.data);
    current = null; // free node
    display();
  }

  // delete from certain position in the list
  void deleteFromPos(int pos) {
    if (pos > length() || pos < 0) {
      System.out.println("POSITION OUT OF BOUND");
      return;
    } else if (pos == 1) {
      deleteFromBeg();
      return;
    } else if (pos == 0) {
      deleteFromEnd();
      return;
    }

    // if there's only single node
    if (tail.next == tail) {
      System.out.println("Deleted Node: " + tail.data);
      tail = null;
      return;
    }

    Node current = tail.next;
    Node nextnode = null;

    int i = 1;

    while (i < pos - 1) {
      current = current.next;
      i++;
    }
    nextnode = current.next;
    current.next = nextnode.next;
    System.out.println("\nDeleted Node: " + nextnode.data);
    nextnode = null; // free node
    display();
  }
}

public class java_04_circular_LL {
  public static void main(String[] args) {
    CircularLL linked_list = new CircularLL();
    linked_list.createCll();
    linked_list.deleteFromPos(3);
  }
}
