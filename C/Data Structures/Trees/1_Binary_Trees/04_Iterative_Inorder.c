// Implementation of iterative in-order traversal using stack
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// create stack
struct Stack {
  int TOP;
  struct TreeNode *stack[MAX];
};

// create tree node
struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

// initialize stack
void initStack(struct Stack *s) { s->TOP = -1; }

// initialize tree nodes
struct TreeNode *initNode(int data) {
  struct TreeNode *newnode;
  newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  newnode->data = data;
  newnode->left = 0;
  newnode->right = 0;
  return newnode;
}

// push tree node in a stack
void push(struct Stack *s, struct TreeNode *node) {
  if (s->TOP > MAX - 1) {
    printf("Overflow!");
    return;
  }
  s->stack[++s->TOP] = node;
}

// pop node from the stack
struct TreeNode *pop(struct Stack *s) {
  if (s->TOP < 0) {
    printf("UNDERFLOW!");
    exit(1);
  }
  return s->stack[s->TOP--];
}

// if stack is empty
int is_empty(struct Stack *s) { return s->TOP == -1; }

// iterative inorder traversal using stack
void iterative_inorder(struct TreeNode *root) {
  struct TreeNode *node = root;
  struct Stack s;
  initStack(&s);

  printf("In-order: [ ");

  while (1) {
    // process left most nodes
    if (node) {
      push(&s, node);    // push node
      node = node->left; // move to left most nodes
    } else {
      // process right most nodes
      if (is_empty(&s))
        break;
      node = pop(&s);
      printf("%d ", node->data);
      node = node->right;
    }
  }
  printf("]\n");
}

// main
int main(void) {
  struct TreeNode *root;
  root = initNode(10);

  root->left = initNode(20);
  root->right = initNode(30);

  root->left->left = initNode(40);
  root->left->right = initNode(50);

  root->right->left = initNode(60);
  root->right->right = initNode(70);

  iterative_inorder(root);

  return 0;
}
