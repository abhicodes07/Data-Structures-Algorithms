#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initalize the tree node
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

// find the last right of a node
TreeNode *findLastRight(TreeNode *root) {
  if (root->right == NULL)
    return root;

  return findLastRight(root->right);
}

// helper function to delete a node
TreeNode *helper(TreeNode *root) {
  TreeNode *temp;

  // if there's no left subtree,
  // return right subtree
  if (root->left == NULL) {
    temp = root->right;
    free(root);
    return temp;
  }

  // if there's no right subtree,
  // return left subtree
  else if (root->right == NULL) {
    temp = root->left;
    free(root);
    return temp;
  }

  // right child of root
  TreeNode *rightChild = root->right;

  // lastRight of root
  TreeNode *lastRight = findLastRight(root->left);

  // update link
  lastRight->right = rightChild;

  // free and return node
  temp = root->left;
  free(root); // free node
  return temp;
}

// deletion
TreeNode *delete(TreeNode *root, int key) {
  if (!root) {
    return NULL;
  }

  // if node to be deleted is root
  if (root->data == key) {
    return helper(root);
  }

  TreeNode *temp = root;
  while (root) {
    // go to the left subtree
    if (root->data > key) {
      if (root->left != NULL && root->left->data == key) {
        root->left = helper(root->left);
        break;
      } else {
        root = root->left;
      }
    }
    // go to the right subtree
    else {
      if (root->right != NULL && root->right->data == key) {
        root->right = helper(root->right);
        break;
      } else {
        root = root->right;
      }
    }
  }

  return temp;
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
