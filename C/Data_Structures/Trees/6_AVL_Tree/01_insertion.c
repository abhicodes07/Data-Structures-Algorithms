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
int getHeight(TreeNode *node) { return (node == NULL) ? 0 : node->height; }

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
  // STEP-1 : insert node
  if (!root)
    return initNode(data);

  if (data <= root->data) {
    root->left = insertNode(root->left, data);
  } else {
    root->right = insertNode(root->right, data);
  }

  // STEP-2 :
  // update height
  updateHeight(root);

  // get balance factor
  int balance_factor = getBalanceFactor(root);
  return root;
}

// ── Print and free tree ──────────────────────────────────────────────────────
// in order tree walk
void inOrderWalk(TreeNode *root) {
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

// main
int main(int argc, char *argv[]) {
  int list[] = {14, 17, 11, 7, 53, 4, 13, 12, 8, 60, 19, 16, 20};
  int size = sizeof(list) / sizeof(list[0]);

  TreeNode *root = initNode(list[0]);
  for (int i = 1; i < size; i++) {
    root = insertNode(root, list[i]);
  }

  printf("In-order: ");
  inOrderWalk(root);
  printf("\n");

  return EXIT_SUCCESS;
}
