#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;
struct Node *temp;
struct Node *newnode;
int count;

/* Create a linked list */
void createLinkedList() {
  // initialise head null
  head = 0;

  printf("Enter the number of elements in the list: ");
  scanf("%d", &count);

  // create newnode
  for (int i = 0; i < count; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for %d st node: ", i);
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (head == 0) {
      head = newnode;
    } else {
      temp = head;
      while (temp->next != 0) {
        temp = temp->next;
      }
      temp->next = newnode;
    }
  }
}

/* display list */
void displayList() {
  printf("\n[ ");
  temp = head;
  while (temp != 0) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL ]\n");
  printf("Number of elements in the list: %d\n\n", count);
}

/* Reverse the linked list */
void reverseList() {
  struct Node *currentnode = head;
  struct Node *nextnode = head;
  struct Node *prevnode = 0;

  while (nextnode != 0) {
    nextnode = nextnode->next;    // traverse the list
    currentnode->next = prevnode; // update address of currentnode
    prevnode = currentnode;       // move prevnode
    currentnode = nextnode;       // move currentnode
  }
  head = prevnode; // head points to last node at last
  displayList();
}

int main(void) {
  createLinkedList();
  displayList();
  reverseList();
  return 0;
}
