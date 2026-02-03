// Binary tree implementation
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* create a treenode */
typedef struct treenode {
  int data;               // stores the data part
  struct treenode *left;  // points to left nodes
  struct treenode *right; // points to right nodes
} Treenode;

// initialize newnode
Treenode *initNode(int data) {
  Treenode *node = (Treenode *)malloc(sizeof(Treenode));
  if (node == NULL) {
    printf("Memory allocation failed!\n");
    exit(0);
  }
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// create binary tree using recursion
Treenode *createTree() {
  int val;
  printf("Enter the data (-1 for no node): ");
  scanf("%d", &val);

  if (val == -1)
    return 0;

  Treenode *newnode = initNode(val);

  printf("Left node of %d ~~> ", newnode->data);
  newnode->left = createTree();

  printf("right node of %d ~~> ", newnode->data);
  newnode->right = createTree();
  return newnode;
}

// traverse using pre order traversal
void traverse(Treenode *root) {
  if (root) {
    printf("%d ", root->data); // root
    traverse(root->left);      // left
    traverse(root->right);     // right
  }
}

// main
int main(int argc, char *argv[]) {
  Treenode *root;
  root = createTree();
  printf("Elements in the list: [ ");
  traverse(root);
  return EXIT_SUCCESS;
}
