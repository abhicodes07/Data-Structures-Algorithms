/* IMPLEMENTATION OF DOQUEUE(DOUBLE ENDED QUEUE) USING ARRAY */
// consider array circular

#include <stdio.h>

#define MAX 5
int deque[MAX];
int front = -1, rear = -1;

/* check if queue is full */
int isFull() {
  // (rear + 1) % MAX == front condition can also be used here
  if ((rear + 1 == front) || (front == 0 && rear == MAX - 1)) {
    return 1;
  }
  return 0;
}

/* check if queue is empty */
int isEmpty() {
  if (front == -1 && rear == -1) {
    return 1;
  }
  return 0;
}

/* display elements in dqeue */
void display() {
  // if deque is empty
  if (isEmpty()) {
    printf("Nothing to display, DeQue is empty.\n");
    return;
  }

  int i = front;
  printf("Elements in queue: [ ");
  while (i != rear) {
    printf("%d ", deque[i]);
    i = (i + 1) % MAX;
  }
  printf("%d ]\n\n", deque[rear]);
}

/* Enqueue element using front part */
void enqueueFront(int x) {
  // front part of the queue is used for deletion
  // and it gets incremented whenever a element is dequeue
  // however to insert an element using front, we have to decrement
  // it.
  if (isFull()) {
    printf("DEQUE IS FULL.\n");
    return;
  } else if (rear == -1 && front == -1) {
    // if deque is empty simply insert an element at 0th position
    rear = front = 0;
    deque[front] = x;
    printf("Enqueued: %d\n", deque[front]);
  } else if (front == 0) {
    // if front is 0 then move it backwards to
    // MAX - 1
    front = MAX - 1;
    deque[front] = x;
    printf("Enqueued: %d\n", deque[front]);
  } else {
    // if front is greater than 0 then simply decrement it
    front--;
    deque[front] = x; // or deque[--front]
    printf("Enqueued: %d\n", deque[front]);
  }
}

/* Enqueue from rear part of the deque */
void enqueueRear(int x) {
  if (isFull()) {
    printf("Deque is full\n");
    return;
  } else if (rear == -1 && front == -1) {
    front = rear = 0;
    deque[rear] = x;
    printf("Enqueued: %d\n", deque[rear]);
  } else if (rear == MAX - 1) {
    rear = 0;
    deque[rear] = x;
    printf("Enqueued: %d\n", deque[rear]);
  } else {
    rear++;
    deque[rear] = x;
    printf("Enqueued: %d\n", deque[rear]);
  }
}

/* Dequeue element from the front part of the deque */
void dequeueFront(void) {
  if (isEmpty()) {
    printf("Deque is already empty, nothing to dequeue.\n");
    return;
  } else if (front == rear) {
    printf("Dequeued: %d\n", deque[front]);
    front = rear = -1;
  } else if (front == MAX - 1) {
    printf("Dequeued: %d\n", deque[front]);
    front = 0;
  } else {
    printf("Dequeued: %d\n", deque[front]);
    front++;
  }
}

/* dequeue element fron the rear part of the deque */
void dequeueRear(void) {
  if (isEmpty()) {
    printf("Deque is already empty, nothing to dequeue.\n");
    return;
  } else if (rear == front) {
    printf("Dequeued: %d\n", deque[rear]);
    rear = front = -1;
  } else if (rear == 0) {
    printf("Dequeued: %d\n", deque[rear]);
    rear = MAX - 1;
  } else {
    printf("Dequeued: %d\n", deque[rear]);
    rear--;
  }
}

/* get front value of deque */
void getFront(void) {
  if (isEmpty()) {
    printf("Queue is Empty.\n");
    return;
  }
  printf("FRONT: %d\n", deque[front]);
}

/* get front value of deque */
void getRear(void) {
  if (isEmpty()) {
    printf("Queue is Empty.\n");
    return;
  }
  printf("REAR: %d\n", deque[rear]);
}

// main method
int main(void) {
  enqueueFront(10);
  enqueueFront(20);
  enqueueFront(30);
  // enqueueRear(10);
  // enqueueRear(20);
  // enqueueRear(30);
  display();
  dequeueFront();
  display();
  dequeueFront();
  display();
  enqueueRear(70);
  enqueueRear(80);
  enqueueRear(90);
  display();

  dequeueRear();
  display();
  dequeueRear();
  display();
  // display();
  // getFront();
  return 0;
}
