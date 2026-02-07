/* Stack implementation for Binary Tree */
#include "tree.h"

#define MAX 100

typedef struct stack {
  int top;
  Treenode *stack[MAX];
} Stack;

// initialize stack
void initStack(Stack *s);

// push elements
void push(Stack *s, Treenode *node);

// pop elements
Treenode *pop(Stack *s);

// empty stack
int isEmpty(Stack *s);
int isFull(Stack *s);
