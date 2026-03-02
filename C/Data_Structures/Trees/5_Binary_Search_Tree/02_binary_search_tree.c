/* Binary search tree using iterative algorithm */

#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
TreeNode *init_node(int data) {
  TreeNode *newnode = malloc(sizeof("* newnode"));
  if (!newnode) {
    perror("Memory allocation failed!\n");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

/* insert node in BST */
TreeNode *insert(TreeNode *root, int key) {
  // if null is encountered
  // create a newnode
  if (!root)
    return init_node(key);

  TreeNode *curr = root;
  while (true) {
    if (curr->data <= key) { // move to right subtree
      if (curr->right == NULL) {
        curr->right = init_node(key);
        break;
      } else {
        curr = curr->right;
      }
    } else { // move to left subtree
      if (curr->left == NULL) {
        curr->left = init_node(key);
        break;
      } else {
        curr = curr->left;
      }
    }
  }

  // return tree on insertion
  return root;
}

// traverse tree using In-Order Treewalk
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);      // left
    printf("%d ", root->data); // root
    in_order(root->right);     // right
  }
}

// free tree nodes to save memory
void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    free(root);
    freeTree(root->right);
  }
}

// main
int main(int argc, char *argv[]) {
  // initialize root node of tree
  TreeNode *root = init_node(6);

  // insert nodes in tree
  root = insert(root, 4);
  root = insert(root, 2);
  root = insert(root, 5);
  root = insert(root, 9);
  root = insert(root, 8);
  root = insert(root, 7);

  if (root)
    printf("\nTree created successfully!\n");

  // traversal
  printf("In-Order Treewalk: ");
  in_order(root);
  printf("\n");

  // free tree
  freeTree(root);

  return EXIT_SUCCESS;
}
