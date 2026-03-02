/* INSERTION OPERATION IN CIRCULAR LINKED LIST */
#include <stdio.h>
#include <stdlib.h>

// create node
struct Node {
  int data;
  struct Node *next;
};

// defines
struct Node *tail;
struct Node *newnode;
struct Node *temp;

// length of the list
int length() {
  temp = tail->next;
  int length;

  while (temp != tail) {
    temp = temp->next;
    length++;
  }
  return length;
}

// display list
void display() {
  temp = tail->next;
  printf("\nElements in the list: [ ");

  int flag = 1;
  while (flag) {
    printf("%d -> ", temp->data);
    temp = temp->next;

    // break loop
    if (temp == tail->next) {
      flag = 0;
    }
  }
  printf("%d ]", tail->next->data);
}

// create circular linked list
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

// insert at the beginning of the list
void insertAtBeg(int item) {
  // create a newnode to insert
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  newnode->next = 0;

  // if list is empty
  if (tail == 0) {
    tail = newnode;
    tail->next = newnode;
  } else {
    newnode->next = tail->next;
    tail->next = newnode;
  }
  display();
}

// insert at the beginning of the list
void insertAtEnd(int item) {
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  newnode->next = 0;

  if (tail == 0) {
    tail = newnode;
    tail->next = newnode;
  } else {
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
  }
  display();
}

// insert at position
void insertAtPos(int item, int pos) {
  int len = length();
  if (pos > len || pos < 0) {
    printf("INVALID POSITION!!");
    return;
  } else if (pos == 0) {
    insertAtBeg(item);
  } else if (pos == 1 || pos == len + 1) {
    insertAtEnd(item);
  } else {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->next = 0;

    temp = tail->next;
    int i = 1;

    while (i < pos - 1) {
      temp = temp->next;
      i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
  }
  display();
}

// main
int main() {
  createCLL();
  insertAtBeg(444);
  insertAtEnd(777);
  insertAtPos(999, 3);
}
