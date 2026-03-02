/* INSERTION OPERATION IN DOUBLY CIRUCLAR LINKED LIST */
#include <stdio.h>
#include <stdlib.h>

// create node
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

// defines
struct Node *head;
struct Node *tail;
struct Node *newnode;
struct Node *temp;

// length of the list
int length() {
  temp = head;
  int length = 0;
  int flag = 1;
  while (flag) {
    temp = temp->next;
    length++;

    if (temp == tail->next) {
      flag = 0;
    }
  }
  return length;
}

// display
void display() {
  temp = head;
  int flag = 1;
  printf("Elements in the list: [ ");
  while (flag) {
    printf("%d <-> ", temp->data);
    temp = temp->next;

    if (temp == tail->next) {
      flag = 0;
    }
  }
  printf("%d ]\n", tail->next->data);
}

// create doubly circular linked list
void createDCLL() {
  head = 0;
  tail = 0;
  int arr[] = {10, 20, 30, 40, 50};
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < size; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = arr[i];

    if (head == 0) {
      head = newnode;
      tail = newnode;
      head->next = newnode;
      head->prev = newnode;
    } else {
      newnode->next = head;
      newnode->prev = tail;
      tail->next = newnode;
      head->prev = newnode;
      tail = newnode;
    }
  }
  display();
}

// insert at the beginning of the list
void insertAtBeg(int item) {
  // create a newnode
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;

  // check if list is empty
  if (head == 0) {
    head = newnode;
    tail = newnode;
    head->next = newnode;
    tail->next = newnode;
  } else {
    newnode->next = head;
    newnode->prev = tail;
    head->prev = newnode;
    tail->next = newnode;
    head = newnode;
  }
  display();
}

// insert at the end of the list
void insertAtEnd(int item) {
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;

  // check if list is empty
  if (head == 0) {
    head = newnode;
    tail = newnode;
    head->next = newnode;
    head->prev = newnode;
  } else {
    newnode->next = tail->next;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;
    tail = newnode;
  }
  display();
}

// insert at a specific position in the list
void insertAtPos(int pos, int item) {
  int len = length();
  if (pos <= 0 || pos > len) {
    printf("Invalid position!");
    exit(0);
  } else if (pos == 1) {
    insertAtBeg(55);
    exit(0);
  } else if (pos == len) {
    insertAtEnd(77);
    exit(0);
  }
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  int i = 1;
  temp = head;
  while (i < pos - 1) {
    temp = temp->next;
    i++;
  }
  newnode->next = temp->next;
  newnode->prev = temp;
  temp->next->prev = newnode;
  temp->next = newnode;
  display();
}

int main() {
  createDCLL();
  // insertAtBeg(77);
  // insertAtEnd(99);
  insertAtPos(3, 69);
  return 0;
}
