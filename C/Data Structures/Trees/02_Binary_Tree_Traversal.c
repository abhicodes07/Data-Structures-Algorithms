// IMPLEMENTATION OF TRAVERSAL OPERATION ON BINARY SERACH TREE

#include <stdio.h>
#include <stdlib.h>

// create a node
struct Node {
  int data;
  struct Node *right;
  struct Node *left;
};

// create a binary tree
struct Node *create_tree() {
  int val;
  struct Node *newnode;

  printf("Enter the data (-1 for no node): ");
  scanf("%d", &val);

  if (val == -1)
    return 0;

  // create a newnode
  newnode = (struct Node *)malloc(sizeof(struct Node));
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
void pre_order(struct Node *root) {
  if (root) {
    printf("%d ", root->data); // root
    pre_order(root->left);     // left sub-tree
    pre_order(root->right);    // right sub-tree
  }
}

// in order traversal
void in_order(struct Node *root) {
  if (root) {
    pre_order(root->left);     // left sub-tree
    printf("%d ", root->data); // root
    in_order(root->right);     // right sub-tree
  }
}

// post order traversal
void post_order(struct Node *root) {
  if (root) {
    post_order(root->left);    // left sub-tree
    post_order(root->right);   // right sub-tree
    printf("%d ", root->data); // root
  }
}

// main
int main(void) {
  struct Node *root;
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
