import java.util.Scanner;

/* Node data type */
class Node {
  int data; // data part
  Node next; // next part for address of next node
  Node prev; // prev part for address of previous node

  Node(int item) {
    data = item;
    next = null;
    prev = null;
  }
}

/* Create doubly linked list */
class DoublyLinkedList {
  Node head;
  Node temp;

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
        temp = head;

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
    temp = head;
    System.out.print("\nElements in the list: [ ");
    while (temp != null) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;
    }
    System.out.print("NULL ]");
  }

  // length of the linked list
  int length() {
    temp = head;
    int length = 0;
    while (temp != null) {
      temp = temp.next;
      length++;
    }
    return length;
  }

  // insert at the end of the list
  void insertAtEnd(int data) {
    Node newnode = new Node(data);

    // if list is empty
    if (head == null) {
      head = newnode;
    } else {
      temp = head;
      while (temp.next != null) {
        temp = temp.next;
      }
      temp.next = newnode;
      newnode.prev = temp;
    }
    display();
  }

  // insert at the beginning of the dll
  void insertAtBeg(int data) {
    Node newnode = new Node(data);

    // if list is empty
    if (head == null) {
      head = newnode;
    } else {
      head.prev = newnode;
      newnode.next = head;
      head = newnode;
    }
    display();
  }

  // insert at specific position
  void insertAtPos(int data, int pos) {
    // invalid position bound
    if (pos < 0 || pos > length()) {
      System.out.println("\nINVALID POSITION!");
    } else if (pos == 1) {
      // if position is 1 then just add it at the beginning
      insertAtBeg(data);
    } else {
      Node newnode = new Node(data);
      int i = 0;
      while (i < pos - 2) {
        temp = temp.next;
        i++;
      }
      newnode.next = temp.next;
      newnode.prev = temp;
      temp.next = newnode;
      newnode.next.prev = newnode;
      display();
    }
  }
}

public class java_02_insertion {
  public static void main(String[] args) {
    DoublyLinkedList linked_list = new DoublyLinkedList();
    linked_list.createList();
  }
}
