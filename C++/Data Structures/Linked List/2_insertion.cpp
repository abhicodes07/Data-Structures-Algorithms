#include <cstddef>
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

  void insertAtBeginning(int item) {
    Node *newnode = new Node();
    newnode->data = item;
    newnode->next = nullptr;
    if (head == nullptr) {
      head = newnode;
    } else {
      newnode->next = head;
      head = newnode;
    }
    displayList();
  }

  void insertAtEnd(int item) {
    Node *newnode = new Node();
    newnode->data = item;
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
    displayList();
  }

  void insertAtPosition(int item, int position) {
    Node *newnode = new Node();
    if (!newnode) {
      exit(1);
    }
    newnode->data = item;
    Node *temp = head;
    int count;
    int i = 0;

    newnode->next = nullptr;
    while (i < position - 1) {
      temp = temp->next;
      i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    displayList();
  }
};

int main(int argc, char *argv[]) {
  LinkedList linked_list;
  linked_list.createNode();
  linked_list.insertAtBeginning(3000);
  linked_list.insertAtEnd(5000);
  linked_list.insertAtPosition(8000, 3);
  return 0;
}
