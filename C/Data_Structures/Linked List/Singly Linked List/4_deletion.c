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

/* Length of the linked list */
int length() {
  temp = head;
  int len = 0;
  while (temp != 0) {
    temp = temp->next;
    len++;
  }
  return len;
}

/* display list */
void displayList() {
  printf("\nElements in the list: [ ");
  temp = head;
  while (temp != 0) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL ]\n");
  printf("Length: %d\n", length());
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
    printf("\nDeleted Node: [ %d ]", temp->data);
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
  printf("\nDeleted Node: [ %d ]", nextnode->data);
  displayList();
  free(nextnode);
}

int main(int argc, char *argv[]) {
  createLinkedList();
  deleteFromBeginning();
  deleteFromEnd();
  deleteFromPos(3);
  return 0;
}
