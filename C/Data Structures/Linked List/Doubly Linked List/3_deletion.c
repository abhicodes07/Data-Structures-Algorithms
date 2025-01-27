#include <stdio.h>
#include <stdlib.h>

// create node data type
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

// defines
struct Node *head;
struct Node *temp;
struct Node *newnode;
struct Node *tail;
struct Node *prevnode;

// display list
void display() {
  temp = head;
  printf("\nElements in the list: [ ");
  while (temp != 0) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf(" NULL ]\n");
}

// length of the list
int length() {
  temp = head;
  int length = 0;
  while (temp != 0) {
    temp = temp->next;
    length++;
  }
  return length;
}

// create list
void createDll() {
  head = 0; // initialize head empty
  int num;
  printf("Enter the number of nodes in the list: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for node %d: ", i);
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;

    // if list is empty no need to traverse
    if (head == 0) {
      head = newnode;
    } else {
      temp = head;
      while (temp->next != 0) {
        temp = temp->next;
      }
      temp->next = newnode;
      newnode->prev = temp;
    }
  }
  display();
}

// delete from the beginning of the list
void deleteFromBeg() {
  if (head == 0) { // Check if the list is empty
    printf("List is empty!!\n");
    return;
  } else {
    temp = head;       // Store the current head
    head = head->next; // Move head to the next node

    if (head != NULL) { // If there are still nodes in the list
      head->prev = 0;
    }

    printf("\nDeleted Node: %d", temp->data); // Print the deleted node
    free(temp); // Free the memory of the deleted node

    display(); // Display the updated list
  }
}

// delete from the end of the list
void deleteFromEnd() {
  if (head == 0) {
    printf("List is empty!!\n");
    return;
  } else {
    temp = head;
    while (temp->next != 0) {
      temp = temp->next;
    }
    prevnode = temp->prev;
    prevnode->next = 0;
    printf("\nDeleted Node: %d", temp->data);
    free(temp);

    display();
  }
};

// delete from the specific position
void deleteFromPos(int pos) {
  int len = length();

  if (pos < 0 || pos > len) {
    printf("INVALID POSITION!");
    return;
  } else if (pos == 1) {
    deleteFromBeg();
    return;
  } else if (pos == len) {
    deleteFromEnd();
    return;
  } else {
    int i = 1;
    temp = head;

    while (i < pos && temp != 0) {
      temp = temp->next;
      i++;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("\nDeleted Node: %d", temp->data);
    free(temp);

    display();
  }
};

int main(int argc, char *argv[]) {
  createDll();
  deleteFromBeg();
  deleteFromEnd();
  deleteFromPos(3);
}
