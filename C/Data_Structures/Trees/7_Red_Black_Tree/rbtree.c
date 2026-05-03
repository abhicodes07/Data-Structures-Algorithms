#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * private functions
 */
static void insertFixUp(rbTree *rbt, rbNode *current);
static void deleteFixUp(rbTree *rbt, rbNode *current);
static void leftRotate(rbTree *, rbNode *);
static void rightRotate(rbTree *, rbNode *);
static int checkOrder(rbTree *rbt, rbNode *m, void *min, void *max);
static int checkBlackHeight(rbTree *rbt, rbNode *node);
static void print(rbTree *rbt, rbNode *node, void (*print_func)(void *),
                  int depth, char *label);

/*
 * tree constructor
 */
rbTree *rbTreeCreate(int (*compare)(const void *, const void *),
                     void (*destroy)(void *)) {
  rbTree *rbt;

  rbt = malloc(sizeof(*rbt));

  // out of memory
  if (rbt == NULL)
    return NULL;

  rbt->compare = compare;
  rbt->destroy = destroy;

  // sentinal nil node pointing to itself
  rbt->nil.left = rbt->nil.right = rbt->nil.parent = RB_NIL(rbt);
  rbt->nil.color = BLACK;
  rbt->root.data = NULL;

#ifdef RB_MIN
  rbt->min = NULL;
#endif /* ifdef RB_MIN */

  return rbt;
}
