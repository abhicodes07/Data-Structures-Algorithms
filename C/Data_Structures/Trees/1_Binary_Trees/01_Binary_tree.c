/* IMPLEMENTATION OF BINARY TREE USING LINKED NODES */

// incudes
#include <stdio.h>
#include <stdlib.h>

// create a node of a tree
struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

// create a tree
struct TreeNode *createTree() {
  // create a newnode and enter the information from runtime
  int val;
  printf("Enter data (-1 for no node): ");
  scanf("%d", &val);

  if (val == -1)
    return 0;

  struct TreeNode *newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

  if (!newnode) {
    printf("Memory allocation failed!");
    exit(1);
  }

  // recursively create nodes
  newnode->data = val;

  printf("LEFT NODE OF %d --> ", val);
  newnode->left = createTree();

  printf("RIGHT NODE OF %d --> ", val);
  newnode->right = createTree();

  return newnode;
}

// main function
int main() {
  // create a root pointer
  struct TreeNode *root;
  root = createTree();

  if (root) {
    printf("\nTree successfully created!!\n");
  }
  return 0;
}
