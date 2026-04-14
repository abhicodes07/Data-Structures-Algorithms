#include "assert.h"
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ── Tree operations ─────────────────────────────────────────────────────────
// initialize node
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode)
    perror("Memory allocation failed!\n");
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->height = 1;

  return newnode;
}

// ── AVL helpers ────────────────────────────────────────────────────────────
// get height
int getHeight(const TreeNode *node) {
  return (node == NULL) ? 0 : node->height;
}

// update height
void updateHeight(TreeNode *node) {
  node->height = 1 + max(getHeight(node->right), getHeight(node->left));
}

// get maximum height
int max(int a, int b) { return (a > b) ? a : b; }

// get balance factor
int getBalanceFactor(TreeNode *node) {
  return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// ── AVL operations ─────────────────────────────────────────────────────────
// left rotation
// Before  (RR imbalance)              After Left rotaion
//      x                                y
//       \                             /  \
//        y                           x    T3
//       / \                         / \
//      T2  T3                      T1  T2
TreeNode *leftRotate(TreeNode *x) {
  TreeNode *y = x->right;
  TreeNode *T3 = y->right;

  // perform rotation
  y->left = x;
  x->right = T3;

  // update height
  updateHeight(y);
  updateHeight(x);

  // return new root
  return y;
}

// right rotation
// Before (LL imbalance)          After Right Rotation
//     y (height=3, BF=+2)           x (new root, BF=0 or ±1)
//    /                           /   \
//   x                           T1    y
//  / \                               / \
// T1  T2                            T2  T3
TreeNode *rightRotate(TreeNode *y) {
  TreeNode *x = y->left;
  TreeNode *T2 = x->right;

  // perform rotation
  y->left = T2;
  x->right = y;

  // update height
  updateHeight(y);
  updateHeight(x);

  // return new root
  return x;
}

// ── insert node ──────────────────────────────────────────────────────────────
// insert node in tree
TreeNode *insertNode(TreeNode *root, int data) {
  // NOTE : insert node
  if (!root)
    return initNode(data);

  if (data <= root->data) {
    root->left = insertNode(root->left, data);
  } else {
    root->right = insertNode(root->right, data);
  }

  // NOTE :  update height
  updateHeight(root);

  // NOTE : get balance factor
  int balance_factor = getBalanceFactor(root);
  printf("Balance factor of %d: %d\n", root->data, balance_factor);

  // NOTE : four rotation cases

  // left-left insertion, balance factor > 1
  //     x (root)
  //    /
  //   y
  //  /
  // z
  // balance_factor > 1 means that height of the left subtree is
  // greater than that of the right subtree
  if (balance_factor > 1 && data < root->left->data) {
    printf("UNBALANCED SUBTREE DETECTED DUE TO LEFT-LEFT INSERTION\n");
    return rightRotate(root);
  }

  // right-right insertion, balance factor < -1
  // x (root)
  //  \
  //   y
  //   \
  //    z
  // balance_factor < 1 means that height of the left subtree is
  // less than that of the right subtree
  if (balance_factor < -1 && data > root->right->data) {
    printf("UNBALANCED SUBTREE DETECTED DUE TO RIGHT-RIGHT INSERTION\n");
    return leftRotate(root);
  }

  // left-right insertion, balance factor > 1
  //     x (root) <- right rotate here
  //    /
  //   y  <- left rotate here
  //    \
  //     z
  if (balance_factor > 1 && data > root->left->data) {
    printf("UNBALANCED SUBTREE DETECTED DUE TO LEFT-RIGHT INSERTION\n");
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // right-left insertion, balance factor < -1
  //  x (root) <- left rotate here
  //   \
  //    y <- right rotate here
  //   /
  //  z
  if (balance_factor < -1 && data < root->right->data) {
    printf("UNBALANCED SUBTREE DETECTED DUE TO RIGHT-LEFT INSERTION\n");
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// ── Print and free tree ──────────────────────────────────────────────────────
// in order tree walk
void inOrderWalk(const TreeNode *root) {
  if (root) {
    inOrderWalk(root->left);
    printf("%d ", root->data);
    inOrderWalk(root->right);
  }
}

// free tree
void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    free(root);
    freeTree(root->right);
  }
}

// ── main ─────────────────────────────────────────────────────────────────────
int main(int argc, char *argv[]) {
  int list[] = {33, 13, 53, 11, 21, 61, 8, 9};
  int size = sizeof(list) / sizeof(list[0]);

  TreeNode *root = NULL;
  for (int i = 0; i < size; i++) {
    root = insertNode(root, list[i]);
    // check balance factor on every insertion
    assert(getBalanceFactor(root) >= -1 && getBalanceFactor(root) <= 1);
  }

  printf("In-order: ");
  inOrderWalk(root);
  printf("\n");

  freeTree(root);
  return EXIT_SUCCESS;
}
