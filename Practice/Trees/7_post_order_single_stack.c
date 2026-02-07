/* implementation of iterative post order
 * traversal order using two stacks
 */
#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
Treenode *initNode(int data) {
  Treenode *newnode = malloc(sizeof(*newnode));
  if (!newnode)
    return NULL;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// initialize stack
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top < 0; }
int isFull(Stack *s) { return s->top == MAX - 1; }
Treenode *peek(Stack *s) {
  if (isEmpty(s))
    return NULL;
  return s->stack[s->top];
}

// push nodes on the stack
void push(Stack *s, Treenode *node) {
  if (isFull(s))
    return;
  s->stack[++s->top] = node;
}

// pop nodes from the stack
Treenode *pop(Stack *s) {
  if (isEmpty(s))
    return NULL;
  return s->stack[s->top--];
}

// iterative post order traversal
void iterative_post_order_traversal(Treenode *root) {
  if (!root)
    return;
  Stack s;
  initStack(&s);

  printf("Iterative post-order: [ ");
  Treenode *curr = root;
  Treenode *lastvisited = NULL;
  while (curr || !isEmpty(&s)) {
    if (curr) {
      push(&s, curr);
      curr = curr->left;
    } else {
      Treenode *topnode = peek(&s);

      if (topnode->right && lastvisited != topnode->right) {
        curr = topnode->right;
      } else {
        printf("%d ", topnode->data);
        lastvisited = pop(&s);
      }
    }
  }
  printf("]\n");
}

// post order traversal
void post_order(Treenode *root) {
  if (root) {
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
  }
}

// main
int main(int argc, char *argv[]) {
  Treenode *root = initNode(10);
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

  printf("Recursive post-order: [ ");
  post_order(root);
  printf(" ]\n");
  iterative_post_order_traversal(root);
  return EXIT_SUCCESS;
}
