#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize node
TreeNode *init_node(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    fprintf(stderr, "Memory allocation failed!\n");
    free(newnode);
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// helper function
TreeNode *insert(TreeNode *root, int key) {
  if (!root)
    return init_node(key);

  if (root->data <= key)
    root->right = insert(root->right, key);
  if (root->data >= key)
    root->left = insert(root->left, key);

  return root;
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
  return EXIT_SUCCESS;
}
