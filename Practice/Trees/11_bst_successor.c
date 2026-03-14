#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

// initialize treenode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    perror("memory allocation failed!\n");
    return NULL;
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// insert nodes
TreeNode *insert(TreeNode *root, int val) {
  if (!root)
    return initNode(val);

  if (val < root->data) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  return root;
}

// successor
TreeNode *successor(TreeNode *root, int data) {
  if (!root)
    return NULL;

  TreeNode *succ = NULL;
  while (root) {
    if (root->data > data) {
      succ = root;
      root = root->left;
    } else {
      root = root->right;
    }
  }

  return succ;
}

// in order treewalk
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }
}

void free_tree(TreeNode *root) {
  if (root) {
    free_tree(root->left);
    free(root);
    free_tree(root->right);
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
  in_order(root);
  printf("]\n");

  printf("Successor of %d: ", list[6]);
  TreeNode *succ = successor(root, list[6]);
  printf("%d\n", succ->data);

  free_tree(root);
  return EXIT_SUCCESS;
}
