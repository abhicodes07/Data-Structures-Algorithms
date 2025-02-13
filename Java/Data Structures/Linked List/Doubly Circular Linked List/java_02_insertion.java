
// create node
class Node {
  int data;
  Node next;
  Node prev;

  Node(int data) {
    this.data = data;
    next = null;
    prev = null;
  }
}

// doubly circular linked list
class DoublyCircularLL {
  private Node head;
  private Node tail;
  Node newnode;
  Node temp;

  DoublyCircularLL() {
    head = null;
    tail = null;
  }

  // create doubly circular linked list
  void createDCLL() {
    int[] arr = { 10, 20, 30, 40, 50 };

    for (int i = 0; i < arr.length; i++) {
      newnode = new Node(arr[i]);

      // check if list is empty or not
      if (head == null) {
        head = newnode;
        tail = newnode;
        head.next = newnode;
        head.prev = newnode;
      } else {
        newnode.next = head;
        newnode.prev = tail;
        tail.next = newnode;
        head.prev = newnode;
        tail = newnode;
      }
    }
    display();
  }

  // display list
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
    System.out.println(tail.next.data + " ]");
  }

  // get length
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

  // insert at the beginning of the list
  void insertAtBeg(int item) {
    // create a newnode
    newnode = new Node(item);

    // check if list is empty
    if (head == null) {
      head = newnode;
      tail = newnode;
      head.next = newnode;
      head.prev = newnode;
    } else {
      newnode.next = head;
      newnode.prev = head.prev;
      head.prev = newnode;
      tail.next = newnode;
      head = newnode;
    }
    display();
  }

  // insert at the end of the list
  void insertAtEnd(int item) {
    newnode = new Node(item);

    // check if list is empty
    if (head == null) {
      head = newnode;
      tail = newnode;
      head.next = newnode;
      head.prev = newnode;
    } else {
      newnode.next = head;
      newnode.prev = tail;
      tail.next = newnode;
      head.prev = newnode;
      tail = newnode;
    }
    display();
  }

  // insert at specific position in the list
  void insertAtPos(int pos, int item) {
    int len = length();
    if (pos > len || pos < 0) {
      System.out.println("INVALID POSITION!");
      return;
    } else if (pos == 1) {
      insertAtBeg(44);
      return;
    } else if (pos == len) {
      insertAtEnd(77);
      return;
    }

    newnode = new Node(item);

    int i = 1;
    temp = head;

    while (i < pos - 1) {
      temp = temp.next;
      i++;
    }

    newnode.prev = temp;
    newnode.next = temp.next;
    temp.next.prev = newnode;
    temp.next = newnode;
    display();
  }
}

public class java_02_insertion {
  public static void main(String[] args) {
    DoublyCircularLL lnkdlist = new DoublyCircularLL();
    lnkdlist.createDCLL();
    // lnkdlist.insertAtBeg(99);
    // lnkdlist.insertAtEnd(55);
    lnkdlist.insertAtPos(3, 22);

  }
}
