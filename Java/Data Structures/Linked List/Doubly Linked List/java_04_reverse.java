import java.util.Scanner;

/* create a node */
class Node {
  int data;
  Node prev;
  Node next;

  Node(int item) {
    data = item;
    prev = null;
    next = null;
  }
}

/* doubly linked list */
class DLinkedList {
  Node head;
  Node tail;
  Node current;
  Node nextnode;

  DLinkedList() {
    head = null;
    tail = null;
  }

  // create a doubly llinked list
  void createDLL() {
    int num;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of node in the list: ");
    num = sc.nextInt();

    for (int i = 0; i < num; i++) {
      int data;
      System.out.print("Enter the data for node " + i + ": ");
      data = sc.nextInt();
      Node newnode = new Node(data);

      if (head == null) {
        head = newnode;
        tail = newnode;
      } else {
        Node temp = head;
        while (temp.next != null) {
          temp = temp.next;
        }
        temp.next = newnode;
        newnode.prev = temp;
        tail = newnode;
      }
    }
    sc.close();
    display();
  }

  // display linked list
  void display() {
    Node temp = head;
    System.out.print("Elements in the list: [ ");
    while (temp != null) {
      System.out.print(temp.data + " <-> ");
      temp = temp.next;
    }
    System.out.print(" NULL ]\n");
  }

  // reverse linked list
  void reverse() {
    current = head;

    while (current != null) {
      nextnode = current.next;
      current.next = current.prev;
      current.prev = nextnode;
      current = nextnode;
    }
    nextnode = head;
    head = tail;
    tail = nextnode;
    display();
  }
}

public class java_04_reverse {
  public static void main(String[] args) {
    DLinkedList linked_list = new DLinkedList();
    linked_list.createDLL();
    linked_list.reverse();
  }
}
