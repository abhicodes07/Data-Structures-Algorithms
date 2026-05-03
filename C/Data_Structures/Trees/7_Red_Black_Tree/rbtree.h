/**
 * Copyright (c) 2026 abhi9av. All Rights Reserved.
 * May be freely redistributed, but copyright notice must be retained.
 * https://github.com/abhicodes07
 */

#ifndef _RB_TREE_HEADER // header guard
#define _RB_TREE_HEADER

#define RB_DUP 1 // duplicates
#define RB_MIN 1 // minimum

#include <stdbool.h>
#include <stddef.h>

// color definitions
typedef enum { RED = 0, BLACK = 1 } rbColor;

// traversal
typedef enum { PREORDER, INORDER, POSTORDER } rbTraversal;

/* create node struct */
typedef struct rbNode {
  struct rbNode *left;
  struct rbNode *right;
  struct rbNode *parent;
  rbColor color;
  void *data; // generic: tree can store any dtype
} rbNode;

/* wrapper for Red-Black tree */
typedef struct rbTree {
  int (*compare)(const void *, const void *);
  void (*print)(void *);
  void (*destroy)(void *);

  rbNode root;
  rbNode nil;

#ifdef RB_MIN
  rbNode *min;
#endif
} rbTree;

// macros
#define RB_ROOT(rbt) (&(rbt)->root)
#define RB_NIL(rbt) (&(rbt)->nil)
#define RB_FIRST(rbt) ((rbt)->root.left)
#define RB_MINIMAL(rbt) ((rbt)->min)

#define RB_ISEMPTY(rbt)                                                        \
  ((rbt)->root.left == &(rbt)->nil && (rbt)->root.right == &(rbt)->nil)

#define RB_APPLY(rbt, f, c, o)                                                 \
  rbapply_node((rbt), (rbt)->root.left, (f), (c), (o))

/* initialize treenode */
rbNode *rbTreeInitNode(rbNode *parent, int data);

/* initialize and destroy tree */
rbTree *rbTreeCreate(int (*compare_func)(const void *, const void *),
                     void (*destroy_func)(void *));
void rbTreeDestroy(rbTree *rbt);

/* predecessor and successor */
rbNode *rbTreePredecessor(const rbTree *tree, rbNode *node);
rbNode *rbTreeSuccessor(const rbTree *tree, rbNode *node);

/* apply node*/
int rb_apply_node(rbTree *rbt, rbNode *node, int (*func)(void *, void *),
                  void *cookie, rbTraversal order);
void rbTreePrint(rbTree *rbt, void (*print_func)(void *));

/* insert and delete node */
bool rbTreeInsert(rbTree *tree, void *data);
bool rbTreeDeleteNode(rbTree *tree, rbNode *node, int keep);

rbNode *rbTreeMinimum(const rbTree *tree);

int rbTreeCheckOrder(rbTree *rbt, void *min, void *max);
int rbTreeCheckBlackHeight(rbTree *rbt);

#endif // !_RB_TREE_HEADER
