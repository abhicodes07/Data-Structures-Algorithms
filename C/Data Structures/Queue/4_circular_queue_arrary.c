// Implementation of cicular queue using array and queue encapsulation
#include <stdio.h>
#define MAX 5

// create queue
struct Queue {
  int front;
  int rear;
};

int queue[MAX];

// initialize queue
void initQueue(struct Queue *q) {
  q->front = -1;
  q->rear = -1;
}

// insert element in a queue
void enqueue(struct Queue *q, int val) {
  printf("\n");

  // if queue is empty
  if (q->rear == -1 && q->front == -1) {
    q->front = 0;
    q->rear = 0;
    queue[q->rear] = val;
    printf("REAR: %d\n", q->rear);
    printf("FRONT: %d\n", q->front);
    printf("Enqueued: %d\n", val);
  }

  // overflow error
  else if ((q->rear + 1) % MAX == q->front) {
    printf("Queue is currently full! Overflow");
  }

  else {
    q->rear = (q->rear + 1) % MAX;
    queue[q->rear] = val;
    printf("Enqueued: %d\n", val);
  }
}

// remove element from the queue
void dequeue(struct Queue *q) {
  printf("\n");
  if (q->front < 0 && q->rear < 0) {
    printf("Queue is empty!");
  }

  else if (q->front == 0 && q->rear == 0) {
    printf("Dequeued: %d\n", queue[q->front]);
    q->front = -1;
    q->rear = -1;
  }

  else {
    printf("Dequeued: %d\n", queue[q->front]);
    q->front = (q->front + 1) % MAX;
    printf("REAR: %d\n", q->rear);
    printf("FRONT: %d\n", q->front);
  }
}

// display queue elements
void display(struct Queue *q) {
  if (q->front == -1 && q->rear == -1) {
    printf("Queue is empty!, Nothing to do display.");
  }

  else {
    int temp = q->front;
    printf("Elements in the list: ");
    while (temp != q->rear) {
      printf("%d ", queue[temp]);
      temp = (temp + 1) % MAX;
    }
    printf("%d\n", queue[temp]);
  }
}

void isFull(struct Queue *q) {
  if (q->rear > MAX - 1)
    printf("Queue is full!");
}

int main() {
  struct Queue q;
  initQueue(&q);
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);
  display(&q);

  dequeue(&q);
  display(&q);

  enqueue(&q, 60);
  display(&q);

  enqueue(&q, 70);
  return 0;
}
