/*
 * CIRCULAR LINKED LIST IMPLEMENTATION
 * USING TAIL AND HEAD POINTERS
 */

#include <iostream>
using namespace std;

// create node data type
struct Node {
  int data;   // data part
  Node *next; // next pointer
};

// Circular linked list
class CircularLinkedList {
private:
  Node *head;
  Node *tail;
  Node *newnode;
  Node *temp;

public:
  CircularLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // create Circular linked list
  void createCLL(void) {
    int num;
    cout << "Enter the number of nodes in the list: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
      newnode = new Node();
      cout << "Enter the data for node " << i << ": ";
      cin >> newnode->data;
      newnode->next = nullptr;

      // check if list is empty
      if (head == nullptr) {
        head = newnode;
        tail = newnode;
      } else {
        tail->next = newnode;
        tail = newnode;
      }
    }
    // last node points to head i.e., first node
    tail->next = head;
    display();
  }

  // display nodes
  void display(void) {
    temp = head;

    cout << endl << "Elements in the list: [ ";
    while (true) {
      cout << temp->data << " -> ";
      temp = temp->next;

      if (temp == head) {
        break;
      }
    }
    cout << temp->data << " ]";
  }
};

int main(int argc, char *argv[]) {
  CircularLinkedList cll;
  cll.createCLL();
  return 0;
}
