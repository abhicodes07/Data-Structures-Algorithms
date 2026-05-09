#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>

/* private functions ──────────────────────────────────────────────────────── */
static void insertFixUp(rbTree *rbt, rbNode *current);
static void deleteFixUp(rbTree *rbt, rbNode *current);
static void leftRotate(rbTree *, rbNode *);
static void rightRotate(rbTree *, rbNode *);
static int checkOrder(rbTree *rbt, rbNode *n, void *min, void *max);
static int checkBlackHeight(rbTree *rbt, rbNode *n);
static void print(rbTree *rbt, rbNode *n, void (*print_func)(void *), int depth,
                  char *label);
static void destroy(rbTree *rbt, rbNode *n);

/* tree constructor ──────────────────────────────────────────────────────── */
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

/* tree destructor ───────────────────────────────────────────────────────── */
void rbDestroy(rbTree *rbt) {
  destroy(rbt, RB_FIRST(rbt));
  free(rbt);
}

/*
 * find node in tree
 */
rbNode *rbTreeFind(rbTree *rbt, void *data) {
  rbNode *p;
  p = RB_FIRST(rbt);

  while (p != RB_NIL(rbt)) {
    int cmp;
    cmp = rbt->compare(data, p->data);
    if (cmp == 0)
      return p; // found
    p = cmp < 0 ? p->left : p->right;
  }
  return NULL; // not found
}

/* successor of a given node ────────────────────────────────────────────── */
rbNode *rbTreeSuccessor(rbTree *rbt, rbNode *node) {
  rbNode *p;

  p = node->right;

  if (p != RB_NIL(rbt)) {
    /* move down the leftmost leaf
     * until we find it */
    for (; p->left != RB_NIL(rbt); p = p->left)
      ;
  } else {
    /* move up until we find it or hit the root */
    for (p = node->parent; node == p->right; node = p, p = p->parent)
      ;
    if (p == RB_ROOT(rbt))
      p = NULL; /* not found */
  }

  return p;
}

/* apply func ───────────────────────────────────────────────────────────── */
/* return non-zero if error */
int rbTreeApply(rbTree *rbt, rbNode *node, int (*func)(void *, void *),
                void *cookie, rbTraversal order) {
  int err;

  if (node != RB_NIL(rbt)) {
    if (order == PREORDER &&
        (err = func(node->data, cookie)) != 0) /* pre order*/
      return err;
    if ((err = rbTreeApply(rbt, node->left, func, cookie, order)) !=
        0) /* left */
      return err;
    if (order == INORDER && (err = func(node->data, cookie)) != 0) /* inorder */
      return err;
    if ((err = rbTreeApply(rbt, node->right, func, cookie, order)) !=
        0) /* right */
      return err;
    if (order == POSTORDER &&
        (err = func(node->data, cookie)) != 0) /* postorder */
      return err;
  }

  return 0;
}

