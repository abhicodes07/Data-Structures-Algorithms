/* IMPLEMENTATION OF STACK USING LINKED LIST */
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};

struct Node *top;
struct Node *temp;
struct Node *newnode;

// push element in stack
void push(int item) {
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = item;
  newnode->next = top;
  top = newnode;
  printf("%d pushed into stack.\n", newnode->data);
}

// pop element in stack
void pop() {
  temp = top;
  printf("%d popped.\n", top->data);
  top = top->next;
  free(temp);
}

// peek element
void peek() { printf("Top most element: %d\n", top->data); }

// display
void display() {
  temp = top;
  printf("Elements in the list: [ ");
  while (temp != 0) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf(" ]\n");
}

// minimum element in the list
void minimum() {
  int min = top->data;
  temp = top->next;
  while (temp != 0) {
    if (temp->data < min) {
      min = temp->data;
    }
    temp = temp->next;
  }
  printf("Minimum: %d\n", min);
}

// maximum element in the list
void maximum() {
  int max = top->data;
  temp = top->next;
  while (temp != 0) {
    if (temp->data > max) {
      max = temp->data;
    }
    temp = temp->next;
  }
  printf("Minimum: %d\n", max);
}

int main(int argc, char *argv[]) {
  push(10);
  push(5);
  push(30);
  push(3);
  push(6);
  display();
  peek();
  maximum();
  minimum();
  return 0;
}
