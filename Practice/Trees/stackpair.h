#include "tree.h"
#define MAX 100

// pair to store state and treenode
typedef struct pair {
  int state;      // store state
  Treenode *node; // store treenode
} Pair;

// stack for pairs
typedef struct stack {
  int top;
  Pair *stack[MAX]; // store pair
} Stack;

// initialize pair
Pair *initPair(Treenode *node, int state);

// Stack operations
void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
Pair *peek(Stack *s);
void push(Stack *s, Pair *p);
Pair *pop(Stack *s);
