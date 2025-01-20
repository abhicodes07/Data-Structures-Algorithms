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

  /* reverse a linked list */
  void reversList() {
    Node currentnode = head;
    Node nextnode = head;
    Node prevnode = null;

    while (nextnode != null) {
      nextnode = nextnode.next;
      currentnode.next = prevnode;
      prevnode = currentnode;
      currentnode = nextnode;
    }
    head = prevnode;
    displayList();
  }
}

public class java_05_reverse_list {
  public static void main(String[] args) {
    LinkedList linked_list = new LinkedList();
    linked_list.createNode();
    linked_list.reversList();
  }
}
