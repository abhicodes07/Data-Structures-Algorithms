// IMPLEMENTATION OF TRAVERSAL OPERATION ON BINARY SERACH TREE

#include <stdio.h>
#include <stdlib.h>

// create a node
struct TreeNode {
  int data;
  struct TreeNode *right;
  struct TreeNode *left;
};

// create a binary tree
struct TreeNode *create_tree() {
  int val;
  struct TreeNode *newnode;

  printf("Enter the data (-1 for no node): ");
  scanf("%d", &val);

  if (val == -1)
    return 0;

  // create a newnode
  newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  if (!newnode)
    exit(1);

  // create nodes left and right recursively
  newnode->data = val;

  printf("LEFT NODE OF %d --> ", val);
  newnode->left = create_tree();

  printf("Right NODE OF %d --> ", val);
  newnode->right = create_tree();

  return newnode;
}

// pre order traversal
void pre_order(struct TreeNode *root) {
  if (root) {
    printf("%d ", root->data); // root
    pre_order(root->left);     // left sub-tree
    pre_order(root->right);    // right sub-tree
  }
}

// in order traversal
void in_order(struct TreeNode *root) {
  if (root) {
    pre_order(root->left);     // left sub-tree
    printf("%d ", root->data); // root
    in_order(root->right);     // right sub-tree
  }
}

// post order traversal
void post_order(struct TreeNode *root) {
  if (root) {
    post_order(root->left);    // left sub-tree
    post_order(root->right);   // right sub-tree
    printf("%d ", root->data); // root
  }
}

// main
int main(void) {
  struct TreeNode *root;
  root = create_tree();
  if (root)
    printf("Tree successfully created!\n");

  // traverse tree
  printf("Pre order traversal of tree: ");
  pre_order(root);
  printf("\n");

  printf("Post order traversal of tree: ");
  post_order(root);
  printf("\n");

  printf("In order traversal of tree: ");
  in_order(root);
  printf("\n");

  return 0;
}
