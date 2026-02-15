/* Check if a tree is complete tree
 * using level order traversal
 */
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// create queue
typedef struct queue {
  TreeNode *queue[MAX]; // store treenode
  int rear;             // insertion
  int front;            // deletion
} Queue;

// initialize queue
void initQueue(Queue *q) {
  q->rear = -1;
  q->front = 0;
}

// check if queue is empty or full
bool isFull(const Queue *q) { return q->rear > MAX - 1; }
bool isEmpty(const Queue *q) { return q->front > q->rear; }

// enqueue node
void enqueue(Queue *q, TreeNode *node) {
  if (isFull(q)) {
    printf("Overflow!\n");
    return;
  }
  q->queue[++q->rear] = node;
}

// dequeue node
TreeNode *dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Underflow!\n");
    return NULL;
  }
  return q->queue[q->front++];
}

// initialize tree node
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    perror("Allocation failed!\n");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// check if the tree is complete
bool is_complete(TreeNode *root) {
  if (!root)
    return NULL;
  Queue q;
  initQueue(&q);
  enqueue(&q, root);    // enqueue root node
  bool is_null = false; // flag to track the null node
  while (!isEmpty(&q)) {
    TreeNode *temp = dequeue(&q);

    if (temp) {
      if (is_null)
        return false;
      enqueue(&q, temp->left);
      enqueue(&q, temp->right);
    } else {
      is_null = true; // mark that we've seen a gap
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  TreeNode *root = initNode(10);
  root->left = initNode(20);
  root->right = initNode(30);
  root->left->left = initNode(40);
  root->left->right = initNode(50);
  root->right->left = initNode(60);
  root->right->right = initNode(70);
  root->left->left->right = initNode(80);

  if (is_complete(root))
    printf("Tree is a complete binary tree!\n");
  else
    printf("Tree is not a complete binary tree!\n");
  return EXIT_SUCCESS;
}
