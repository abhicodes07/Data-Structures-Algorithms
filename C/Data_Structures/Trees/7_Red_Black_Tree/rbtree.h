/**
 * Copyright (c) 2026 Abhinav.
 * May be freely redistributed, but copyright notice must be retained.
 * https://github.com/abhicodes07
 */

#ifndef _RB_TREE_HEADER // header guard
#define _RB_TREE_HEADER

#define RB_DUP 1 // duplicates
#define RB_MIN 1 // minimum

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

/* macros */
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

/*
 * @brief initialize a new empty tree with custom comparison and destruction
 * functions
 *
 * @param compare_func function for ordering keys.
 *                     Signature: `int compare(const void *a, const void *b)`
 * @param destroy_func function for destroying user data
 *                     signature: `int destroy(void *a)`
 *
 * @return success: pointer to rbTree structure
 * @return failure: NULL
 */
rbTree *rbTreeCreate(int (*compare_func)(const void *, const void *),
                     void (*destroy_func)(void *));

/*
 * @brief     free the entire tree
 * @param rbt pointer to the  rbTree to be destroyed
 * @return    void
 */
void rbTreeDestroy(rbTree *rbt);

/*
 * @brief      find predecessor of a node
 *
 * @param rbt  pointer to valid non-empty rbTree structure
 * @param node pointer to current node
 *
 * @return     pointer to rbNode
 */
rbNode *rbTreePredecessor(rbTree *rbt, rbNode *node);

/*
 * @brief      find successor of a node
 *
 * @param rbt  pointer to valid non-empty rbTree structure
 * @param node pointer to the current node
 *
 * @return     pointer to the node of type rbNode
 */
rbNode *rbTreeSuccessor(rbTree *rbt, rbNode *node);

/*
 * @brief      search node in rbTree
 *
 * @param rbt  pointer to rbTree structure
 * @param data generic pointer to the data to be searched
 *
 * @return     pointer to the node of type rbNode*/
rbNode *rbTreeFind(rbTree *rbt, void *data);

/*
 * @brief        traverse subtree applying a function (PRE/IN/POST) order
 *
 * @param rbt    pointer the rbTree structure
 * @param node   root of subtree to traverse
 * @param func   user defined callback function applied to every node.
 *               Signature: `int func(void *node_data, void *cookie)`
 * @param cookie generic data passed to `func` on each call
 * @param order  Traversal order
 *
 * @return int
 */
int rbTreeApply(rbTree *rbt, rbNode *node, int (*func)(void *, void *),
                void *cookie, rbTraversal order);

/*
 * @brief            print rbTree recursively
 * @param rbt        pointer to valid rbTree structure
 * @param print_func function for printing single node's data
 *                   Signature: `print_func(void *node)`
 * @return void
 */

void rbTreePrint(rbTree *rbt, void (*print_func)(void *));

/*
 * @brief      insert values in red-black tree or updates the existing values if
 *             duplicated are enabled
 *
 * @param rbt  pointer to the rbTree structure
 * @param data key to be inserted into the tree
 *
 * @return     pointer to the inserted node
 */
rbNode *rbTreeInsert(rbTree *rbt, void *data);

/*
 * @brief      delete node from the tree
 *
 * @param rbt  pointer to the rbTree structure
 * @param node pointer to the node to be deleted
 * @param keep if 0, data is destroyed using destroy_func;
 *             if 1, data is preserved and returned
 *
 * @return     pointer to the deleted data if keep=1, NULL if keep=0
 */
void *rbTreeDelete(rbTree *rbt, rbNode *node, int keep);

/*
 * @brief      verify the BST property
 *
 * @param  rbt pointer to valid rbTree structure
 * @param  min minimum boundary value
 * @param  max maximum boundary value
 *
 * @return int 1 if tree is valid, 0 if invalid
 */
int rbTreeCheckOrder(rbTree *rbt, void *min, void *max);

/*
 * @brief      verify red-black tree black-height property
 * @param  rbt pointer to valid rbTree structure
 * @return int 1 if tree is valid, 0 if invalid
 */
int rbTreeCheckBlackHeight(rbTree *rbt);

#endif // !_RB_TREE_HEADER
