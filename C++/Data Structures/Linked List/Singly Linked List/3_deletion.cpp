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

  /* Length of the linked list */
  int length() {
    Node *temp = head;
    int len = 0;
    while (temp != nullptr) {
      temp = temp->next;
      len++;
    }
    return len;
  }

  /* Display Linked List */
  void displayList(void) {
    temp = head;

    cout << "Elements in list: [ ";
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << " NULL ]\n" << endl;
    cout << "Length: " << length() << endl;
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
