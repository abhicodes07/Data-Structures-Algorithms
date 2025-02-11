import java.util.Scanner;

class Node {
  int data;
  Node next;

  Node(int data) {
    this.data = data;
    next = null;
  }
}

class CircularLL {
  Node tail;
  Node temp;
  Node newnode;

  CircularLL() {
    tail = null;
  }

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

      if (tail == null) {
        tail = newnode;
        tail.next = newnode;
      } else {
        newnode.next = tail.next;
        tail.next = newnode;
        tail = newnode;
      }
    }
    sc.close();
    display();
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

  // reverse the linked list
  void reverse() {
    if (tail == null) {
      System.out.println("LIST IS EMPTY");
      return;
    } else if (tail.next == tail) {
      display();
      return;
    }

    Node current, prevnode, nextnode;
    current = tail.next;
    nextnode = current.next;

    while (current != tail) {
      prevnode = current;
      current = nextnode;
      nextnode = current.next;
      current.next = prevnode;
    }
    nextnode.next = tail;
    tail = nextnode;
    display();
  }
}

public class java_05_reverse {
  public static void main(String[] args) {
    CircularLL linked_list = new CircularLL();
    linked_list.createCLL();
    linked_list.reverse();
  }
}
