#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    perror("Memory allocation failed!\n");
    exit(1);
  }
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  newnode->height = 1;
  return newnode;
}

// get node height
int getHeight(const TreeNode *node) { return (!node) ? 0 : node->height; }

// get maximum height
int max(int a, int b) { return (a > b) ? a : b; }

// update height of the node
void updateHeight(TreeNode *node) {
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// get balance factor of a node
int getBalanceFactor(TreeNode *node) {
  return (!node) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// left rotation
TreeNode *leftRotate(TreeNode *x) {
  TreeNode *y = x->right;
  TreeNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  updateHeight(x);
  updateHeight(y);

  return y;
}

// right rotation
TreeNode *rightRotate(TreeNode *x) {
  TreeNode *y = x->left;
  TreeNode *T2 = y->right;

  y->right = x;
  x->left = T2;

  updateHeight(x);
  updateHeight(y);

  return y;
}

// insert a node in a tree
TreeNode *insertNode(TreeNode *root, int key) {
  if (!root)
    return initNode(key);

  if (key <= root->data) {
    root->left = insertNode(root->left, key);
  } else {
    root->right = insertNode(root->right, key);
  }

  // update heights
  updateHeight(root);

  // get balance factor
  int balance_factor = getBalanceFactor(root);

  // right insertions
  if (balance_factor < -1) {
    if (key > root->right->data) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }

  // left insertions
  if (balance_factor > 1) {
    if (key < root->left->data) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }

  return root;
}

// find the in order predecessor
TreeNode *findPredecessor(TreeNode *root) {
  TreeNode *curr = root;
  while (curr && curr->right != NULL) {
    curr = curr->right;
  }
  return curr;
}

// delete a node
TreeNode *deleteNode(TreeNode *root, int key) {
  if (!root)
    return NULL;

  TreeNode *temp;

  if (root->data < key) {
    root->right = deleteNode(root->right, key);
  } else if (root->data > key) {
    root->left = deleteNode(root->left, key);
  } else {
    if (root->left == NULL) {
      temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      temp = root->left;
      free(root);
      return temp;
    } else {
      TreeNode *predecessor = findPredecessor(root->left);
      root->data = predecessor->data;
      root->left = deleteNode(root->left, predecessor->data);
    }
  }

  // update height of nodes
  if (root)
    updateHeight(root);

  // get balance factor of a node
  int balance_factor = getBalanceFactor(root);

  // perform rotation if unbalanced
  if (balance_factor < -1 && getBalanceFactor(root->right) <= 0)
    return leftRotate(root);

  if (balance_factor < -1 && getBalanceFactor(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  if (balance_factor > 1 && getBalanceFactor(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance_factor > 1 && getBalanceFactor(root->left) >= 0)
    return rightRotate(root);

  return root;
}

// in order tree walk
void inOrderWalk(const TreeNode *root) {
  if (root) {
    inOrderWalk(root->left);
    printf("%d ", root->data);
    inOrderWalk(root->right);
  }
}

// free tree nodes
void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

// main
int main(int argc, char *argv[]) {
  int list[] = {14, 11, 19, 7, 12, 17, 50, 4, 8, 13, 16, 20, 60};
  int size = sizeof(list) / sizeof(list[0]);
  TreeNode *root = NULL;

  for (int i = 0; i < size; i++) {
    root = insertNode(root, list[i]);
  }

  printf("In-order walk: [ ");
  inOrderWalk(root);
  printf("]\n");

  // delete node with two children
  printf("Node to be deleted: %d\n", 11);
  root = deleteNode(root, 11);
  printf("New In-order after deletion: [ ");
  inOrderWalk(root);
  printf("]\n");

  printf("Node to be deleted: %d\n", 19);
  root = deleteNode(root, 19);
  printf("New In-order after deletion: [ ");
  inOrderWalk(root);
  printf("]\n");

  // delete leaf node
  printf("Node to be deleted: %d\n", 20);
  root = deleteNode(root, 20);
  printf("New In-order after deletion: [ ");
  inOrderWalk(root);
  printf("]\n");

  // delete with only one children
  printf("Node to be deleted: %d\n", 17);
  root = deleteNode(root, 17);
  printf("New In-order after deletion: [ ");
  inOrderWalk(root);
  printf("]\n");

  // free tree
  freeTree(root);
  return EXIT_SUCCESS;
}
