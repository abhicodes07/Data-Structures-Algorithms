import java.util.Scanner;

// Create Node
class Node {
  int data;
  Node prev;
  Node next;

  Node(int item) {
    data = item;
    next = null;
    prev = null;
  }
}

// Doubly linked list
class DoublyLinkedList {
  Node head = null;
  Node temp;
  Node tail;

  // create doubly linked list
  void createDll() {
    Scanner sc = new Scanner(System.in);
    int num;
    System.out.print("Enter the number of nodes in the list: ");
    num = sc.nextInt();

    for (int i = 0; i < num; i++) {
      int data;
      System.out.print("Enter the data node " + i + ": ");
      data = sc.nextInt();
      Node newnode = new Node(data);

      // check if list is empty
      if (head == null) {
        head = newnode;
        tail = newnode;
      } else {
        temp = head;
        while (temp.next != null) {
          temp = temp.next;
        }
        temp.next = newnode;
        newnode.prev = temp;
        tail = newnode;
      }
    }
    System.out.println();
    display();
    sc.close();
  }

  // length of the list
  int length() {
    temp = head;
    int length = 0;
    while (temp != null) {
      temp = temp.next;
      length++;
    }
    return length;
  }

  // display linked list
  void display() {
    temp = head;
    System.out.print("Elements in the list: [ ");
    while (temp != null) {
      System.out.print(temp.data + " <-> ");
      temp = temp.next;
    }
    System.out.print(" NULL ]\n");
  }

  // delete from the beginning of the list
  void deleteFromBeg() {
    if (head == null) {
      System.out.println("List is empty!!");
      return;
    } else {
      temp = head;
      head = head.next;
      head.prev = null;

      // Display deleted node and free temp
      System.out.println("\nDeleted Node: " + temp.data);
      temp = null;
      display();
    }
  }

  // delete from the end of the linked list
  void deleteFromEnd() {
    if (head == null) {
      System.out.println("List is empty!!");
      return;
    } else {
      // no need to traverse if tail is maintained TC: O(1)
      tail = temp;
      tail = tail.prev;
      tail.next = null;

      // Display deleted node and free temp
      System.out.println("\nDeleted Node: " + temp.data);
      temp = null;
      display();
    }
  }

  // delete from specific position
  void deleteFromPos(int pos) {
    if (pos < 0 || pos > length()) {
      System.out.println("INVALID POSITION!");
    } else if (pos == 1) { // if position is first node, call function
      deleteFromBeg();
      return;
    } else if (pos == length()) { // if position is last node, call function
      deleteFromEnd();
      return;
    } else {
      int i = 1;
      temp = head;
      while (i < pos) {
        temp = temp.next; // traverse till position
        i++;
      }
      // update addresses of previous node and next node from temp
      temp.prev.next = temp.next;
      temp.next.prev = temp.prev;

      // Display deleted node and free temp
      System.out.println("\nDeleted Node: " + temp.data);
      temp = null;
      display();
    }
  }
}

public class java_03_deletion {
  public static void main(String[] args) {
    DoublyLinkedList linked_list = new DoublyLinkedList();
    linked_list.createDll();
    linked_list.deleteFromBeg();
    linked_list.deleteFromPos(1);
  }
}
