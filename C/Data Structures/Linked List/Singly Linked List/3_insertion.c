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

/* Insert node at the beginning */
void insertAtBeginning(int item) {
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  count++;

  if (head == 0) {
    head = newnode;
    /*
     * If there's only one node then
     * no need to further execute
     */
    return;
  } else {
    newnode->next = head; // store the address of first node in the newnode
    head = newnode;       // store address of new node into head
  }
}

/* Insert node at the end */
void insertAtEnd(int item) {
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  count++;

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

/* Insert node at certain position */
void insertAtPosition(int item) {
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  count++;
  int pos, i = 0;

  printf("Enter the position: ");
  scanf("%d", &pos);

  if (pos > count) {
    printf("\nINVALID POSITION!");
  } else if (pos == 0) {
    newnode->next = head;
    head = newnode;
  } else {
    temp = head;
    while (i < pos - 1) {
      temp = temp->next;
      i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
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

int main(int argc, char *argv[]) {
  createLinkedList();
  insertAtBeginning(5);
  insertAtEnd(60);
  insertAtPosition(100);
  displayList();
  return 0;
}
