#include "avl.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize enode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    perror("Memory allocation failed!\n");
    exit(1);
  }
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->data = data;
  newnode->height = 1;

  return newnode;
}

// get height of node
int getHeight(const TreeNode *node) {
  return (node == NULL) ? 0 : node->height;
}

// update height of node
void updateHeight(TreeNode *node) {
  node->height = max(getHeight(node->left), getHeight(node->right));
}

// find max
int max(int a, int b) { return (a > b) ? a : b; }

// get balance factor of node
int getBalanceFactor(TreeNode *node) {
  return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// left rotate
TreeNode *leftRotate(TreeNode *x) {
  TreeNode *y = x->right;
  TreeNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  updateHeight(y);
  updateHeight(x);

  return y;
}

// right rotate
TreeNode *rightRotate(TreeNode *x) {
  TreeNode *y = x->left;
  TreeNode *T2 = y->right;

  y->right = x;
  x->left = T2;

  updateHeight(y);
  updateHeight(x);

  return y;
}

// insert node
TreeNode *insertNode(TreeNode *root, int key) {
  if (!root)
    return initNode(key);

  if (key >= root->data) {
    root->right = insertNode(root->right, key);
  } else {
    root->left = insertNode(root->left, key);
  }

  updateHeight(root);

  int balance_factor = getBalanceFactor(root);

  if (balance_factor > 1 && root->left->data > key) {
    return rightRotate(root);
  }
  if (balance_factor < -1 && root->right->data < key) {
    return leftRotate(root);
  }
  if (balance_factor > 1 && root->left->data < key) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (balance_factor < -1 && root->right->data > key) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// in order traversal
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

// main
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
