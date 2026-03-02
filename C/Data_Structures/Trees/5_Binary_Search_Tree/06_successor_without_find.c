// find successor of key in BST

// Time complexity:
// Best case : O(logn)
// Worst case: O(n) (skewed tree)

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

// insert nodes in tree
TreeNode *insert(TreeNode *root, int key) {
  if (!root)
    return init_node(key);

  if (key <= root->data)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);

  return root;
}

// find successor of key node
TreeNode *successor(TreeNode *root, int key) {
  if (!root)
    return NULL;

  TreeNode *succ = NULL;

  while (root) {
    if (root->data > key) {
      succ = root;
      root = root->left;
    } else {
      root = root->right;
    }
  }

  return succ;
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

  // initialize root
  TreeNode *root = init_node(pre_order[0]);

  // create tree
  for (int i = 1; i < size; i++) {
    root = insert(root, pre_order[i]);
  }

  if (root)
    printf("Tree created successfully!\n");
  else
    printf("Failed!\n");

  // print tree using in-order treewalk
  printf("================= In-order =================\n");
  // printf("____________________________________________\n");
  in_order(root);
  printf("\n");

  TreeNode *succ1 = successor(root, 16);
  TreeNode *succ2 = successor(root, 85);

  if (succ1)
    printf("%d\n", succ1->data);
  else
    printf("None (no larger value)\n");

  printf("Successor of 85: ");
  if (succ2)
    printf("%d\n", succ2->data);
  else
    printf("None (maximum in tree)\n");

  // free tree
  free_tree(root);
  return EXIT_SUCCESS;
}
