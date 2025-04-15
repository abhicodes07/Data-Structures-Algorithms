// implementation of queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct node *temp;

// create a node
struct node {
  int data;
  struct node *next;
};

// create a queue
struct queue {
  struct node *front;
  struct node *rear;
};

// initialize queue
void initQueue(struct queue *q) {
  q->front = NULL;
  q->rear = NULL;
}

// insertion operation: append element
void enqueue(struct queue *q, int x) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->next = NULL;
  newnode->data = x;

  if (q->rear == NULL) {
    q->rear = newnode;
    q->front = newnode;
    printf("Enqueued: %d\n", q->rear->data);
  } else {
    q->rear->next = newnode;
    q->rear = newnode;
    printf("Enqueued: %d\n", q->rear->data);
  }
}

// deletion operation: remove an element
void dequeue(struct queue *q) {
  if (q->front == NULL) {
    printf("Queue is empty!");
    return;
  }

  struct node *temp = q->front;
  q->front = q->front->next;
  printf("Dequeued: %d\n", temp->data);
  free(temp);
}

// display queue
void display(struct queue *q) {
  struct node *temp = q->front;
  printf("Elements in the list: [ ");
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL ]\n");
}

int main() {
  struct queue q1;
  initQueue(&q1);
  enqueue(&q1, 10);
  enqueue(&q1, 20);
  enqueue(&q1, 30);
  display(&q1);
  dequeue(&q1);
  display(&q1);
  return 0;
}
