#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

TreeNode *insertNode(TreeNode *root, int key) {
  if (!root)
    return initNode(key);

  if (key >= root->data) {
    root->right = insertNode(root->right, key);
  } else {
    root->left = insertNode(root->left, key);
  }

  return root;
}

TreeNode *predecessor(TreeNode *root) {
  if (root->right == NULL)
    return root;
  return predecessor(root->right);
}

TreeNode *helper(TreeNode *root) {
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
  TreeNode *pred = predecessor(root->left);

  pred->right = rightChild;
  temp = root->left;
  free(root);
  return temp;
}

TreeNode *deleteNode(TreeNode *root, int key) {
  if (!root)
    return NULL;

  TreeNode *temp = root;

  while (root) {
    // go to left subtree
    if (key < root->data) {
      if (root->left != NULL && root->left->data == key) {
        root->left = helper(root->left);
        break;
      } else {
        root = root->left;
      }
    } else {
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

void inOrderWalk(TreeNode *root) {
  if (!root)
    return;
  inOrderWalk(root->left);
  printf("%d ", root->data);
  inOrderWalk(root->right);
}

void freeTree(TreeNode *root) {
  if (!root)
    return;
  freeTree(root->left);
  free(root);
  freeTree(root->right);
}

int main(int argc, char *argv[]) {
  int pre_order[] = {20, 16, 5, 18, 17, 19, 60, 85, 70};
  int size = sizeof(pre_order) / sizeof(pre_order[0]);

  // initialize root
  TreeNode *root = initNode(pre_order[0]);

  // create tree
  for (int i = 1; i < size; i++) {
    root = insertNode(root, pre_order[i]);
  }

  if (root)
    printf("Tree created successfully!\n");
  else
    printf("Failed!\n");

  // in order of tree
  printf("In-order: [ ");
  inOrderWalk(root);
  printf("]\n");

  root = deleteNode(root, 16);

  printf("In-order: [ ");
  inOrderWalk(root);
  printf("]\n");

  root = deleteNode(root, 18);

  printf("In-order: [ ");
  inOrderWalk(root);
  printf("]\n");

  freeTree(root);
  return EXIT_SUCCESS;
}
