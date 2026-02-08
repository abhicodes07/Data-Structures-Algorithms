#include "stackpair.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
Treenode *initNode(int data) {
  Treenode *newnode = malloc(sizeof(*newnode));
  if (!newnode)
    return NULL;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->data = data;

  return newnode;
}

// initialize pair
Pair *initPair(Treenode *node, int state) {
  Pair *pair = malloc(sizeof(*pair));
  if (!pair)
    return NULL;
  pair->node = node;
  pair->state = state;
  return pair;
}

// initialize stack
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top < 0; }
int isFull(Stack *s) { return s->top == MAX; }
Pair *peek(Stack *s) { return s->stack[s->top]; }

// push pair with state
void push(Stack *s, Pair *p) {
  if (isFull(s))
    return;
  s->stack[++s->top] = p;
}

// pop pair from the stack
Pair *pop(Stack *s) {
  if (isEmpty(s))
    return NULL;
  return s->stack[s->top--];
}

// traversals in one run: pre, in, post
void traversals(Treenode *root) {
  if (!root)
    return;

  int pre[MAX];  // store pre order traversal
  int in[MAX];   // store in order traversal
  int post[MAX]; // store post order traversal
  int i, j, k;
  i = j = k = 0;

  Stack s;
  initStack(&s);
  Pair *pair = initPair(root, 1);
  push(&s, pair);
  while (!isEmpty(&s)) {
    // pop top pair
    Pair *pair = pop(&s);

    /* if state is 1, traverse in pre-order */
    if (pair->state == 1) {
      pre[i++] = pair->node->data;
      pair->state++;
      push(&s, pair);

      // if node has left child
      // push onto the stack with state 1
      if (pair->node->left)
        push(&s, initPair(pair->node->left, 1));
    }
    /* if state is 2, traverse in in-order */
    else if (pair->state == 2) {
      in[j++] = pair->node->data;
      pair->state++;
      push(&s, pair);

      if (pair->node->right)
        push(&s, initPair(pair->node->right, 1));
    }
    /* if state is 3, traverse in post-order */
    else {
      post[k++] = pair->node->data;
    }
  }

  // display lists
  printf("In-order: [ ");
  for (int l = 0; l < i; l++) {
    printf("%d ", in[l]);
  }
  printf("]\n");

  printf("Pre-order: [ ");
  for (int m = 0; m < j; m++) {
    printf("%d ", pre[m]);
  }
  printf("]\n");

  printf("Post-order: [ ");
  for (int n = 0; n < k; n++) {
    printf("%d ", post[n]);
  }
  printf("]\n");
}

void in_order(Treenode *root) {
  if (root) {
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }
}

void pre_order(Treenode *root) {
  if (root) {
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
  }
}

void post_order(Treenode *root) {
  if (root) {
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
  }
}

int main(int argc, char *argv[]) {

  Treenode *root = initNode(10);
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

  traversals(root);

  printf("Iterative in-order: [ ");
  in_order(root);
  printf("]\n");

  printf("Iterative pre-order: [ ");
  pre_order(root);
  printf("]\n");

  printf("Iterative post-order: [ ");
  post_order(root);
  printf("]\n");
  return EXIT_SUCCESS;
}
