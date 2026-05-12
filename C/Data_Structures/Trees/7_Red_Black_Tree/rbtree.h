/**
 * Copyright (c) 2026 Abhinav.
 * May be freely redistributed, but copyright notice must be retained.
 * https://github.com/abhicodes07
 */

#ifndef _RB_TREE_HEADER // header guard
#define _RB_TREE_HEADER

#define RB_DUP 1 // duplicates
#define RB_MIN 1 // minimum

#include <stdbool.h>
#include <stddef.h>

// color constants
typedef enum { RED = 0, BLACK = 1 } rbColor;

// traversal
typedef enum { PREORDER, INORDER, POSTORDER } rbTraversal;

/* create node struct */
typedef struct rbNode {
  struct rbNode *left;   // left pointer
  struct rbNode *right;  // right pointer
  struct rbNode *parent; // parent pointer
  rbColor color;         // color of the node
  void *data;            // generic: tree can store any dtype
} rbNode;

/* wrapper for Red-Black tree */
typedef struct rbTree {
  int (*compare)(const void *, const void *); // comparator like strcmp
  void (*print)(void *);                      // print (optional)
  void (*destroy)(void *);                    // destructor

  rbNode root; // sentinal root (actual data starts at root.left)
  rbNode nil;  // sentinal NIL (leaf nodes, always black)

#ifdef RB_MIN
  // pointer to minimum node if enabled
  rbNode *min;
#endif
} rbTree;

// macros
#define RB_ROOT(rbt) (&(rbt)->root)      // root node
#define RB_NIL(rbt) (&(rbt)->nil)        // nil node
#define RB_FIRST(rbt) ((rbt)->root.left) // first real node with data
#define RB_MINIMAL(rbt) ((rbt)->min)     // minimum node

// check if tree/subtree is empty
#define RB_ISEMPTY(rbt)                                                        \
  ((rbt)->root.left == &(rbt)->nil && (rbt)->root.right == &(rbt)->nil)

// apply a function to all nodes
#define RB_APPLY(rbt, f, c, o)                                                 \
  rbTreeApply((rbt), (rbt)->root.left, (f), (c), (o))

/* initialize treenode */
rbNode *rbTreeInitNode(rbNode *parent, int data);

/* initialize and destroy tree */
rbTree *rbTreeCreate(int (*compare_func)(const void *, const void *),
                     void (*destroy_func)(void *));

/* free the entire tree */
void rbTreeDestroy(rbTree *rbt);

/* find predecessor and successor of a node */
rbNode *rbTreePredecessor(rbTree *tree, rbNode *node);
rbNode *rbTreeSuccessor(rbTree *tree, rbNode *node);

/* find node */
rbNode *rbTreeFind(rbTree *rbt, void *data);

/* traverse subtree applying a function (PRE/IN/POST) order */
int rbTreeApply(rbTree *rbt, rbNode *node, int (*func)(void *, void *),
                void *cookie, rbTraversal order);

/* print the tree */
void rbTreePrint(rbTree *rbt, void (*print_func)(void *));

/* insert and delete node */
rbNode *rbTreeInsert(rbTree *rbt, void *data);
void *rbTreeDelete(rbTree *rbt, rbNode *node, int keep);

/* Debug */
// verify BST property
int rbTreeCheckOrder(rbTree *rbt, void *min, void *max);

// verify Red-Black height propety
int rbTreeCheckBlackHeight(rbTree *rbt);

#endif // !_RB_TREE_HEADER
