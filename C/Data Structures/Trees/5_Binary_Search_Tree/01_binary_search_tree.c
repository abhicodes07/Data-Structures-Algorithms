/* Binary search trees follow the following property:
 * LEFT <= ROOT <= RIGHT */

#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize node
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (newnode == NULL) {
    perror("Memory allocation failed!\n");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// insert node in BST using recursion
TreeNode *insert(TreeNode *root, int key) {
  if (!root)
    return initNode(key);

  // go to right subtree
  // if the value is greater than the root
  if (root->data <= key)
    root->right = insert(root->right, key);

  // go to left subtree
  // if the value is smaller than the root
  else
    root->left = insert(root->left, key);

  // return the root
  return root;
}

// in order traversal of a tree
// always gives sorted values in
// ascending order
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }
}

// main
int main(int argc, char *argv[]) {
  TreeNode *root = initNode(6);
  root = insert(root, 4);
  root = insert(root, 2);
  root = insert(root, 5);
  root = insert(root, 8);
  root = insert(root, 7);
  root = insert(root, 9);

  if (root)
    printf("\nTree created successfully!\n");

  printf("Elements in BST: ");
  in_order(root);
  printf("\n");

  return EXIT_SUCCESS;
}
