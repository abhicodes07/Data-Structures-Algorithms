import java.util.Scanner;

class Node {
  int data;
  Node next;

  Node(int item) {
    data = item;
    next = null;
  }
}

/* Linked List Class */
class LinkedList {
  Node head;

  LinkedList() {
    head = null;
  }

  /* Display created list */
  void displayList() {
    Node temp = head;
    System.out.print("\nElements in the list: [ ");
    while (temp != null) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;
    }
    System.out.print(" NULL ]");
  }

  /* creaete node in the linked list */
  void createNode() {
    Scanner sc = new Scanner(System.in);
    int num_nodes;
    System.out.print("Enter the number of nodes in the linked list: ");
    num_nodes = sc.nextInt();

    for (int i = 0; i < num_nodes; i++) {
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
    sc.close();
    displayList();
  }

  /* Insert at beginning of the list */
  void insertAtBeginning(int item) {
    Node newnode = new Node(item);

    if (head == null) {
      head = newnode;
      return;
    } else {
      newnode.next = head;
      head = newnode;
    }
    displayList();
  };

  /* Insert at the End of the list */
  void insertAtEnd(int item) {
    Node newnode = new Node(item);

    if (head == null) {
      // if there's only one node then
      // no need to further execute
      // the code; exit
      head = newnode;
      return;
    } else {
      Node temp = head;
      while (temp.next != null) {
        temp = temp.next;
      }
      temp.next = newnode;
    }
    displayList();
  }

  /* Insert at certain position in the list */
  void insertAtPosition(int item, int position) {
    Node newnode = new Node(item);
    Node temp = head;
    int i = 0, count = 0;

    while (temp.next != null) {
      temp = temp.next;
      count++;
    }

    if (position > count || position < 0) {
      System.out.println("Invalid position");
      return;
    }

    temp = head;
    while (i < position - 1) {
      temp = temp.next;
      i++;
    }
    newnode.next = temp.next;
    temp.next = newnode;
    displayList();
  }
}

public class java_03_insertion {
  public static void main(String[] args) {
    LinkedList lnkd_list = new LinkedList();
    lnkd_list.createNode();
    lnkd_list.insertAtEnd(100);
    lnkd_list.insertAtBeginning(1000);
    lnkd_list.insertAtPosition(555, 2);
  }
}
