/* IMPLMENTATION OF DOUBLY CIRCULAR LINKED LIST */
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
    cout << "Value of tail: " << tail->data << endl;
    cout << "Tail pointing to first node in the list: " << tail->next->data
         << endl;
    cout << "Value of head: " << head->data << endl;
    cout << "Head pointing to last node in the list: " << head->prev->data
         << endl;
  }
};

int main(int argc, char *argv[]) {
  DoublyCircularLL linked_list;
  linked_list.createDCLL();
  return 0;
}
