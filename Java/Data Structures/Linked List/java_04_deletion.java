import java.util.Scanner;

class Node {
  int data;
  Node next;

  Node(int item) {
    data = item;
    next = null;
  }
}

class LinkedList {
  Node head;

  LinkedList() {
    Node head = null;
  }

  /* Length of the linked list */
  int length() {
    Node temp = head;
    int len = 0;
    while (temp != null) {
      temp = temp.next;
      len++;
    }
    return len;
  }

  /* Display created list */
  void displayList() {
    Node temp = head;
    System.out.print("\nElements in the list: [ ");
    while (temp != null) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;
    }
    System.out.print(" NULL ]\n");
    System.out.println("Length: " + length());
  }

  /* creaete node in the linked list */
  void createList() {
    int num;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of elements in the list: ");
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
        temp.next = newnode;
      }
    }
    displayList();
    sc.close();
  }

  /*** DELETION OPERATIONS ***/

  /* Delete from the beginning */
  void deletFromBeginning() {
    Node temp = head;

    if (temp == null) {
      System.out.println("List is already empty");
      return;
    } else {
      head = head.next;
      displayList();
      System.out.println("Deleted Node: " + temp.data);
      temp = null;
    }
  }

  /* Delete from the end */
  void deleteFromEnd() {
    Node temp = head;
    Node prevnode = head;

    while (temp.next != null) {
      prevnode = temp;
      temp = temp.next;
    }
    prevnode.next = null;
    displayList();
    System.out.println("Deleted Node: " + temp.data);
    temp = null;
  }

  /* Delete from specified posititon */
  void deleteFromPos(int pos) {
    Node temp = head;
    Node nextnode = head;
    int i = 1;

    while (i < pos - 1) {
      temp = temp.next;
      i++;
    }
    nextnode = temp.next;
    temp.next = nextnode.next;
    displayList();
    System.out.println("Deleted Node: " + nextnode.data);
    nextnode = null;
  }
}

public class java_04_deletion {
  public static void main(String[] args) {
    LinkedList linked_list = new LinkedList();
    linked_list.createList();
    linked_list.deletFromBeginning();
    linked_list.deleteFromEnd();
    linked_list.deleteFromPos(3);
  }
}
