#include "stdio.h"
#include "stdlib.h"

// creaete a node
struct Node {
  int data;          // data part
  struct Node *next; // next part
};

// defines
struct Node *newnode;
struct Node *temp;
struct Node *tail;
struct Node *current;
struct Node *nextnode;
struct Node *prevnode;

// display
void display() {
  temp = tail->next;
  printf("\nElements in the list: [ ");
  int flag = 1;
  while (flag) {
    printf("%d -> ", temp->data);
    temp = temp->next;

    if (temp == tail->next) {
      break;
    }
  }
  printf("%d ]", tail->next->data);
}

// length of the list
int length() {
  int length = 0;
  temp = tail->next;
  int flag = 1;
  while (flag) {
    temp = temp->next;
    length++;

    if (temp == tail->next) {
      break;
    }
  }
  return length;
}

// create a cirular linked list
void createCLL() {
  tail = 0;
  int num;
  printf("Enter the number of nodes in the list: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for node %d: ", i);
    scanf("%d", &newnode->data);
    newnode->next = 0;

    // if list is empty
    if (tail == 0) {
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

// reverse a circular linked list
void reverse() {
  struct Node *current, *prevnode, *nextnode;

  if (tail == 0) {
    printf("LIST IS EMPTY");
    exit(0);
  } else if (tail->next == tail) {
    display();
    exit(0);
  }

  // current points to first node
  current = tail->next;
  nextnode = current->next;

  while (current != tail) {
    prevnode = current;       // move prevnode to current
    current = nextnode;       // move current to nextnode
    nextnode = current->next; // move nextnode
    current->next = prevnode; // update current
  }
  nextnode->next = tail; // points to first node after reversal
  tail = nextnode;
  display();
}

int main(int argc, char *argv[]) {
  createCLL();
  reverse();
  return 0;
}
