#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// define queue
typedef struct queue {
  int front;
  int rear;
  int queue[MAX];
} Queue;

int queue[MAX];

// initialize queue
void initQueue(Queue *q) {
  q->front = -1;
  q->rear = -1;
}

// insert element in queue
// Reminder = Dividend - (Divisor * quotient)
void enqueue(Queue *q, int data) {
  // assuming rear = 9 then
  // 9 + 1 % 10 = 10 % 10 = 0
  // which equals to front, making the queue
  // circular when full
  if ((q->rear + 1) % MAX == q->front) {
    printf("Queue is full!\n");
    return;
  } else if (q->front == -1 && q->rear == -1) {
    q->front++;
    q->rear++;
    q->queue[q->rear] = data;
    printf("%d enqueue.\n", q->queue[q->rear]);
  } else {
    q->rear = q->rear + 1 % MAX;
    q->queue[q->rear] = data;
    printf("%d enqueue.\n", q->queue[q->rear]);
  }
}

// dequeue elements
void dequeue(Queue *q) {
  if (q->front == -1 && q->rear == -1) {
    printf("List is empty!\n");
    return;
  } else if (q->rear == 0 && q->front == 0) {
    printf("%d dequeued.\n", q->queue[q->front]);
    q->rear = -1;
    q->front = -1;
  } else {
    printf("%d dequeued.\n", q->queue[q->front]);
    q->front = (q->front + 1) % MAX;
  }
}

// display elements
void display(Queue *q) {
  if (q->front == -1 && q->rear == -1) {
    printf("List is empty!\n");
    return;
  }
  int i = q->front;
  printf("Elements in the list: ");
  while (i <= q->rear) {
    printf("%d ", q->queue[i]);
    i++;
  }
  printf("\n");
}

// main
int main(int argc, char *argv[]) {
  Queue q;
  initQueue(&q);
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);
  enqueue(&q, 60);
  display(&q);
  dequeue(&q);
  dequeue(&q);
  display(&q);
}
