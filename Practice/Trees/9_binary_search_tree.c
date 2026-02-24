#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode)
    return NULL;

  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

TreeNode *insertNode(int key, TreeNode *root) {
  if (!root)
    return initNode(key);

  if (key <= root->data) {
    root->left = insertNode(key, root->left);
  } else {
    root->right = insertNode(key, root->right);
  }

  return root;
}

void in_order_tree_walk(TreeNode *root) {
  if (root) {
    in_order_tree_walk(root->left);
    printf("%d ", root->data);
    in_order_tree_walk(root->right);
  }
}

void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    free(root);
    freeTree(root->right);
  }
}

int main(int argc, char *argv[]) {
  TreeNode *root = initNode(6);
  root = insertNode(8, root);
  root = insertNode(7, root);
  root = insertNode(4, root);
  root = insertNode(9, root);

  printf("In order treewalk: ");
  in_order_tree_walk(root);
  printf("\n");

  freeTree(root);
  return EXIT_SUCCESS;
}
