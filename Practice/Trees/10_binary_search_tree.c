#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Treenode data-type
typedef struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

// initialize treenode
TreeNode *initNode(int data) {
  TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
  if (!newnode) {
    perror("Memory allocation failed!\n");
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// insert in tree
TreeNode *insert(TreeNode *root, int val) {
  if (!root)
    return initNode(val);

  if (val <= root->data) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }

  return root;
}

// print nodes: in-order
void inOrder(TreeNode *root) {
  if (root) {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}

// free tree
void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    free(root);
    freeTree(root->right);
  }
}

// main
int main(int argc, char *argv[]) {
  int list[] = {14, 17, 11, 7, 53, 4, 13, 12, 8, 60, 19, 16, 20};
  int size = sizeof(list) / sizeof(list[0]);

  TreeNode *root = insert(root, list[0]);
  for (int i = 1; i < size; i++) {
    root = insert(root, list[i]);
  }

  printf("In-order: [ ");
  inOrder(root);
  printf("]\n");

  freeTree(root);
  return EXIT_SUCCESS;
}
