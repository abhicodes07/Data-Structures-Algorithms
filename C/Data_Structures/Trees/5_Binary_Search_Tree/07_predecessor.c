#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// create treenode
TreeNode *init_node(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(1);
  }
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->data = data;
  return newnode;
}

// insert nodes in tree
TreeNode *insert(TreeNode *root, int key) {
  if (!root)
    return init_node(key);

  if (root->data < key) {
    root->right = insert(root->right, key);
  } else {
    root->left = insert(root->left, key);
  }

  return root;
}

// predecessor of element in tree
TreeNode *predecessor(TreeNode *root, int key) {
  if (!root)
    return NULL;

  TreeNode *pred = NULL;

  // predecssor of a element x is the
  // largest key that is smaller than x.
  while (root) {
    if (root->data < key) {
      pred = root;
      root = root->right;
    } else {
      root = root->left;
    }
  }

  return pred;
}

// in order tree walk: left->root->right
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);
    printf("%d", root->data);
    in_order(root->right);
  }
}

// free tree nodes
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

  // in order of tree
  printf("In-order: [ ");
  in_order(root);
  printf("\n");

  // predecessors
  TreeNode *pred1 = predecessor(root, 16);
  TreeNode *pred2 = predecessor(root, 5);
  TreeNode *pred3 = predecessor(root, 60);

  if (pred1)
    printf("predecssor of 16: %d\n", pred1->data);
  else
    printf("Predecessor of 16 is None (smallest value)\n");

  if (pred2)
    printf("predecssor of 5: %d\n", pred2->data);
  else
    printf("Predecessor of 5 is None (smallest value)\n");

  if (pred3)
    printf("predecssor of 60: %d\n", pred3->data);
  else
    printf("Predecessor of 60 is None (smallest value)\n");

  free_tree(root);
  return EXIT_SUCCESS;
}
