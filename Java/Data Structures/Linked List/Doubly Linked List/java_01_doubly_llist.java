import java.io.PrintStream;
import java.util.Scanner;

/* Node data type */
class Node {
  int data;
  Node next;
  Node prev;

  Node(int item) {
    data = item;
    next = null;
    prev = null;
  }
}

/* Create doubly linked list */
class DoublyLinkedList {
  Node head;

  DoublyLinkedList() {
    head = null;
  }

  // create list
  void createList() {
    int num;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of nodes in the list: ");
    num = sc.nextInt();

    for (int i = 0; i < num; i++) {
      int data;
      System.out.print("Enter the data for node " + i + " : ");
      data = sc.nextInt();
      Node newnode = new Node(data);

      if (head == null) {
        head = newnode;
      } else {
        Node temp = head;

        while (temp.next != null) {
          temp = temp.next;
        }
        temp.next = newnode; // store next node
        newnode.prev = temp; // store previous node
      }
    }
    sc.close();
    display();
  }

  // display list
  void display() {
    Node temp = head;
    System.out.print("\nElements in the list: [ ");
    while (temp != null) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;
    }
    System.out.print("NULL ]");
  }
}

public class java_01_doubly_llist {
  public static void main(String[] args) {
    DoublyLinkedList linked_list = new DoublyLinkedList();
    linked_list.createList();
  }
}
