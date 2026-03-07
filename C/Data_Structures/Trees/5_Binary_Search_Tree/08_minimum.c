#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize node
TreeNode *init_node(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// insert nodes
TreeNode *insert(TreeNode *root, int key) {
  if (!root)
    return init_node(key);

  if (root->data <= key)
    root->right = insert(root->right, key);
  else
    root->left = insert(root->left, key);

  return root;
}

// find minimum node in a bst
TreeNode *minimum(TreeNode *root) {
  if (!root)
    return NULL;

  TreeNode *min = NULL;

  // visit leftmost leaf
  while (root) {
    min = root;
    root = root->left;
  }

  return min;
}

// in order tree walk
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }
}

// free tree
void free_tree(TreeNode *root) {
  if (root) {
    free_tree(root->left);
    free(root);
    free_tree(root->right);
  }
}

// main
int main(int argc, char *argv[]) {
  int pre_order[] = {20, 16, 5, 18, 17, 19, 60, 85, 70};
  int size = sizeof(pre_order) / sizeof(pre_order[0]);
  TreeNode *root = init_node(pre_order[0]);

  for (int i = 1; i < size; i++) {
    root = insert(root, pre_order[i]);
  }

  if (root)
    printf("Tree created successfully!");
  else
    printf("Failed!\n");

  printf("In-order: [ ");
  in_order(root);
  printf("]\n");

  TreeNode *min = minimum(root);
  printf("Minimum in bst: %d\n", min->data);

  free_tree(root);
  return EXIT_SUCCESS;
}
