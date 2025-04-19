// implementation of queue on linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *newnode;
struct Node *rear = NULL;
struct Node *front = NULL;

// enqueue or insert element
void enqueue(int x) {
  struct Node *temp;

  // create a node
  newnode = (struct Node *)malloc(sizeof(struct Node));

  newnode->data = x;
  newnode->next = 0;

  if (rear == NULL) {
    front = newnode;
    rear = newnode;
    printf("Enqueued: %d\n", rear->data);
  } else {
    rear->next = newnode;
    rear = newnode;
    printf("Enqueued: %d\n", rear->data);
  }
}

// dequeue or delete from queue
void dequeue() {
  struct Node *temp;

  if (front == NULL) {
    printf("Queue is empty!");
    return;
  }

  temp = front;
  front = front->next;
  printf("Dequeued: %d\n", temp->data);
  free(temp);

  if (rear == NULL) {
    front = NULL;
  }
}

// display
void display() {
  struct Node *temp;
  // displau values
  temp = front;
  printf("Elements in the list: [ ");
  while (temp != 0) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL ]\n");
}

int main() {
  enqueue(10);
  enqueue(20);
  display();
  dequeue();
  display();
  return 0;
}
