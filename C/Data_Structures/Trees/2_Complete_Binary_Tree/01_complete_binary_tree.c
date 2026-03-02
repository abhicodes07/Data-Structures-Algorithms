// Implementation of complete binary tree
// in complete tree all levels are completely
// filled except the last level and at last
// level, the leaf nodes are left as possible
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenodes
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode)
    return NULL;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// count the number of nodes
int count(TreeNode *root) {
  if (root == NULL)
    return 0;

  return 1 + count(root->left) + count(root->right);
}

// if the tree is complete binary tree
bool isCompleteBinaryTree(TreeNode *root, int index, int count) {
  if (!root)
    return true;

  if (index >= count)
    return false;

  return (isCompleteBinaryTree(root->left, 2 * index + 1, count) &&
          isCompleteBinaryTree(root->right, 2 * index + 2, count));
}

// main
int main(int argc, char *argv[]) {
  TreeNode *root = initNode(1);
  root->left = initNode(2);
  root->right = initNode(3);
  root->left->left = initNode(4);
  root->left->right = initNode(5);
  root->right->right = initNode(6);

  int node_count = count(root);
  int index = 0;

  if (isCompleteBinaryTree(root, index, node_count)) {
    printf("Tree is complete binary tree.\n");
  } else {
    printf("Tree is not a complete binary tree.\n");
  }
  return EXIT_SUCCESS;
}
