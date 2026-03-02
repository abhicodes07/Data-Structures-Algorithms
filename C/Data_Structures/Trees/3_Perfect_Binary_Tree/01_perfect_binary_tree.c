/* check if a tree is perfect binary
 * tree using recursive approach
 * Time complexity = O(n)
 * space complexity = O(log(n))
 */
#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize newnode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode)
    return NULL;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

int is_perfect_binary_tree(TreeNode *root) {
  if (!root)
    return 0;

  int lh = is_perfect_binary_tree(root->left);  // height of left subtree
  int rh = is_perfect_binary_tree(root->right); // height of right subtree

  // if subtrees are not perfect or heights differ, not perfect
  if (lh == -1 || rh == -1 || lh != rh) {
    return -1;
  }

  return 1 + lh; // return height of current tree
}

void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

int main(int argc, char *argv[]) {
  TreeNode *root = initNode(1);
  if (root == NULL) { // Check malloc failure
    printf("Memory allocation failed.\n");
    return EXIT_FAILURE;
  }
  root->left = initNode(2);
  root->right = initNode(3);
  root->left->left = initNode(4);
  root->left->right = initNode(5);
  root->right->left = initNode(6);
  root->right->right = initNode(7); // Making it perfect (full last level)

  if (is_perfect_binary_tree(root) != -1)
    printf("Tree is perfect binary tree!\n");
  else
    printf("Tree is not perfect binary tree!\n");

  freeTree(root);
  return EXIT_SUCCESS;
}
