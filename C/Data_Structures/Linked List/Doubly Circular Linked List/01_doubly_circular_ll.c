/* IMPLEMENTATION OF DOUBLY CIRCULAR LINKED LIST */
#include <stdio.h>
#include <stdlib.h>

// create node data type for DCLL
struct Node {
  int data;          // data part
  struct Node *next; // stores address of next node
  struct Node *prev; // stores address of previous node
};

// defines
struct Node *head;
struct Node *tail;
struct Node *newnode;
struct Node *temp;

// display
void display() {
  temp = head;
  int flag = 1;
  printf("\nElements in the list: [ ");
  while (flag) {
    printf("%d <-> ", temp->data);
    temp = temp->next;

    if (temp == tail->next) {
      flag = 0;
    }
  }
  printf("%d ]", tail->next->data);
  printf("\nValue of tail: %d\n", tail->data);
  printf("Tail pointing to first node: %d\n", tail->next->data);
  printf("Value of head: %d\n", head->data);
  printf("Head pointing to last node: %d\n", head->prev->data);
}

// create doubly circular linked list
void creatDCLL() {
  // initialize head and tail null
  head = 0;
  tail = 0;

  int list[] = {10, 20, 30, 40, 50};
  int size = sizeof(list) / sizeof(list[0]);

  for (int i = 0; i < size; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = list[i];

    // NOTE: no need to initialize prev and next of newnode
    //  null since we're going to update them

    // check if list is empty
    if (head == 0) {
      // both head and tail point to newnode
      head = newnode;
      tail = newnode;

      // first node's next and prev parts points to itself
      head->next = newnode;
      head->prev = newnode;
    } else {
      newnode->next = head; // newnode pointing to head
      newnode->prev = tail; // newnode pointing to previous node
      head->prev = newnode; // head pointing to last node in the list newnode
      tail->next = newnode; // the previous node points to newnode
      tail = newnode;       // move tail
    }
  }
  display();
}

int main() {
  creatDCLL();
  return 0;
}
