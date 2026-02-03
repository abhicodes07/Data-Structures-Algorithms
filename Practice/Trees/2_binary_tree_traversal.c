// Implementation of traversal in trees
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// create tree
typedef struct treenode {
  int data;               // data part
  struct treenode *left;  // points to left nodes
  struct treenode *right; // points to right nodes
} Treenode;

// initialize node
Treenode *initNode(int data) {
  Treenode *newnode = (Treenode *)malloc(sizeof(Treenode));
  if (newnode == NULL) {
    printf("Memory Allocation failed!\n");
    exit(0);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// in order traversal
void in_order(Treenode *root) {
  if (root) {
    in_order(root->left);      // left
    printf("%d ", root->data); // root
    in_order(root->right);     // right
  }
}

// pre order traversal
void pre_order(Treenode *root) {
  if (root) {
    printf("%d ", root->data); // root
    in_order(root->left);      // left
    in_order(root->right);     // right
  }
}

// post order traversal
void post_order(Treenode *root) {
  if (root) {
    in_order(root->left);      // left
    in_order(root->right);     // right
    printf("%d ", root->data); // root
  }
}

int max(int value_1, int value_2) {
  return value_1 > value_2 ? value_1 : value_2;
}

// height of the tree
int maximum_height(Treenode *root) {
  if (root == NULL)
    return 0;
  int left_height = maximum_height(root->left);
  int right_height = maximum_height(root->right);
  return 1 + max(left_height, right_height);
}

// main
int main(int argc, char *argv[]) {
  Treenode *root;
  root = initNode(10);
  root->left = initNode(20);
  root->right = initNode(30);
  root->left->left = initNode(40);
  root->left->right = initNode(50);
  root->right->left = initNode(60);
  root->right->right = initNode(70);

  printf("In order: [ ");
  in_order(root);
  printf("]\n");

  printf("Pre order: [ ");
  pre_order(root);
  printf("]\n");

  printf("Post order: [ ");
  post_order(root);
  printf("]\n");

  int height = maximum_height(root);
  printf("Maximum height of tree: %d\n", height);
  return EXIT_SUCCESS;
}
