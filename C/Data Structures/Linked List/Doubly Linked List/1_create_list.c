/* DOUBLY LINKED LIST IMPLEMETATION */

// Create a doubly linked list node
#include <stdio.h>
#include <stdlib.h>
struct Node {
  struct Node *next; // next pointer part
  struct Node *prev; // previous pointer part
  int data;          // data part
};

// Declare globally
struct Node *head;
struct Node *newnode;
struct Node *temp;
int count;

/* Create a linked list */
void createDoublyLinkedList(void) {
  head = 0;

  printf("Enter the number of elements in the list: ");
  scanf("%d", &count);

  for (int i = 0; i < count; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for %d st node: ", i);
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;

    // if head is empty or list is empty
    if (head == 0) {
      head = newnode;
    } else {
      temp = head;
      while (temp->next != 0) {
        temp = temp->next; // move temp to newnode
      }
      temp->next = newnode; // update next part of previous node
      newnode->prev = temp; // update prev part of next node
    }
  }
}

/* Display created node */
void displayList(void) {
  temp = head;
  printf("\nElements in list: [ ");
  while (temp) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL ]");
}

int main(int argc, char *argv[]) {
  createDoublyLinkedList();
  displayList();
  return 0;
}
