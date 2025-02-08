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

  // delete from beginning of the circular linked list
  void deleteFromBeg() {
    temp = tail->next;
    if (tail == nullptr) {
      cout << "List is empty!!" << endl;
      exit(0);
    } else if (tail->next == tail) {
      cout << "Deleted Node: [ " << temp->data << " ]";
      temp = nullptr;
      cout << "List is empty!" << endl;
    } else {
      tail->next = temp->next;
      cout << "Deleted Node: [ " << temp->data << " ]" << endl;
      free(temp);
      display();
    }
  }

  // delete from end of the circular linked list
  void deleteFromEnd() {
    Node *current, *prevnode;
    current = tail->next;
    if (tail == nullptr) {
      cout << "List is empty!!" << endl;
      exit(0);
    } else if (current->next == current) {
      cout << "Deleted Node: [ " << current->data << " ]" << endl;
      free(current);
      cout << "List is empty!" << endl;
    } else {
      while (current != tail) {
        prevnode = current;
        current = current->next;
      }
      prevnode->next = current->next;
      tail = prevnode; // move tail
      cout << "Deleted Node: [ " << current->data << " ]" << endl;
      free(current);
      display();
    }
  }

  // delete from the specific position of the circular linked list
  void deleteFromPos(int pos) {
    Node *current, *nextnode;
    int len = length();
    if (pos < 0 || pos > len) {
      cout << "INVALID POSITION" << endl;
      exit(0);
    } else if (pos == 1) {
      deleteFromBeg();
      exit(0);
    } else if (pos == len) {
      deleteFromEnd();
      exit(0);
    } else {
      int i = 1;
      current = tail->next;
      // traverse till position - 1
      while (i < pos - 1) {
        current = current->next;
        i++;
      }
      nextnode = current->next; // on position
      current->next = nextnode->next;
      cout << "Deleted Node: [ " << nextnode->data << " ]" << endl;
      free(nextnode);
      display();
    }
  }
};

int main(int argc, char *argv[]) {
  CircularLL linked_list;
  linked_list.createCLL();
  // linked_list.deleteFromBeg();
  // linked_list.deleteFromEnd();
  linked_list.deleteFromPos(3);
  return 0;
}
