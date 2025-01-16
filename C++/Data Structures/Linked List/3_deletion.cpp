#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;

/* Create Node data type of 8 bytes */
struct Node {
  int data;   // data part
  Node *next; // next part
};

class LinkedList {
private:
  Node *head;
  Node *temp;

public:
  // Initialise head NULL
  LinkedList() { head = nullptr; }

  /* Display Linked List */
  void displayList(void) {
    temp = head;

    cout << "Elements in list: [ ";
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << " NULL ]\n" << endl;
  }

  /* Create Linked List */
  void creatLinkedList(void) {
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
        temp = head;
        while (temp->next != nullptr) {
          temp = temp->next;
        }
        temp->next = newnode;
      }
    }
    displayList();
  }

  /*** INSERTION OPERATIONS ***/

  /* Insert at beginning of the list */
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

  /* Insert at the end of the linked list */
  void insertAtEnd(int item) {
    Node *newnode = new Node();
    newnode->data = item;
    newnode->next = nullptr;

    if (head == nullptr) {
      head = newnode;
    } else {
      temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newnode;
    }
    displayList();
  }

  /* Insert at specific position in the linked list */
  void insertAtPosition(int item, int position) {
    Node *newnode = new Node();
    if (!newnode) {
      exit(1);
    }
    newnode->data = item;
    temp = head;
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

  /*** DELETION OPERATIONS ***/

  /* Delete from the beginning */
  void deleteFromBeginning(void) {
    temp = head;

    if (temp == nullptr) {
      head = 0;
      free(temp);
    } else {
      head = head->next;
      cout << "\nDeleted Node: " << temp->data << endl;
      displayList();
      free(temp);
    }
  }

  /* Delete from the end */
  void deleteFromEnd() {
    Node *prevnode;
    temp = head;

    while (temp->next != 0) {
      prevnode = temp;
      temp = temp->next;
    }

    // if there's only single node in the list
    if (temp == head) {
      head = 0;
      free(temp);
    } else {
      prevnode->next = 0;
      cout << "Delete Node: " << temp->data << endl;
      displayList();
      free(temp);
    }
  }

  /* Delete from specific position */
  void deleteFromPos(int position) {
    Node *nextnode;
    int i = 1;

    temp = head;

    while (i < position - 1) {
      temp = temp->next;
      i++;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    cout << "Delete Node: " << nextnode->data << endl;
    displayList();
    free(nextnode);
  }
};

int main(int argc, char *argv[]) {
  LinkedList linked_list;
  linked_list.creatLinkedList();
  linked_list.deleteFromPos(3);
  return 0;
}
