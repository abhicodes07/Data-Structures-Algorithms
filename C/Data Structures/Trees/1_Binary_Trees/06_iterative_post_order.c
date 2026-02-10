// implementation of post order traversal
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// create tree node
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// create stack
struct Stack {
  int top;
  struct Node *stack[MAX];
};

// node initilizer
struct Node *initNode(int value) {
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = value;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// stack initializer
void initStack(struct Stack *s) { s->top = -1; }

// push node
void push(struct Stack *s, struct Node *node) {
  if (s->top > MAX - 1) {
    printf("OVERFLOW\n");
    exit(1);
  }
  s->stack[++s->top] = node;
}

// pop node
struct Node *pop(struct Stack *s) {
  if (s->top < 0) {
    printf("UNDERFLOW\n");
    exit(1);
  }
  return s->stack[s->top--];
}

// is empty?
int is_empty(struct Stack *s) { return s->top == -1; }

// iterative post order traversal using two stack
void iterative_post_order_two_stack(struct Node *rootnode) {
  if (!rootnode)
    return;
  struct Stack s1, s2;
  initStack(&s1);
  initStack(&s2);

  // push the root node into stack-1
  push(&s1, rootnode);

  while (!is_empty(&s1)) {
    // pop a node
    struct Node *temp = pop(&s1);

    // push the popped node into stack-2
    push(&s2, temp);

    // push the left subtree of popped node
    if (temp->left)
      push(&s1, temp->left);

    // push the right subtee of popped node
    if (temp->right)
      push(&s1, temp->right);
  }

  // print post order
  printf("Post order: ");
  while (!is_empty(&s2)) {
    struct Node *temp = pop(&s2);
    printf("%d ", temp->data);
  }
  printf("\n");
}

// main
int main(void) {
  struct Node *root;
  root = initNode(10);
  root->left = initNode(20);
  root->right = initNode(30);
  root->left->left = initNode(40);
  root->left->right = initNode(50);
  root->right->left = initNode(60);
  root->right->right = initNode(70);
  iterative_post_order_two_stack(root);
  return 0;
}
