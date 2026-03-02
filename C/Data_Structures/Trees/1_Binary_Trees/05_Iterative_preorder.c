// IMPLEMENTATION OF ITERATIVE PRE-ORDER TRAVERSAL
// PRE-ORDER CRITERIA: ROOT LEFT RIGHT

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// create tree node
struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

// create stack
struct Stack {
  struct TreeNode *stack[MAX];
  int top;
};

// create tree nodes
struct TreeNode *initNode(int item) {
  struct TreeNode *newnode;
  newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  newnode->data = item;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// initialize stack
void initStack(struct Stack *s) { s->top = -1; }

// push tree node into stack
void push(struct Stack *s, struct TreeNode *node) {
  if (s->top > MAX - 1) {
    printf("OVERFLOW!\n");
    exit(1);
  }
  s->stack[++s->top] = node;
}

// pop tree node from the stack
struct TreeNode *pop(struct Stack *s) {
  if (s->top < 0) {
    printf("UNDERFLOW!\n");
    exit(1);
  }
  return s->stack[s->top--];
}

// if stack is empty
int is_empty(struct Stack *s) { return s->top == -1; }

// iterative pre order
void iterative_preorder(struct TreeNode *rootnode) {
  struct Stack s;
  struct TreeNode *node;
  initStack(&s);

  if (!rootnode)
    return;
  push(&s, rootnode);

  printf("Iterative Preorder: [ ");
  while (!is_empty(&s)) {
    node = pop(&s);
    printf("%d ", node->data);
    if (node->right)
      push(&s, node->right);
    if (node->left)
      push(&s, node->left);
  }
  printf("]\n");
}

// main
int main() {
  struct TreeNode *root;
  root = initNode(10);
  root->left = initNode(20);
  root->right = initNode(30);
  root->left->left = initNode(40);
  root->left->right = initNode(50);
  root->right->left = initNode(60);
  root->right->right = initNode(70);
  iterative_preorder(root);
  return 0;
}
