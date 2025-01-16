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

/* display list */
void displayList() {
  printf("\nElements in the list: [ ");
  temp = head;
  while (temp != 0) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL ]\n");
}

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
  displayList();
}

/*** INSERTION OPERATIONS ***/

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

/*** DELETION OPERATIONS ***/

/* Delete from the beginning of the list */
void deleteFromBeginning() {
  temp = head;
  if (temp == 0) {
    printf("List is already empty!\n");
    exit(1);
  } else {
    // move head to the second node in the list
    head = head->next;

    // free memory of the node and print the deleted data
    printf("\nDeleted Node: [ %d ]", temp->data);
    free(temp);
    count--;
  }
  displayList();
}

/* Delete from the end */
void deleteFromEnd() {
  struct Node *prevnode;
  temp = head;

  while (temp->next != 0) {
    prevnode = temp;
    temp = temp->next;
  }

  // if there's only single node in the list
  if (temp == head) {
    head = 0;
    free(temp);
  } else {
    prevnode->next = 0;
    printf("\nDelete Node: [ %d ]", temp->data);
    displayList();
    free(temp);
  }
}

/* Delete from specific position */
void deleteFromPos(int position) {
  struct Node *nextnode;
  int i = 1;

  temp = head;

  while (i < position - 1) {
    temp = temp->next;
    i++;
  }

  nextnode = temp->next;
  temp->next = nextnode->next;
  printf("\nDelete Node: [ %d ]", nextnode->data);
  free(nextnode);
  displayList();
}

int main(int argc, char *argv[]) {
  createLinkedList();
  deleteFromEnd();
  deleteFromPos(3);
  return 0;
}
