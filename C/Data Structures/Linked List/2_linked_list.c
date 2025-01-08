#include <stdio.h>
#include <stdlib.h>

/* Create node */
struct node {
  int data;          // data part
  struct node *next; // next part
};

// Insert nodes in list

void append(int d) {
  struct node *head, *temp, *newnode;
  head = 0;

  // create a node
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = d;
  newnode->next = 0;

  if (head == 0) {
    temp = head;
    head = newnode;
  } else {
    temp->next = newnode;
    temp = newnode;
  }

  // displau values
  temp = head;
  while (temp != 0) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
}

int main(int argc, char *argv[]) {
  append(10);
  append(20);
  // append(30);
  return 0;
}
