/* Queue implementation for tree */
#include "tree.h"
#define MAX 100

/* Queue using linked list */
typedef struct queue {
  int REAR;             // insert nodes
  int FRONT;            // delete nodes
  Treenode *queue[MAX]; // stores the addresses of treenodes
} Queue;

// initialize queue
void initQueue(Queue *q);

// enqueue treenode using rear
void enqueue(Queue *q, Treenode *node);

// dequeue elements using front
Treenode *dequeue(Queue *q);
