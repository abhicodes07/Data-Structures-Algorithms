/* IMPLEMENTATION OF CIRCULAR LINKED LIST USING ONLY SINGLE TAIL POINTER*/
#include <stdio.h>
#include <stdlib.h>

// create node data type
struct Node {
  int data; // data part
  struct Node *next;
};

// defines
struct Node *tail;
struct Node *newnode;
struct Node *temp;

void display() {
  temp = tail->next; // points to first node using last node
  printf("\nElements in the list: [ ");

  int flag = 1;
  while (flag) {
    printf("%d -> ", temp->data);
    temp = temp->next;

    if (temp == tail->next) {
      flag = 0;
    }
  }
  // print first node to make circular
  printf("%d ]", tail->next->data);

  // NOTE: using do while loop
  temp = tail->next; // points to first node using last node
  printf("\nElements in the list: [ ");
  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != tail->next);
  printf("%d ]", tail->next->data);
}

// create circular linked list
void createCLL() {
  tail = 0;
  int num;
  printf("Enter the number of elements in the list: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for the node %d: ", i);
    scanf("%d", &newnode->data); // or use: newnode->data for simplicity
    (*newnode).next = 0;

    if (tail == 0) {
      tail = newnode;
      // since it's the first and last node, it points to itself
      tail->next = newnode;
    } else {
      // since there's only one pointer; tail
      // update next part of newnode first and then move tail to newnode
      newnode->next = tail->next;

      // update next of previous node
      tail->next = newnode;

      // move tail to newnode
      tail = newnode;
    }
  }
  display();
}

int main() {
  createCLL();
  return 0;
}
