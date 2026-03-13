/* Implementation of post order traveral on tree
 * using two stacks
 */

#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
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

// push nodes on stack
void push(Stack *s, TreeNode *node) {
  if (isFull(s))
    return;
  s->stack[++s->top] = node;
}

// pop nodes from stack
TreeNode *pop(Stack *s) {
  if (isEmpty(s))
    return NULL;
  return s->stack[s->top--];
}

// post order traversal
void post_order(TreeNode *root) {
  if (root) {
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
  }
}

// post order traversal
void iterative_post_order(TreeNode *root) {
  if (!root)
    return;

  // initialize two stacks
  Stack s1, s2;
  initStack(&s1);
  initStack(&s2);

  // push root node on stack 1
  push(&s1, root);
  while (!isEmpty(&s1)) {
    // pop a node from s1
    // push the popped node from s2
    TreeNode *temp = pop(&s1);
    push(&s2, temp);

    // push left and right nodes on stack 1
    if (temp->left)
      push(&s1, temp->left);

    if (temp->right)
      push(&s1, temp->right);
  }
  printf("Iterative post-order: [ ");
  while (!isEmpty(&s2)) {
    TreeNode *temp = pop(&s2);
    printf("%d ", temp->data);
  }
  printf(" ]\n");
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

  printf("Iterative post-order: [ ");
  post_order(root);
  printf(" ]\n");

  iterative_post_order(root);
  return EXIT_SUCCESS;
}
