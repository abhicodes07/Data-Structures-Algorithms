#include <cstdlib>
#include <iostream>
using namespace std;

// Create a Node data type
struct Node {
  int data;
  Node *prev = nullptr;
  Node *next = nullptr;
};

// Doubly linked list class
class DoublyLinkedList {
private:
  Node *head;
  Node *newnode;
  Node *temp;
  Node *tail;

public:
  // create a doubly linked list
  DoublyLinkedList() {
    head = nullptr; // initialize head null
  }

  // lenght of the list
  int length() {
    temp = head;
    int length;
    while (temp) {
      temp = temp->next;
      length++;
    }
    return length;
  }

  // display list
  void display() {
    temp = head;
    cout << "Elements in the list: [ ";
    while (temp) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL ]" << endl;
  }

  // create a doubly linked list
  void createDLL() {
    int num;

    cout << "Enter the number of nodes in the list: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
      newnode = new Node();
      cout << "Enter the data for node " << i << ": ";
      cin >> newnode->data; // store data

      if (head == nullptr) { // check if list is empty
        head = newnode;
        tail = newnode;
      } else {
        temp = head;
        while (temp->next != nullptr) { // traverse till last node in the list
          temp = temp->next;
        }
        temp->next = newnode; // update next address of the last node to newnode
        newnode->prev = temp; // update previous address of the newnode
        tail = newnode;
      }
    }
    display();
  }

  // delete from the beginning of the list
  void deleteFromBeg() {
    if (head == nullptr) { // check if the list is empty
      cout << "List is already empty!";
      return;
    } else {
      temp = head;       // store the current head
      head = head->next; // move head to the next node;
    }

    // free node and display deleted node
    cout << endl << "Deleted node: " << temp->data << endl;
    free(temp);
    display();
  }

  // delete from the end of the list
  void deleteFromEnd() {
    if (head == nullptr) { // check if list is empty
      cout << "List is empty!!" << endl;
      return;
    } else {
      temp = tail;       // temp points towards maintained tail
      tail = tail->prev; // move tail to one node previous
      tail->next = 0;

      // free node and display deleted node
      cout << endl << "Deleted node: " << temp->data << endl;
      free(temp);
      display();
    }
  }

  // delete from the specific position
  void deleteFromPos(int pos) {
    int len = length();
    if (pos < 0 || pos > len) { // check position bound
      cout << "INVALID POSITION" << endl;
      return;
    } else if (pos == 1) { // if position is first node, call function
      deleteFromBeg();
      return;
    } else if (pos == len) { // if position is last node, call function
      deleteFromEnd();
      return;
    } else {
      int i = 1;
      temp = head;

      // move temp to desired position
      while (i < pos && temp != 0) {
        temp = temp->next;
        i++;
      }
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;

      // free node and display deleted node
      cout << endl << "Deleted node: " << temp->data << endl;
      free(temp);
      display();
    }
  }
};

int main(int argc, char *argv[]) {
  DoublyLinkedList linked_list;
  linked_list.createDLL();
  linked_list.deleteFromPos(3);
  return 0;
}
