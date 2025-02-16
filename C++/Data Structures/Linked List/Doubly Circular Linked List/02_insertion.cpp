/* INSERTION OPERATION IN DOUBLY CIRCULAR LINKED LIST */
#include <cstdlib>
#include <iostream>
using namespace std;

// create a node
struct Node {
  int data;
  Node *next;
  Node *prev;
};

// doubly circular linked list
class DoublyLinkedLL {
private:
  Node *newnode, *temp, *head, *tail;

public:
  DoublyLinkedLL(void) {
    head = nullptr;
    tail = nullptr;
  }

  // create doubly circular linked list
  void createDCLL(void) {
    int num[] = {10, 20, 30, 40, 50};
    int size = sizeof(num) / sizeof(num[0]);

    for (int i = 0; i < size; i++) {
      newnode = new Node();
      newnode->data = num[i];

      // check if list is empty or not
      if (head == nullptr) {
        head = newnode;
        tail = newnode;
        head->prev = newnode;
        head->next = newnode;
      } else {
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        tail = newnode;
      }
    }
    display();
  }

  // display list
  void display() {
    temp = head;
    cout << "Elements in the list: [ ";
    while (true) {
      cout << temp->data << " <-> ";
      temp = temp->next;

      if (temp == tail->next) {
        break;
      }
    }
    cout << tail->next->data << " ]" << endl;
  }

  // length of the list
  int length() {
    temp = head;
    int length = 0;
    while (true) {
      temp = temp->next;
      length++;

      if (temp == tail->next) {
        break;
      }
    }
    return length;
  }

  // insertion at the beginning of the list
  void insertionAtBeg(int item) {
    newnode = new Node();
    newnode->data = item;

    if (head == nullptr) {
      head = newnode;
      tail = newnode;
      head->prev = newnode;
      head->next = newnode;
    } else {
      newnode->prev = tail;
      newnode->next = head;
      tail->next = newnode;
      head = newnode;
    }
    display();
  }

  // insertion at the end of the list
  void insertionAtEnd(int item) {
    newnode = new Node();
    newnode->data = item;

    if (head == nullptr) {
      head = newnode;
      tail = newnode;
      head->prev = newnode;
      head->next = newnode;
    } else {
      newnode->next = head;
      newnode->prev = tail;
      tail->next = newnode;
      head->prev = newnode;
      tail = newnode;
    }
    display();
  }

  // insertion at certain position in the list
  void insertionAtPos(int item, int pos) {
    int len = length();
    if (pos > len || pos < 0) {
      cout << "INVALID POSITION!" << endl;
      exit(0);
    } else if (pos == 1) {
      insertionAtBeg(99);
      exit(0);
    } else if (pos == len) {
      insertionAtEnd(77);
      exit(0);
    }

    newnode = new Node();
    newnode->data = item;

    temp = head;
    int i = 1;
    while (i < pos - 1) {
      temp = temp->next;
      i++;
    }

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    display();
  }
};

int main(int argc, char *argv[]) {
  DoublyLinkedLL linked_list;
  linked_list.createDCLL();
  linked_list.insertionAtBeg(99);
  return 0;
}
