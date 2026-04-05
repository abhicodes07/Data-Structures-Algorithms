#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  int data;
  int height;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

// initnode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    perror("Memory allocation failed!\n");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->height = 1;
  return newnode;
}

// utility functions
int max(int a, int b) { return (a > b) ? a : b; }
int getHeight(TreeNode *node) { return (node == NULL) ? 0 : node->height; }
void updateHeight(TreeNode *node) {
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}
int getBalanceFactor(TreeNode *node) {
  return (node == NULL) ? 0 : getHeight(node->right) - getHeight(node->left);
}

// left rotation
TreeNode *leftRotate(TreeNode *x) {
  TreeNode *y = x->right;
  TreeNode *T3 = y->right;

  x->right = T3;
  y->left = x;

  updateHeight(x);
  updateHeight(y);

  return y;
}

// right rotation
TreeNode *rightRotate(TreeNode *y) {
  TreeNode *x = y->left;
  TreeNode *T2 = x->left;

  x->right = y;
  y->left = T2;

  updateHeight(x);
  updateHeight(y);

  return x;
}

TreeNode *insert(TreeNode *root, int data) {
  if (!root)
    return initNode(data);

  if (root->data > data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  updateHeight(root);
  int balance_factor = getBalanceFactor(root);
}

// preorder
void inOrder(TreeNode *root) {
  if (root) {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
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
int main(int argc, char *argv[]) { return EXIT_SUCCESS; }
