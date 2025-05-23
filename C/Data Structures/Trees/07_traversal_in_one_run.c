/*
 * ALGORITHM TO TRAVERSE A TREE IN
 * POST / IN / PRE ORDER IN SINGLE RUN
 * TIME COMPLEXITY: O(3N) -> O(N)
 * SPACE COMPLEXITY: O(3N)
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 15

// create treenode datatype
struct Treenode {
  struct Treenode *left;
  struct Treenode *right;
  int data;
};

// implement pairs
struct Pair {
  struct Treenode *node;
  int state;
};

// implementation of stack
struct Stack {
  int top;
  struct Pair *stack[MAX];
};

// initialize treenode
struct Treenode *initNode(int value) {
  struct Treenode *newnode = (struct Treenode *)malloc(sizeof(struct Treenode));
  newnode->data = value;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// initialize pair
struct Pair *initPair(struct Treenode *node, int state) {
  struct Pair *p = (struct Pair *)malloc(sizeof(struct Pair));
  p->node = node;
  p->state = state;
  return p;
}
// initialize stack
void initStack(struct Stack *s) { s->top = -1; }

// push treenode into stack
void push(struct Stack *s, struct Pair *p) {
  if (s->top == MAX - 1) {
    printf("overflow!\n");
    return;
  }
  s->stack[++s->top] = p;
}

// pop top most pair from stack
struct Pair *pop(struct Stack *s) {
  if (s->top == -1) {
    printf("underflow!\n");
    exit(1);
  }
  return s->stack[s->top--];
}

// check empty stack
int is_empty(struct Stack *s) { return s->top == -1; }

// display results
void display(int preorder[], int inorder[], int postorder[]) {
  printf("Pre-order: ");
  for (int i = 0; i < 7; i++) {
    printf("%d ", preorder[i]);
  }
  printf("\nIn-order: ");
  for (int i = 0; i < 7; i++) {
    printf("%d ", inorder[i]);
  }
  printf("\nPost-order: ");
  for (int i = 0; i < 7; i++) {
    printf("%d ", postorder[i]);
  }
  printf("\n");
}

// traverse the tree in post/pre/in order in single run
void traverse_all(struct Treenode *rootnode) {
  struct Stack st;
  initStack(&st);

  int pre[7];
  int post[7];
  int in[7];
  int i = 0, j = 0, k = 0;

  if (!rootnode)
    return;

  // initially push roonode into stack
  push(&st, initPair(rootnode, 1));

  while (!is_empty(&st)) {
    // pop top most node
    struct Pair *node_state = pop(&st);

    // if state is 1 then process for pre-order
    if (node_state->state == 1) {
      pre[i++] = node_state->node->data;
      node_state->state++;
      push(&st, node_state);

      // push left subtree
      if (node_state->node->left) {
        push(&st, initPair(node_state->node->left, 1));
      }
    }
    // if state is 2 then process for in-order
    else if (node_state->state == 2) {
      in[j++] = node_state->node->data;
      node_state->state++;
      push(&st, node_state);

      // push right subtree
      if (node_state->node->right) {
        push(&st, initPair(node_state->node->right, 1));
      }
    }
    // if state is 3 then process for post-order
    else {
      post[k++] = node_state->node->data;
    }
  }
  display(pre, in, post);
}

// main
int main(void) {
  struct Treenode *root;
  root = initNode(1);
  root->left = initNode(2);
  root->right = initNode(3);
  root->left->left = initNode(4);
  root->left->right = initNode(5);
  root->right->left = initNode(6);
  root->right->right = initNode(7);

  traverse_all(root);
  return 0;
}
