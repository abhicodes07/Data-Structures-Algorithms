/* DOUBLY LINKED LIST IMPLEMENTATION */

#include <iostream>
using namespace std;

struct Node {
  int data;   // data part
  Node *next; // next part to store address of next node
  Node *prev; // Previous part to store address of previous node
};

class DoublyLinkedList {
private:
  Node *head;

public:
  DoublyLinkedList() { head = nullptr; }

  /* Display doubly linked list */
  void displayList(void) {
    Node *temp = head;
    cout << endl << "Elements in the list: [ ";
    while (temp) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << " NULL ]";
  }

  /* Create doubly linked list */
  void createDoublyList(void) {
    int num;
    cout << "Enter the number of nodes you want in list: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
      Node *newnode = new Node();
      cout << "Enter data for node " << i << " : ";
      cin >> newnode->data;
      newnode->next = nullptr;
      newnode->prev = nullptr;

      // if head is null and list is empty
      if (head == nullptr) {
        head = newnode;
      } else {
        Node *temp = head;
        while (temp->next != nullptr) { // traverse to the last node
          temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
      }
    }
    displayList();
  }
};

int main(int argc, char *argv[]) {
  DoublyLinkedList linked_list;
  linked_list.createDoublyList();
  return 0;
}
