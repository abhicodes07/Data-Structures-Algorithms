#include <iostream>
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

  void createNode(int item) {
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
  }

  void displayList() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL";
  }
};

int main(int argc, char *argv[]) {
  LinkedList linked_list;
  linked_list.createNode(10);
  linked_list.createNode(20);
  linked_list.createNode(30);
  linked_list.createNode(40);
  linked_list.displayList();
  return 0;
}
