#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// create a queue
typedef struct queue {
  int front;
  int rear;
  int queue[MAX];
} Queue;

// initialize the queue
void initQueue(Queue *q) {
  q->front = -1;
  q->rear = -1;
}

int isFull(Queue *q) { return (q->rear + 1) % MAX == q->front; }
int isEmpty(Queue *q) { return q->front == -1 && q->rear == -1; }

// enqueue element using front
void enqueueFront(Queue *q, int data) {
  if (isFull(q)) {
    printf("Queue is full!\n");
    return;
  } else if (isEmpty(q)) {
    // when queue is initialized
    // front will initially store the value
    // at 0 and then move backwards
    q->rear = 0;
    q->front = 0;
    q->queue[q->front] = data;
    printf("Front: %d\n", q->front);
    printf("%d enqueued.\n", q->queue[q->front]);
  } else if (q->front == 0) {
    q->front = MAX - 1;
    q->queue[q->front] = data;
    printf("Front: %d\n", q->front);
    printf("%d enqueued.\n", q->queue[q->front]);
  } else {
    q->queue[--q->front] = data;
    printf("Front: %d\n", q->front);
    printf("%d enqueued.\n", q->queue[q->front]);
  }
}

// enqueue element using rear
void enqueueRear(Queue *q, int data) {
  if (isFull(q)) {
    printf("Queue is full!\n");
    return;
  } else if (q->rear == -1 && q->front == -1) {
    q->front = 0;
    q->rear = 0;
    q->queue[q->front] = data;
    printf("%d enqueued.\n", q->queue[q->rear]);
  } else if (q->rear == MAX - 1) {
    q->rear = 0;
    printf("this invoked");
    printf("%d enqueued.\n", q->queue[q->rear]);
  } else {
    q->queue[++q->rear] = data;
    printf("%d enqueued.\n", q->queue[q->rear]);
  }
}

// dequeue element using front
void dequeueFront(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
    return;
  } else if (q->front == q->rear) {
    // when front and rear are equal,
    // there's only single element
    printf("%d dequeued.\n", q->queue[q->front]);
    q->front--;
    q->rear--;
  } else if (q->front == MAX - 1) {
    printf("%d dequeued.\n", q->queue[q->front]);
    q->front = 0;
  } else {
    printf("%d dequeued.\n", q->queue[q->front]);
    q->front++;
  }
}

// dequeue element using rear
void dequeueRear(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
    return;
  } else if (q->front == q->rear) {
    printf("%d dequeued.\n", q->queue[q->rear]);
    q->front = -1;
    q->rear = -1;
  } else if (q->rear == 0) { // if only rear is 0 and front is not
    printf("%d dequeued.\n", q->queue[q->rear]);
    q->front = MAX - 1;
  }
}

// display the de-queue
void display(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
    return;
  }

  int i = q->front;
  printf("Elements in the list: ");
  while (i != q->rear) {
    printf("%d ", q->queue[i]);
    i = (i + 1) % MAX;
  }
  // print the last element as the loop stops
  // i = 0, when i = (4 + 1) % 5; i = 0
  // without printing it
  printf("%d \n", q->queue[q->rear]);
}

// main
int main(int argc, char *argv[]) {
  Queue q;
  initQueue(&q);
  enqueueFront(&q, 20); // 4
  enqueueRear(&q, 10);  // 0
  display(&q);
  return EXIT_SUCCESS;
}
