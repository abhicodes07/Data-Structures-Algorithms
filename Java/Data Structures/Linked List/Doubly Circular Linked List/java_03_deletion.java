/* DELETION OPERATION IN DOUBLY CIRCULAR LINKED LIST */

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
  }

  // length of the list
  int length() {
    temp = head;
    int length = 0;
    while (true) {
      temp = temp.next;
      length++;

      if (temp == tail.next) {
        break;
      }
    }
    return length;
  }

  // delete from the beginning of the list
  void deleteFromBeg() {
    temp = head;

    if (head == null) {
      System.out.println("LIST IS EMPTY!");
      return;
    } else if (head == head.next) {
      head = null;
      tail = null;
      temp = null;
      System.out.println("LIST IS EMPTY");
      return;
    }

    head = head.next;
    head.prev = tail;
    tail.next = head;
    System.out.println("Deleted Node: [ " + temp.data);
    temp = null;
    display();
  }

  // delete from the end of the list
  void deleteFromEnd() {
    temp = tail;

    if (tail == null) {
      System.out.println("LIST IS EMPTY!");
      return;
    } else if (tail == tail.next) {
      head = null;
      tail = null;
      temp = null;
      System.out.println("LIST IS EMPTY");
      return;
    }

    tail = tail.next;
    tail.next = head;
    head.prev = tail;
    System.out.println("Deleted Node: [ " + temp.data);
    temp = null;
    display();
  }

  // delete from the specific position in the list
  void deleteFromPos(int pos) {
    int len = length();
    if (pos > len || pos < 0) {
      System.out.println("INVALID POSITION");
      return;
    } else if (pos == 1) {
      deleteFromBeg();
      return;
    } else if (pos == len) {
      deleteFromEnd();
      return;
    }

    int i = 1;
    temp = head;
    while (i < pos) {
      temp = temp.next;
      i++;
    }

    temp.prev.next = temp.next;
    temp.next.prev = temp.prev;
    System.out.println("Deleted Node: [ " + temp.data);
    temp = null;
    display();
  }
}

public class java_03_deletion {
  public static void main(String[] args) {
    DoublyCircularLL linked_list = new DoublyCircularLL();
    linked_list.createDCLL();
    linked_list.deleteFromBeg();
    linked_list.deleteFromEnd();
    linked_list.deleteFromPos(3);
  }
}
