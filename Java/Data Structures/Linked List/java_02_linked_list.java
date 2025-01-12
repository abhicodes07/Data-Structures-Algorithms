public class java_02_linked_list {
  // Create a node
  static class Node {
    int data;
    Node next;
  }

  public static void main(String[] args) {
    Node head = null; // initialize head null
    Node temp;

    // Create nodes
    Node node1 = new Node();
    Node node2 = new Node();
    Node node3 = new Node();
    Node node4 = new Node();

    node1.data = 10;
    node2.data = 20;
    node3.data = 30;
    node4.data = 40;

    head = node1;
    head.next = node2;
    node2.next = node3;
    node3.next = node4;
    node4.next = null;

    temp = head;
    while (temp != null) {
      System.out.print(temp.data + "->");
      temp = temp.next;
    }
    System.out.print("NULL");
  }
}
