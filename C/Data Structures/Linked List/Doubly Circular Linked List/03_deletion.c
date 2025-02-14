/* DELETION OPERATION IN LINKED LIST */
#include <stdio.h>
#include <stdlib.h>

// create a node
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

// delete a node from the beginning of the list
void deleteFromBeg() {
  temp = head;
  if (head == 0) {
    printf("List is empty!");
    exit(0);
  } else if (head == head->next) {
    // set head and tail null
    head = 0;
    tail = 0;
    free(temp);
    printf("LIST IS EMPTY!");
    exit(0);
  }

  head = head->next; // move head to next node
  head->prev = tail;
  tail->next = head;
  printf("\nDeleted Node: %d", temp->data);
  free(temp);
  display();
}

// delete a node from the end of the list
void deleteFromEnd() {
  temp = temp;
  if (head == 0) {
    printf("List is empty!");
    exit(0);
  } else if (head == head->next) {
    // set head and tail null
    head = 0;
    tail = 0;
    free(temp);
    printf("LIST IS EMPTY!");
    exit(0);
  }

  // move tail to one node back
  tail = tail->prev;
  tail->next = head;
  head->prev = tail;
  printf("\nDeleted Node: %d", temp->data);
  free(temp);
  display();
}

// delete from specific position in the list
void deleteFromPos(int pos) {
  int len = length();
  if (pos > len || pos < 0) {
    printf("INVALID POSITION!");
    exit(0);
  } else if (pos == 1) {
    deleteFromBeg();
    exit(0);
  } else if (pos == len) {
    deleteFromEnd();
    exit(0);
  }

  temp = head;
  int i = 1i;
  while (i < pos) {
    temp = temp->next;
    i++;
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  printf("\nDeleted Node: %d", temp->data);
  free(temp);
  display();
}

int main(int argc, char *argv[]) {
  createDCLL();
  deleteFromBeg();
  deleteFromEnd();
  deleteFromPos(3);
  return 0;
}
