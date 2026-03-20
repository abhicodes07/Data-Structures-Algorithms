#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*================== utility functions =================*/
// initialize node
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    perror("Memory allocation failed!\n");
  }
  newnode->data = data;
  newnode->height = 1;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// get node height
int getHeight(TreeNode *node) { return (node == NULL) ? 0 : node->height; }

// get maximum height
int max(int a, int b) { return (a > b) ? a : b; }

// get balance factor of a node
int getBalanceFactor(TreeNode *node) {
  return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

/*================== rotation functions =================*/
TreeNode *leftRotate(TreeNode *node) {}

/*===================== insertion ======================*/
// insert node in tree maintaining BST property
TreeNode *insertNode(TreeNode *root, int data) {
  if (!root)
    return initNode(data);

  if (root->data <= data)
    root->right = insertNode(root->right, data);
  else
    root->left = insertNode(root->left, data);

  // height of node
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  return root;
}

// inorder tree walk
void inOrderWalk(TreeNode *root) {
  if (root) {
    inOrderWalk(root->left);
    printf("%d ", root->data);
    inOrderWalk(root->right);
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
