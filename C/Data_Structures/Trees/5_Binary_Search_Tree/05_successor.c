// find successor of key in BST

// Time complexity:
// Best case : O(logn)
// Worst case: O(n) (skewed tree)

#include "Ptree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize node
TreeNode *init_node(TreeNode *parent, int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->parent = parent;

  return newnode;
}

// insert nodes in tree
TreeNode *insert(TreeNode *root, TreeNode *parent, int key) {
  if (!root)
    return init_node(parent, key);

  if (key <= root->data)
    root->left = insert(root->left, root, key);
  else
    root->right = insert(root->right, root, key);

  return root;
}

// helper to find the key and it's node in tree
TreeNode *find(TreeNode *root, int key) {
  if (!root)
    return NULL;

  TreeNode *node = NULL;

  if (key == root->data)
    node = root;
  else if (key < root->data)
    node = find(root->left, key);
  else
    node = find(root->right, key);

  return node;
}

// helper function
TreeNode *helper(TreeNode *root, TreeNode *node) {
  if (!root || !node)
    return NULL;

  // initially successor is nil
  TreeNode *succ = NULL;

  // if the node has right subtree then
  // then check the leftmost leaf in
  // the right subtree
  if (node->right) {
    succ = node->right;
    while (succ->left) {
      succ = succ->left;
    }
  } else {
    succ = node->parent;
    TreeNode *curr = node;
    while (succ != NULL && curr == succ->right) {
      curr = succ;
      succ = succ->parent;
    }
  }

  return succ;
}

// find successor of key node
void successor(TreeNode *root, int key) {
  TreeNode *key_node = find(root, key);
  TreeNode *succ = helper(root, key_node);

  if (!key_node)
    printf("%d not found in tree.\n", key);

  if (!succ)
    printf("%d doesn't have successor, it is the largest element in tree.\n",
           key_node->data);
  else
    printf("Successor: %d\n", succ->data);
}

// in order tree walk
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);
    printf("=================================\n");
    printf("\tParent: ");
    if (root->parent)
      printf("%d\n", root->parent->data);
    else
      printf("NULL\n");
    printf("\tValue: %d\n", root->data);
    printf("=================================\n");
    in_order(root->right);
  }
}

// free tree
void free_tree(TreeNode *root) {
  if (root) {
    free_tree(root->left);
    free(root);
    free_tree(root->right);
  }
}

// main
int main(int argc, char *argv[]) {
  int pre_order[] = {20, 16, 5, 18, 17, 19, 60, 85, 70};
  int size = sizeof(pre_order) / sizeof(pre_order[0]);

  // initialize root
  TreeNode *root = init_node(NULL, pre_order[0]);

  // create tree
  for (int i = 1; i < size; i++) {
    root = insert(root, NULL, pre_order[i]);
  }

  if (root)
    printf("Tree created successfully!\n");
  else
    printf("Failed!\n");

  // print tree using in-order treewalk
  printf("================= In-order =================\n");
  printf("____________________________________________\n");
  in_order(root);
  printf("\n");

  successor(root, 16);
  successor(root, 85);

  // free tree
  free_tree(root);
  return EXIT_SUCCESS;
}
