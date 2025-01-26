#include <cstdio>
#include <iostream>
using namespace std;

/* CREATE NODE */
struct Node {
  int data;
  Node *prev;
  Node *next;
};

/* CREATE LINKED LIST */
class LinkedList {
private:
  Node *head;
  Node *newnode;
  Node *temp;

public:
  // initialize head null
  LinkedList() { head = nullptr; }

  /* DISPLAY LINKED LIST */
  void display() {
    temp = head;
    cout << endl << "Elements in the list: [ ";
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << " NULL ]" << endl;
  }

  /* LENGTH OF THE DLL */
  int length() {
    temp = head;
    int length = 0;
    while (temp != nullptr) {
      temp = temp->next;
      length++;
    }
    return length;
  }

  /* CREATE DOUBLY LL */
  void createDLL() {
    int num;
    cout << "Enter the number of nodes in the list: ";
    cin >> num;

    // add nodes
    for (int i = 0; i < num; i++) {
      newnode = new Node();
      cout << "Enter the data for node " << i << " : ";
      cin >> newnode->data;
      newnode->next = nullptr;
      newnode->prev = nullptr;

      if (head == nullptr) {
        head = newnode;
      } else {
        temp = head;
        while (temp->next != nullptr) {
          temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
      }
    }
    display();
  }

  /* INSERT AT THE BEGINNING OF DLL */
  void insertAtBeg(int item) {
    newnode = new Node();
    newnode->data = item;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    // if list is empty
    if (head == nullptr) {
      head = newnode;
      return;
    } else {
      head->prev = newnode;
      newnode->next = head;
      head = newnode;
      display();
    }
  }

  /* INSERT AT THE END OF THE LIST */
  void insertAtEnd(int item) {
    newnode = new Node();
    newnode->data = item;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    // if list is empty
    if (head == nullptr) {
      head = newnode;
    } else {
      temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newnode;
      newnode->prev = temp;
    }
    display();
  }

  /* INSERT AT SPECIFIC POSITION */
  void insertAtPos(int item, int pos) {
    // invalid position bound
    if (pos < 0 || pos > length()) {
      cout << "\nINVALID POSITION!" << endl;
    } else if (pos == 1) {
      // if position is 1 then just add it at the beginning
      insertAtBeg(item);
    } else {
      newnode = new Node();
      newnode->data = item;
      newnode->next = nullptr;
      newnode->prev = nullptr;

      // traverse till specified position
      temp = head;
      int i = 0;
      while (i < pos - 2) {
        temp = temp->next;
        i++;
      }
      newnode->next = temp->next;    // update newnode next address
      newnode->prev = temp;          // update newnode prev address
      temp->next = newnode;          // temp address
      newnode->next->prev = newnode; // update next node, from temp, address
      display();
    }
  }
};

int main(int argc, char *argv[]) {
  LinkedList linked_list;
  linked_list.createDLL();
  linked_list.insertAtBeg(777);
  linked_list.insertAtEnd(999);
  linked_list.insertAtPos(444, 3);
  return 0;
}
