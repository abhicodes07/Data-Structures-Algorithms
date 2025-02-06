/* IMPLEMENTATION OF INSERTION OPERATION IN CIRCULAR LINKED LIST */
#include <cstdlib>
#include <iostream>

using namespace std;

// create node
struct Node {
  int data; // data part
  Node *next;
};

// circular linked list
class CircularLL {
private:
  Node *tail;
  Node *temp;
  Node *newnode;

public:
  CircularLL() { tail = nullptr; }

  // create cll
  void createCLL() {
    int list[] = {10, 20, 30, 40, 50};
    int size = sizeof(list) / sizeof(list[0]);

    for (int i = 0; i < size; i++) {
      newnode = (struct Node *)malloc(sizeof(struct Node));
      newnode->data = list[i];
      newnode->next = nullptr;

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

  // display the list
  void display() {
    temp = tail->next;
    cout << "Elements in the list: [ ";
    while (true) {
      cout << temp->data << " -> ";
      temp = temp->next;

      if (temp == tail->next) {
        break;
      }
    }
    cout << tail->next->data << " ]" << endl;
  }

  // length of the linked list
  int length() {
    temp = tail->next;
    int length = 0;

    while (true) {
      temp = temp->next;
      length++;

      if (temp == tail->next) {
        break;
      }
    }
    return length;
  }

  // insert the beginning of the list
  void insertAtBeg(int item) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->next = 0;

    if (tail == nullptr) {
      tail = newnode;
      tail->next = newnode;
    } else {
      newnode->next = tail->next;
      tail->next = newnode;
    }
    display();
  }

  // insert at the end of the list
  void insertAtEnd(int item) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->next = 0;

    if (tail == nullptr) {
      tail = newnode;
      tail->next = newnode;
    } else {
      newnode->next = tail->next;
      tail->next = newnode;
      tail = newnode;
    }
    display();
  }

  // insert at the specific position in the list
  void insertAtPos(int pos, int item) {
    int len = length();
    if (pos < 0 || pos > len) {
      cout << "INVALID POSITION";
      exit(0);
    } else if (pos == 1) {
      insertAtBeg(item);
    } else if (pos == len) {
      insertAtEnd(item);
    } else {
      newnode = (struct Node *)malloc(sizeof(struct Node));
      newnode->data = item;
      newnode->next = 0;

      int i = 1;
      temp = tail->next;

      while (i < pos - 1) {
        temp = temp->next;
        i++;
      }

      newnode->next = temp->next;
      temp->next = newnode;
    }
    display();
  }
};

int main(int argc, char *argv[]) {
  CircularLL linked_list;
  linked_list.createCLL();
  linked_list.insertAtPos(3, 666);
  return 0;
}