/* left rotation about x ──────────────────────────────────────────────────── */
void leftRotate(rbTree *rbt, rbNode *x) {
  rbNode *y;

  /* child */
  y = x->right;

  /* tree x */
  x->right = y->left;

  /* if y had no left subtree then
   * x->right had stored NIL above
   * so check if it is not NIL
   * if it is not, then update the parent of
   * x->right
   */
  if (x->right != RB_NIL(rbt))
    x->right->parent = x;

  /* tree y */
  y->parent = x->parent;
  if (x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;

  /* link x and y tree */
  y->left = x;
  x->parent = y;
}

/* right rotation about x ────────────────────────────────────────────────── */
void rightRotate(rbTree *rbt, rbNode *x) {
  rbNode *y;

  y = x->left;

  /* x tree */
  x->left = y->right;
  if (x->left != RB_NIL(rbt))
    x->left->parent = x;

  /* y tree */
  y->parent = x->parent;
  if (x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;

  /* link x and y trees */
  y->right = x;
  x->parent = y;
}

/* insert (or update) data
 * maintaining Red-Black properties
 * return NULL if out of memory
 * ───────────────────────────────────────────────────────────────────────── */
rbNode *rbTreeInsert(rbTree *rbt, void *data) {
  rbNode *current, *parent;
  rbNode *new_node;

  /* binary search to find the node */
  parent = RB_ROOT(rbt);
  current = RB_FIRST(rbt);

  /* traverse tree */
  while (current != RB_NIL(rbt)) {
    int cmp;
    cmp = rbt->compare(data, current->data);

    /* if duplicate values are allowed then
     * update the new data with duplicate one
     */
#ifndef RB_DUP
    if (cmp == 0) {
      rbt->destroy(current->data);
      current->data = data;
      return current; // updated
    }
#endif /* ifndef RB_DUP */

    /* move parent */
    parent = current;

    /* if data < current->data go to left else right */
    current = cmp < 0 ? current->left : current->right;
  }

  /* replace the termination NIL pointer with new node pointer */
  current = new_node = (rbNode *)malloc(sizeof(rbNode));

  /* memory allocaion failed */
  if (current == NULL)
    return NULL;

  /* add new node with RED color */
  current->left = current->right = RB_NIL(rbt);
  current->parent = parent;
  current->color = RED;
  current->data = data;

  /* update parent's pointers */
  /* if parent is ROOT (sentinal) node or data is less than
   * parents data then make the new node in the left of parent
   * else in the right
   */
  if (parent == RB_ROOT(rbt) || rbt->compare(data, parent->data) < 0)
    parent->left = current;
  else
    parent->right = current;

/* updated minimum if pointer to the minimum node is enabled */
#ifdef RB_MIN
  if (rbt->min == NULL || rbt->compare(current->data, rbt->min->data))
    rbt->min = current;
#endif /* ifdef RB_MIN */

  /* apply insertFixUp auxiliary procedure if the
   * RED-BLACK property is violated
   */
  if (current->parent->color == RED) {
    insertFixUp(rbt, current);
  } else {
  }

  /* root is always black */
  RB_FIRST(rbt)->color = BLACK;

  return new_node;
}

/* auxiliary function ────────────────────────────────────────────────────── */
void insertFixUp(rbTree *rbt, rbNode *current) {
  /* right-child of grand-parent */
  rbNode *uncle;

  /* parent's parent */
  rbNode *grandparent;
  grandparent = current->parent->parent;

  /* both current and parent node are RED
   * violation of RED-BLACK property
   */
  do {
    /* if parent of current is left-child of grandparent */
    if (current->parent == grandparent->left) {
      uncle = grandparent->right;
      if (uncle->color == RED) {
        current->parent->color = BLACK;
        uncle->color = BLACK;

        current = grandparent;
        current->color = RED;
      } else {
        if (current == current->parent->right) {
          current = current->parent;
          leftRotate(rbt, current);
        }

        current->parent->color = BLACK;
        grandparent->color = RED;
        rightRotate(rbt, grandparent);
      }
    } else {
      uncle = grandparent->left;

      if (uncle->color == RED) {
        uncle->color = BLACK;
        current->parent->color = BLACK;
        current = grandparent;
      } else {
        if (current == current->parent->left) {
          current = current->parent;
          rightRotate(rbt, current);
        }

        current->parent->color = BLACK;
        grandparent->color = RED;
        leftRotate(rbt, grandparent);
      }
    }
  } while (current->parent->color == RED);
}

/* check BST property of the tree ────────────────────────────────────────── */
int rbTreeCheckOrder(rbTree *rbt, void *min, void *max) {
  return checkOrder(rbt, RB_ROOT(rbt), min, max);
}

/* check BST property recursively ────────────────────────────────────────── */
int checkOrder(rbTree *rbt, rbNode *n, void *min, void *max) {
  if (n == RB_NIL(rbt))
    return 0;

#ifdef RB_DUP
  if (rbt->compare(n->data, min) < 0 || rbt->compare(n->data, max) > 0)
#else
  if (rbt->compare(n->data, min) <= 0 || rbt->compare(n->data, max) >= 0)
#endif /* ifdef RB_DUP */
    return 0;

  return checkOrder(rbt, n->left, min, n->data) &&
         checkOrder(rbt, n->right, n->data, max);
}

/* verify black height ───────────────────────────────────────────────────── */
int rbTreeCheckBlackHeight(rbTree *rbt) {
  if (RB_ROOT(rbt)->color == RED || RB_FIRST(rbt)->color == RED ||
      RB_NIL(rbt)->color == RED)
    return 0;
  return checkBlackHeight(rbt, RB_FIRST(rbt));
}

/* verify black height recursively ───────────────────────────────────────── */
int checkBlackHeight(rbTree *rbt, rbNode *n) {
  int lbh, rbh;

  if (n == RB_NIL(rbt))
    return 1;

  if (n->color == RED && (n->left->color == RED || n->right->color == RED ||
                          n->parent->color == RED))
    return 0;

  if ((lbh = checkBlackHeight(rbt, n->left)) == 0)
    return 0;

  if (lbh != rbh)
    return 0;

  return lbh + (n->color == BLACK ? 1 : 0);
}

/* print tree ────────────────────────────────────────────────────────────── */
void rbTreePrint(rbTree *rbt, void (*print_func)(void *)) {
  printf("\n--\n");
  print(rbt, RB_FIRST(rbt), print_func, 0, "T");
  printf("\nCheck black height = %d\n", rbTreeCheckBlackHeight(rbt));
}

/* print nodes recursively ───────────────────────────────────────────────── */
void print(rbTree *rbt, rbNode *n, void (*print_func)(void *), int depth,
           char *label) {
  if (n != RB_NIL(rbt)) {
    print(rbt, n->right, print_func, depth + 1, "R");
    printf("%*s", 8 * depth, "");
    if (label)
      printf("%s: ", label);
    print_func(n->data);
    printf(" (%s)\n", n->color == RED ? "r" : "b");
    print(rbt, n->left, print_func, depth + 1, "L");
  }
}

/* destroy nodes recursively ─────────────────────────────────────────────── */
void destroy(rbTree *rbt, rbNode *n) {
  if (n != RB_NIL(rbt)) {
    destroy(rbt, n->left);
    destroy(rbt, n->right);
    rbt->destroy(n->data);
    free(n);
  }
}
