/* Implementation of in-order
 * traversal using stack
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

// push nodes in the stack
void push(Stack *s, TreeNode *node) {
  if (isFull(s))
    return;
  s->stack[++s->top] = node;
}

// pop nodes from the stack
TreeNode *pop(Stack *s) {
  if (isEmpty(s))
    return NULL;
  return s->stack[s->top--];
}

// iterative in order traversal
void in_order_traversal(TreeNode *root) {
  if (!root)
    return;
  Stack s;
  initStack(&s);
  printf("Iterative in-order traversal: [ ");

  // store in root in temp
  TreeNode *temp = root;

  while (true) {
    // process left nodes
    if (temp) {
      push(&s, temp);
      temp = temp->left;
    } else {
      // process right nodes
      if (isEmpty(&s))
        break;
      temp = pop(&s);
      printf("%d ", temp->data);
      temp = temp->right;
    }
  }
  printf(" ]\n");
}

// in order recursive
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }
}

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

  in_order_traversal(root);

  printf("Iterative in-order: [ ");
  in_order(root);
  printf(" ]\n");
  return EXIT_SUCCESS;
}
