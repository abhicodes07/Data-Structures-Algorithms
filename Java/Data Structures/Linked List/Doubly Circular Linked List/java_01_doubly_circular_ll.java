// create node for doubly circular linked list
class Node {
  int data;
  Node next;
  Node prev;

  Node(int val) {
    data = val;
    next = null;
    prev = null;
  }
}

class DoublyCircularLL {
  Node tail, head, newnode, temp;

  DoublyCircularLL() {
    head = null;
    tail = null;
  }

  // create doubly circular linked list
  void createDCLL() {
    int[] arr = { 10, 20, 30, 40, 50 };

    for (int i = 0; i < arr.length; i++) {
      newnode = new Node(arr[i]);

      // check if list is empty
      if (head == null) {
        // both head and tail point to newnode
        head = newnode;
        tail = newnode;

        // first node's next and prev parts points to itself
        head.next = newnode;
        head.prev = newnode;
      } else {
        newnode.next = head; // newnode pointing to head
        newnode.prev = tail; // newnode pointing to previous node
        head.prev = newnode; // head pointing to last node in the list newnode
        tail.next = newnode; // the previous node points to newnode
        tail = newnode; // move tail
      }
    }
    display();
  }

  // display
  void display() {
    temp = head;
    System.out.print("Elements in the list: [ ");

    while (true) {
      System.out.print(temp.data + " <-> ");
      temp = temp.next;

      if (temp == tail.next) {
        break;
      }
    }

    System.out.print(tail.next.data + " ]\n");
    System.out.println("Value of tail: " + tail.data);
    System.out.println("Tail pointing to first node in the list: " + tail.next.data);
    System.out.println("Value of head: " + head.data);
    System.out.println("Head pointing to last node in the list: " + head.prev.data);
  }
}

public class java_01_doubly_circular_ll {
  public static void main(String[] args) {
    DoublyCircularLL linked_list = new DoublyCircularLL();
    linked_list.createDCLL();
  }
}
