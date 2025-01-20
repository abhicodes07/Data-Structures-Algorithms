#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() { head = nullptr; }

  void displayList(void) {
    Node *temp = head;

    cout << "Elements in list: [ ";
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << " NULL ]" << endl;
  }

  void createNode(void) {
    int num_node;
    cout << "Enter the number of elements in the Linked List: ";
    cin >> num_node;

    for (int i = 0; i < num_node; i++) {
      Node *newnode = new Node();
      cout << "Enter the data for node " << i << ": ";
      cin >> newnode->data;
      newnode->next = nullptr;

      if (head == nullptr) {
        head = newnode;
      } else {
        Node *temp = head;
        while (temp->next != nullptr) {
          temp = temp->next;
        }
        temp->next = newnode;
      }
    }
    displayList();
  }

  void reverse(void) {
    Node *currentnode = head;
    Node *nextnode = head;
    Node *prevnode = nullptr;

    while (nextnode != nullptr) {
      nextnode = nextnode->next;
      currentnode->next = prevnode;
      prevnode = currentnode;
      currentnode = nextnode;
    }
    head = prevnode;
    displayList();
  }
};

int main(int argc, char *argv[]) {
  LinkedList linked_list;
  linked_list.createNode();
  linked_list.reverse();
  return 0;
}
