#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ── Tree operations ─────────────────────────────────────────────────────────
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

// ── AVL helpers ────────────────────────────────────────────────────────────
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

// ── AVL operations ─────────────────────────────────────────────────────────
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

// ── insert node ──────────────────────────────────────────────────────────────
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

// ── find in order predecessor ────────────────────────────────────────────────
TreeNode *findPredecessor(TreeNode *root) {
  TreeNode *curr = root;
  while (curr && curr->right != NULL) {
    curr = curr->right;
  }
  return curr;
}

// ── delete node ──────────────────────────────────────────────────────────────
TreeNode *deleteNode(TreeNode *root, int key) {
  if (!root)
    return NULL;

  TreeNode *temp;

  // search the right-subtree
  if (root->data < key) {
    root->right = deleteNode(root->right, key);
  }
  // search left-subtree
  else if (root->data > key) {
    root->left = deleteNode(root->left, key);
  }
  // perform deletion
  else {
    // node with single child case
    if (root->left == NULL) {
      temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      temp = root->left;
      free(root);
      return temp;
    }
    // node with two children case
    else {
      // find in-order predecessor of nodeToBeDeleted
      TreeNode *predecessor = findPredecessor(root->left);

      // copy the predecessor into the nodeToBeDeleted
      root->data = predecessor->data;

      // delete the predecessor
      root->left = deleteNode(root->left, predecessor->data);
    }
  }

  // update height of nodes
  if (root)
    updateHeight(root);

  // get balance factor of a node
  int balance_factor = getBalanceFactor(root);

  // perform rotation if unbalanced

  // NOTE: the right-right case:
  // balance_factor < -1 means that the root is right heavy
  // and getBalanceFactor(root->right) <= 0 means that the root's right child is
  // also right heavy so we perform left rotation.
  // Also, balance_factor(root->right) == 0 can happen during
  // node deletion
  // eg:
  //  15 (BF = -2)  <- Root is unbalanced, right-heavy
  //    \
  //    20 (BF = -1) <- Right child is also right-heavy (<= 0)
  //     \
  //     30 (BF = 0)
  if (balance_factor < -1 && getBalanceFactor(root->right) <= 0)
    return leftRotate(root);

  //  NOTE: the right-left case:
  // balance_factor < -1 means that the root is right heavy
  // but getBalanceFactor(root->right) > 0 means that the right child leans left
  // creating a zig-zag. so we perform right-left rotation
  // eg:
  //  15 (BF = -2)  <- Root is unbalanced
  //   \
  //    30 (BF = 1)  <- Right child is left-heavy (> 0)
  //   /
  // 20 (BF = 0)
  if (balance_factor < -1 && getBalanceFactor(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  // NOTE: the left-right case:
  // balance_factor > 1 means that the root is left-heavy
  // and getBalanceFactor(root->left) < 0 means that the root->left is leaning
  // to right creating a zig-zag. so we perfrom left-right rotation eg:
  //     30 (BF = 2)   <- Root is unbalanced
  //    /
  //  15 (BF = -1)      <- Left child is right-heavy (< 0)
  //   \
  //    20 (BF = 0)
  if (balance_factor > 1 && getBalanceFactor(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // NOTE: the left-left case
  // balance_factor > 1 means that the root is left-heavy and
  // getBalanceFactor(root->left) >= 1 means that the left-child is also
  // left heavy or balanced (>=0) so we perfrom right-rotation
  // eg:
  //       30 (BF = 2)   <- Root is unbalanced
  //      /
  //    20 (BF = 1)       <- Left child is left-heavy (>= 0)
  //    /
  //  15 (BF = 0)
  if (balance_factor > 1 && getBalanceFactor(root->left) >= 0)
    return rightRotate(root);

  return root;
}

// ── Print and free tree ──────────────────────────────────────────────────────
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

// ── main ─────────────────────────────────────────────────────────────────────
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
