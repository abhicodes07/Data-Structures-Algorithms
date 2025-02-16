/* DELETION OF DOUBLY CIRCULAR LINKED LIST */
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;

// create node for DCLL
struct Node {
  int data;   // data part
  Node *next; // stores address of next node
  Node *prev; // stores address of previous node
};

class DoublyCircularLL {
private:
  Node *head, *tail, *newnode, *temp;

public:
  // initialize head and tail null
  DoublyCircularLL() {
    head = nullptr;
    tail = nullptr;
  }

  // create doubly circular linked list
  void createDCLL() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
      newnode = new Node();
      newnode->data = arr[i];

      // check if list is empty
      if (head == nullptr) {
        // both head and tail point to newnode
        head = newnode;
        tail = newnode;

        // first node's next and prev parts points to itself
        head->next = newnode;
        head->prev = newnode;
      } else {
        newnode->next = head; // newnode pointing to head
        newnode->prev = tail; // newnode pointing to previous node
        head->prev = newnode; // head pointing to last node in the list newnode
        tail->next = newnode; // the previous node points to newnode
        tail = newnode;       // move tail
      }
    }
    display();
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

  // display list
  void display() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      exit(0);
    }

    temp = head;
    cout << endl << "Elements in the list: [ ";
    while (true) {
      cout << temp->data << " <-> ";
      temp = temp->next;

      if (temp == tail->next) {
        break;
      }
    }
    cout << tail->next->data << " ]" << endl;
  }

  // deletion from the beginning of the list
  void deleteFromBeg() {
    temp = head;
    if (head == nullptr) {
      cout << "LIST IS EMPTY!!" << endl;
      exit(0);
    } else if (head == head->next) {
      head = nullptr;
      tail = nullptr;
      free(temp);
      cout << "LIST IS EMPTY!!" << endl;
    }

    head = head->next;
    head->prev = tail;
    tail->next = head;
    cout << endl << "Deleted Node: [ " << temp->data << " ]";
    free(temp);
    display();
  }

  // delete from the end of the list
  void deleteFromEnd() {
    temp = tail;
    if (tail == nullptr) {
      cout << "LIST IS EMPTY!!" << endl;
      exit(0);
    } else if (tail == tail->next) {
      head = nullptr;
      tail = nullptr;
      free(temp);
      cout << "LIST IS EMPTY!!" << endl;
    }

    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    cout << endl << "Deleted Node: [ " << temp->data << " ]";
    free(temp);
    display();
  }

  // delete from specific position in the list
  void deleteFromPos(int pos) {
    int len = length();
    if (pos > len || len < 0) {
      cout << "INVALID POSIION!";
      exit(0);
    } else if (pos == 1) {
      deleteFromBeg();
      exit(0);
    } else if (pos == len) {
      deleteFromEnd();
      exit(0);
    }

    int i = 1;
    temp = head;
    while (i < pos) {
      temp = temp->next;
      i++;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    cout << endl << "Deleted Node: [ " << temp->data << " ]";
    free(temp);
    display();
  }
};

int main(int argc, char *argv[]) {
  DoublyCircularLL linked_list;
  linked_list.createDCLL();
  // linked_list.deleteFromBeg();
  // linked_list.deleteFromEnd();
  linked_list.deleteFromPos(3);
  return 0;
}
