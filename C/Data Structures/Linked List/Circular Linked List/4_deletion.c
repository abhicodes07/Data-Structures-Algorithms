/* DELETION OPERATION IN CIRCULAR LINKED LIST */
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

// delete from the beginning of the list
void deleteFromBeg() {
  if (tail == 0) {
    printf("List is already empty!");
    exit(0);
  } else {
    temp = tail->next;
    tail->next = temp->next;
    temp->next = 0;
    printf("\n\nDeleted Node: [ %d ]", temp->data);
    display();
    free(temp);
  }
}

// delete from the end of the circular linked list
void deleteFromEnd() {
  if (tail == 0) {
    printf("List is already empty!");
    exit(0);
  } else {
    // current used for traversal and deleting last node
    current = tail->next;
    while (current->next != tail->next) {
      prevnode = current;
      current = current->next;
    }
    prevnode->next = tail->next;
    tail = prevnode;
    printf("\nDeleted Node: [ %d ]", current->data);
    display();
    free(current);
  }
}

// delete from specific position in the list
void deleteFromPos(int pos) {
  int len = length();
  if (pos < 1 || pos > len) {
    printf("Invalid position!");
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
    while (i < pos - 1) {
      current = current->next;
      i++;
    }
    nextnode = current->next;
    current->next = nextnode->next;
    printf("\nDeleted Node: [ %d ]", nextnode->data);
    display();
    free(nextnode);
  }
}

int main() {
  createCLL();
  // deleteFromEnd();
  // deleteFromBeg();
  deleteFromPos(3);
  return 0;
}
