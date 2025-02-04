/*
 * IMPLEMENTATION OF CIRCULAR LINKED LIST USING SINGLE POINTER
 */
#include <iostream>
using namespace std;

// create node
struct Node {
  int data;   // data part
  Node *next; // next address part
};

// circular linked list
class CircularLL {
private:
  Node *tail;
  Node *newnode;
  Node *temp;

public:
  CircularLL() { tail = nullptr; }

  // create a linked list
  Node *createCLL() {
    int num;
    cout << "Enter the number of elements in the list: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
      newnode = new Node();
      cout << "Enter the data for node " << i << ": ";
      cin >> newnode->data;
      newnode->next = nullptr;

      // check if list is empty
      if (tail == nullptr) {
        tail = newnode;
        tail->next = newnode; // since it's first node it points to itself
      } else {
        // first update newnode next then move tail to newnode
        newnode->next = tail->next;

        // update next of previous node
        tail->next = newnode;

        // move tail to newnode
        tail = newnode;
      }
    }
    return tail;
  }

  void display(Node *tail) {
    temp = tail->next;

    cout << endl << "Elements in the list: [ ";
    while (true) {
      cout << temp->data << " -> ";
      temp = temp->next;

      if (temp == tail->next) {
        break;
      }
    }
    cout << tail->next->data << " ]" << endl;
  }
};

int main(int argc, char *argv[]) {
  CircularLL linked_list;
  Node *list = linked_list.createCLL();
  linked_list.display(list);
  return 0;
}
