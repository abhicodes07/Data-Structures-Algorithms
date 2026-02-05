// level order traversal using queue DS
// enqueue the root node, print it
// enqueue it's children
// left first, right second

#include "queuet.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
Treenode *initNode(int data) {
  Treenode *newnode = malloc(sizeof(*newnode));
  if (newnode == NULL) {
    printf("Memory allocation failed!\n");
    return 0;
  }
  newnode->data = data;
  newnode->right = NULL;
  newnode->left = NULL;
  return newnode;
}

/* initialize queue */
void initQueue(Queue *q) {
  // if front is greater than rear than
  // queue is empty as front has crossed the rear
  // we don't have to initialize both front and
  // rear to -1
  q->REAR = -1;
  q->FRONT = 0;
}

int isEmpty(const Queue *q) { return q->FRONT > q->REAR; }

/* insert treenode */
void enqueue(Queue *q, Treenode *node) {
  // if queue is full
  if (q->REAR == MAX - 1) {
    printf("Queue Overflow!\n");
    return;
  }
  q->queue[++q->REAR] = node;
}

/* dequeue treenode */
Treenode *dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue Underflow!\n");
    return NULL;
  }

  Treenode *node = q->queue[q->FRONT++];
  return node;
}

/* traversal */
void level_order_traversal(Treenode *root) {
  if (!root)
    return;

  Queue q;
  initQueue(&q);
  enqueue(&q, root); // enqueue root node
  printf("Level Order Traversal: [ ");
  while (!isEmpty(&q)) {
    Treenode *temp = dequeue(&q);
    printf(" %d,", temp->data);

    if (temp->left) {
      enqueue(&q, temp->left);
    }
    if (temp->right) {
      enqueue(&q, temp->right);
    }
  }
  printf(" ]\n");
}

// main
int main(int argc, char *argv[]) {
  // create tree
  Treenode *root;
  root = initNode(10);
  root->left = initNode(20);
  root->right = initNode(30);
  root->left->left = initNode(40);
  root->left->right = initNode(50);
  root->right->left = initNode(60);
  root->right->right = initNode(70);

  // if tree is created successfully
  if (root) {
    printf("Tree created!\n");
  }

  // traverse level by level
  level_order_traversal(root);
  return EXIT_SUCCESS;
}
