/* IMPLEMENTATION OF LEVEL ORDER TRAVERSAL OF TREE USING QUEUE */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// create tree node
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// initialize queue
int rear = -1;
int front = -1;
struct Node *queue[MAX];

// initialize tree nodes
struct Node *init(int item) {
  struct Node *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  if (!newnode) {
    printf("MEMORY NOT ALLOCATED");
    return 0;
  }
  newnode->data = item;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// enqueue tree node in queue
void enqueue(struct Node *node) {
  if (rear > MAX - 1) {
    printf("Overflow!");
    return;
  } else if (rear == -1 && front == -1) {
    rear++;
    front++;
    queue[rear] = node;
  } else {
    queue[++rear] = node;
  }
}

// dequeue the tree node from queue
struct Node *dequeue() {
  struct Node *temp = queue[front];
  if (front < 0) {
    printf("UNDERFLOW!");
    exit(1);
  } else if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front++;
  }
  return temp;
}

// traverse through nodes level by level
void level_order_traversal(struct Node *root) {
  if (!root) {
    exit(1);
  }

  // equeue root node in queue
  enqueue(root);

  int i = front;
  printf("Level order traversal: [ ");
  while (i <= rear) {
    struct Node *node = dequeue();
    printf("%d ", node->data);

    // process left children first and then right: left to right
    if (node->left) {
      enqueue(node->left);
    }
    if (node->right) {
      enqueue(node->right);
    }
  }
  printf("]\n");
}

// main
int main(void) {
  // -->        10
  //          /    \
  //         /      \
  // -->    20      30
  //       /  \    /  \
  // -->  40  50  60  70
  // level order: 10 20 30 40 50 60 70

  // root node
  struct Node *root;
  root = init(10);

  root->left = init(20);
  root->right = init(30);

  root->left->left = init(40);
  root->left->right = init(50);

  root->right->left = init(60);
  root->right->right = init(70);

  level_order_traversal(root);
  return 0;
}
