#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize node
TreeNode *init_node(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode)
    return NULL;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// insertion
TreeNode *insert(TreeNode *root, int key) {
  if (!root)
    return init_node(key);

  if (root->data >= key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);

  return root;
}

// find in orde predecessor of an node
TreeNode *findPredecessor(TreeNode *root) {
  TreeNode *curr = root;

  while (curr && curr->right != NULL) {
    curr = curr->right;
  }

  return curr;
}

// delete a node
TreeNode *delete(TreeNode *root, int key) {
  if (!root)
    return NULL;

  if (root->data < key) {
    root->right = delete(root->right, key);
  } else if (root->data > key) {
    root->left = delete(root->left, key);
  } else {
    TreeNode *temp;
    if (root->left == NULL) {
      temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      temp = root->left;
      free(root);
      return temp;
    }

    TreeNode *rightChild = root->right;
    TreeNode *predecessor = findPredecessor(root->left);
    predecessor->right = rightChild;
    temp = root->left;
    free(root);
    return temp;
  }

  return root;
}

// in order treewalk
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

  // in order of tree
  printf("In-order: [ ");
  in_order(root);
  printf("]\n");

  root = delete(root, 16);

  printf("In-order: [ ");
  in_order(root);
  printf("]\n");

  root = delete(root, 18);

  printf("In-order: [ ");
  in_order(root);
  printf("]\n");

  free_tree(root);
  return EXIT_SUCCESS;
}
