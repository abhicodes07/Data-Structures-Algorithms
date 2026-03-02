#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head;
struct Node *tail;
struct Node *newnode;
struct Node *temp;

void display() {
  temp = head;
  printf("\nElements in the list: [ ");
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL ]");
}

void createDLL() {
  head = NULL;
  tail = NULL;
  int num;
  printf("Enter the number of nodes in the list: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for node %d: ", i);
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
      head = newnode;
      tail = newnode;
    } else {
      temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
      newnode->prev = temp;
      tail = newnode;
    }
  }
  display();
}

void reverse() {
  struct Node *current;
  struct Node *nextnode;

  current = head;

  while (current != NULL) {
    nextnode = current->next;
    current->next = current->prev;
    current->prev = nextnode;
    current = nextnode;
  }

  temp = head;
  head = tail;
  tail = temp;
  display();
}

int main(int argc, char *argv[]) {
  createDLL();
  reverse();
  return 0;
}
