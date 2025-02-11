#include <iostream>
using namespace std;

// create a node for circular linked list
struct Node {
  int data;
  Node *next;
};

// circular linked list
class CircularLL {
private:
  Node *tail;
  Node *newnode;
  Node *temp;

public:
  CircularLL() { tail = nullptr; } // initialize tail null

  // create circular linkedlist
  void createCLL() {
    int num;
    cout << "Enter the number of nodes in the list: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
      newnode = new Node();
      cout << "Enter the data for node " << i << ": ";
      cin >> newnode->data;

      if (tail == nullptr) {
        tail = newnode;
        tail->next = newnode;
      } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
      }
    }
    display();
  }

  // display nodes
  void display() {
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

  // reverse circular linked list
  void reverse() {
    Node *current, *prevnode, *nextnode;

    if (tail == 0) {
      cout << "List is empty" << endl;
      return;
    }
    current = tail->next;     // first node in the list
    nextnode = current->next; // one node forward

    while (current != tail) {
      prevnode = current;
      current = nextnode;
      nextnode = current->next;
      current->next = prevnode;
    }
    nextnode->next = tail;
    tail = nextnode;
    display();
  }
};

int main(int argc, char *argv[]) {
  CircularLL linked_list;
  linked_list.createCLL();
  linked_list.reverse();
  return 0;
}
