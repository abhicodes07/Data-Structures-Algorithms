/* Implemetation of iterative pre order
 * traversal using stack
 */

#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    printf("Memory allocation failed!\n");
    return NULL;
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// initialize stack
void initStack(Stack *s) { s->top = -1; }
int isEmpty(const Stack *s) { return s->top < 0; }
int isFull(const Stack *s) { return s->top == MAX - 1; }

// push node in stack
void push(Stack *s, TreeNode *node) {
  if (isFull(s)) {
    printf("Stack Overflow!\n");
    return;
  }
  s->stack[++s->top] = node;
}

// pop node from stack
TreeNode *pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack Underflow!\n");
    return NULL;
  }
  return s->stack[s->top--];
}

// iterative pre order traversal
void iterative_pre_order(TreeNode *root) {
  if (!root)
    return;
  Stack s;
  initStack(&s);
  push(&s, root);

  printf("Iterative pre-order: [ ");
  while (!isEmpty(&s)) {
    TreeNode *temp = pop(&s);
    printf("%d ", temp->data);

    if (temp->right)
      push(&s, temp->right);
    if (temp->left)
      push(&s, temp->left);
  }
  printf(" ]\n");
}

void preorder(const TreeNode *root) {
  if (root) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

// main
int main(int argc, char *argv[]) {
  TreeNode *root;
  root = initNode(10);
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

  iterative_pre_order(root);
  printf("Pre-order: [ ");
  preorder(root);
  printf(" ]\n");
  return EXIT_SUCCESS;
}
