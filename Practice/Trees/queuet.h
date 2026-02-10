/* Queue implementation for tree */
#include "tree.h"
#define MAX 100

/* Queue using linked list */
typedef struct queue {
  int REAR;             // insert nodes
  int FRONT;            // delete nodes
  TreeNode *queue[MAX]; // stores the addresses of treenodes
} Queue;

// initialize queue
void initQueue(Queue *q);

// enqueue treenode using rear
void enqueue(Queue *q, TreeNode *node);

// dequeue elements using front
TreeNode *dequeue(Queue *q);
