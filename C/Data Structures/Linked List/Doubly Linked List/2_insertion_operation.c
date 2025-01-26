#include <stdio.h>
#include <stdlib.h>

/* CREATE NODE DATA TYPE */
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

// defines
struct Node *head;
struct Node *temp;
struct Node *newnode;

/* LENGTH OF THE LIST */
int length() {
  temp = head;
  int length = 0;
  while (temp != 0) {
    temp = temp->next;
    length++;
  }
  return length;
}

/* DISPLAY LIST */
void display() {
  temp = head;
  printf("\nElements in the list: [ ");
  while (temp != 0) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf(" NULL ]");
}

/* CREATE DOUBLY LL */
void createDLL() {
  head = 0;
  int num;
  printf("Enter the number of nodes in the list: ");
  scanf("%d", &num);

  // add nodes
  for (int i = 0; i < num; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for node %d: ", i);
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    if (head == 0) {
      head = newnode;
    } else {
      temp = head;
      // traverse till last node
      while (temp->next != 0) {
        temp = temp->next;
      }
      temp->next = newnode;
      newnode->prev = temp;
    }
  }
  display();
}

/* INSERT AT THE END OF THE DLL */
void insertAtEnd(int item) {
  temp = head;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  newnode->next = 0;
  newnode->prev = 0;

  // if list is head don't move further
  if (head == 0) {
    head = newnode;
  } else {
    // traverse till last node in the list
    while (temp->next != 0) {
      temp = temp->next;
    }

    temp->next = newnode; // update next part of last node to newnode
    newnode->prev = temp; // update prev part of the newnode to last node
  }
  display();
}

/* INSERT AT THE BEGINNING OF THE DLL */
void insertAtBeg(int item) {
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  newnode->next = 0;
  newnode->prev = 0;

  if (head == 0) {
    head = newnode;
  } else {
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
    display();
  }
}

/* INSERT AT SPECIFIC POSITION */
void insertAtPos(int item, int pos) {
  // invalid position bound
  if (pos < 0 || pos > length()) {
    printf("\nINVALID POSITION!");
    exit(1);
  } else if (pos == 1) {
    // if position is 1 then just add it at the beginning
    insertAtBeg(item);
  } else {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->next = 0;
    newnode->prev = 0;

    // traverse till specified position
    temp = head;
    int i = 0;
    while (i < pos - 2) {
      temp = temp->next;
      i++;
    }
    newnode->next = temp->next;    // update newnode next address
    newnode->prev = temp;          // update newnode prev address
    temp->next = newnode;          // temp address
    newnode->next->prev = newnode; // update next node, from temp, address
    display();
  }
}

int main(int argc, char *argv[]) {
  createDLL();
  insertAtBeg(100);
  insertAtEnd(777);
  insertAtPos(000, 3);
  return 0;
}
