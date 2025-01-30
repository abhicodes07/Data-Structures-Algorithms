#include <iostream>
using namespace std;

/* Create a node data type */
struct Node {
  int data;   // data
  Node *prev; // previous
  Node *next; // next
};

/* Create a linked list */
class LinkedList {
private:
  Node *head;
  Node *tail;
  Node *newnode;
  Node *temp;
  Node *current;
  Node *nextnode;

public:
  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  /* display the list */
  void display() {
    temp = head;
    cout << endl << "Elements in the list: [";
    while (temp != NULL) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << " NULL ]" << endl;
  }

  /* create a doubly linked list */
  void createDLL() {
    int num;
    cout << "Enter the number of nodes: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
      // create a newnode
      newnode = new Node();
      cout << "Enter the data for node " << i << ": ";
      cin >> newnode->data;

      if (head == NULL) {
        head = newnode;
        tail = newnode;
      } else {
        temp = head;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
      }
    }
    display();
  }

  /* reverse the list */
  void reverse() {
    current = head;

    while (current != NULL) {
      nextnode = current->next;
      current->next = current->prev;
      current->prev = nextnode;
      current = nextnode;
    }
    nextnode = head;
    head = tail;
    tail = nextnode;
    display();
  }
};

int main(int argc, char *argv[]) {
  LinkedList linked_list;
  linked_list.createDLL();
  linked_list.reverse();
  return 0;
}
