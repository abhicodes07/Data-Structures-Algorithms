// Queue implementation using array
#include <stdio.h>

#define MAX 100

int REAR = -1;
int FRONT = -1;
int queue[MAX];

// insert element
void enqueue(int val) {
  if (REAR > MAX - 1) {
    printf("OVERFLOW!\n");
    return;
  } else if (REAR == -1 && FRONT == -1) {
    REAR++;
    FRONT++;
    queue[REAR] = val;
    printf("Enqueued: %d\n", val);
  } else {
    queue[++REAR] = val;
    printf("Enqueued: %d\n", val);
  }
}

// dequeue or delete an element
void dequeue() {
  if (FRONT < 0) {
    printf("UNDERFLOW!\n");
    return;
  } else if (REAR == 0 && FRONT == 0) {
    printf("Dequeued: %d\n", queue[FRONT]);
    FRONT = -1;
    REAR = -1;
  } else {
    printf("Dequeued: %d\n", queue[FRONT++]);
  }
}

// display all the elements in the queue
void display() {
  if (REAR == -1 && FRONT == -1) {
    printf("Queue is empty!\n");
  } else {
    printf("Elements in the list: ");
    for (int i = FRONT; i <= REAR; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

// peek top most eleement
void peek() { printf("Peek element: %d\n", queue[REAR]); }

// check if queue is empty
void isFull() {
  if (REAR > MAX - 1) {
    printf("Queue is full!");
  } else {
    printf("Queue is empty!");
  }
}

// check if queue is full
void isEmpty() {
  if (FRONT < 0) {
    printf("Queue is empty!");
  } else if (FRONT == MAX - 1) {
    printf("Queue is full!");
  } else {
    printf("Queue still have some space!");
  }
}

int main() {
  enqueue(11);
  enqueue(12);
  enqueue(13);
  display();
  dequeue();
  display();
  dequeue();
  display();
  enqueue(14);
  display();
  printf("FRONT: %d\n", FRONT);
  printf("REAR: %d\n", REAR);
  peek();
  return 0;
}
