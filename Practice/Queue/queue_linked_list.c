/* Queue implementation on linked list */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* create linked list node */
typedef struct Node {
  int data;          // data part
  struct Node *next; // points to next node
} Node;

/* create queue */
typedef struct queue {
  Node *front; // deletion of node
  Node *rear;  // insertion of node
} Queue;

/* initialize node */
Node *initNode(int data) {
  Node *newnode = (Node *)malloc(sizeof(Node));
  if (newnode == NULL) {
    printf("Memory Allocation failed!\n");
    free(newnode);
    exit(0);
  }
  newnode->data = data;
  newnode->next = 0;
  return newnode;
}

/* initialize queue */
void initQueue(Queue *q) {
  q->front = NULL;
  q->rear = NULL;
}

/* insert node in queue */
void enqueue(Queue *q, int data) {
  // NOTE: Since linked lists are dynamic type of
  //  data structure, we don't have to specify size

  Node *newnode = initNode(data);

  // queue is empty
  if (q->front == NULL && q->rear == NULL) {
    q->front = newnode;
    q->rear = newnode;
    printf("%d enqueued.\n", q->rear->data);
  } else {
    // previous node points to new node
    q->rear->next = newnode;
    // mode rear to newnode
    q->rear = newnode;
    printf("%d enqueued.\n", q->rear->data);
  }
}

/* delete node from queue */
void dequeue(Queue *q) {
  // if queue is empty
  if (q->rear == NULL && q->front == NULL) {
    printf("Queue is empty!\n");
    return;
  }

  // mode the front and free the node
  Node *temp = q->front;
  q->front = q->front->next;
  printf("%d dequeued.\n", temp->data);
  free(temp);
}

/* display elements in queue */
int isEmpty(Queue *q) { return q->front == NULL && q->rear == NULL; }

/* display elements in queue */
void peekFront(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
  }
  printf("Element at Front: %d", q->front->data);
}

/* display elements in queue */
void peekRear(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
  }
  printf("Element at Rear: %d", q->rear->data);
}

/* display elements in queue */
void display(Queue *q) {
  // queue is empty
  if (q->rear == NULL && q->front == NULL) {
    printf("Queue is empty!\n");
    return;
  }
  Node *temp = q->front;
  printf("Elements in the list: [ ");
  while (temp) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL ]\n");
}

int main(int argc, char *argv[]) {
  Queue q;
  initQueue(&q);
  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);
  display(&q);
  dequeue(&q);
  display(&q);
  dequeue(&q);
  display(&q);
  printf("%d", isEmpty(&q));
  return EXIT_SUCCESS;
}
