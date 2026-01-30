/* In simple queue,
 * insertion takes place from one end -> REAR/TAIL
 * & deletion takes place from another -> FRONT/HEAD
 * Queue uses FIFO property
 * FIFO: First In First Out
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// define size of the queue
#define MAX 100

// initialize RARE and FRONT null or -1
int REAR = -1;  // insertion
int FRONT = -1; // deletion

// create array of queue
int queue[MAX];

// insert element in queue
void enqueue(int val) {
  if (REAR > MAX - 1) { // check if queue is full or not
    printf("Queue is full!\n");
    return;
  }
  // If queue is empty then initialize both REAR and FRONT
  else if (REAR == -1 && FRONT == -1) {
    REAR++;  // 0
    FRONT++; // 0
    queue[REAR] = val;
    printf("%d enequeued.\n", queue[REAR]);
  }
  // use only REAR to insert the element
  else {
    queue[++REAR] = val;
    printf("%d enequeued.\n", queue[REAR]);
  }
}

// delete elements from the queue
void dequeue() {
  // check if queue is not already empty
  if (FRONT < 0) {
    printf("QUEUE IS EMPTY!\n");
  }
  // if there's only one element in queue
  else if (REAR == 0 && FRONT == 0) {
    printf("%d dequeued from the queue.\n", queue[FRONT]);
    REAR--;
    FRONT--;
  }
  //
  else {
    printf("%d dequeued from the queue.\n", queue[FRONT++]);
  }
}

// check the position of REAR
void peekRear() { printf("Element at REAR: %d\n", queue[REAR]); };

// check the element at FRONT
void peekFront() { printf("Element at FRONT: %d\n", queue[FRONT]); }

// check if the queue is full
int isFull() { return REAR == MAX - 1; }

// check if the queue is empty
int isEmpty() { return FRONT < 0 || FRONT == REAR; }

// display elements in queue
void display() {
  if (REAR == -1 && FRONT == -1) {
    printf("Queue is empty!\n");
  } else {
    printf("Elements in the queue: [");
    int i = FRONT;
    while (i <= REAR) {
      printf("%d ", queue[i]);
      i++;
    }
    printf("]\n");
  }
}

int main(int argc, char *argv[]) {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  display();

  dequeue();
  display();

  dequeue();
  display();

  peekFront();
  peekRear();
  printf("%d\n", isEmpty());
  printf("%d\n", isFull());

  return EXIT_SUCCESS;
}
