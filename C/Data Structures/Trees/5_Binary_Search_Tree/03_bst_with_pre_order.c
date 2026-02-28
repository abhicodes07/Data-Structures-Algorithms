#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// initialize treenode
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(*newnode));
  if (!newnode) {
    perror("Memory allocation failed!");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// get minimum element for sorting
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
int minimum(int arr[], int start, int end) {
  int min = start;
  for (int i = start + 1; i < end; i++) {
    if (arr[i] < arr[min])
      min = i;
  }
  return min;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// sort the array
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
void sort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = minimum(arr, i, size);
    if (min != i) {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// get in order (sorted) list from pre_order
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
int *get_in_order(int pre_order[], int size) {
  // allocate memory to in-order list
  int *in_order = malloc(size * sizeof(int));

  if (!in_order) {
    printf("Memory allocation failed!\n");
    return NULL;
  }

  // copy elements of pre-order to in-order
  for (int i = 0; i < size; i++) {
    in_order[i] = pre_order[i];
  }
  // then perform selection sort the in-order list
  sort(in_order, size);

  return in_order;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// free tree nodes
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
void free_tree(TreeNode *root) {
  if (root) {
    free_tree(root->left);
    free(root);
    free_tree(root->right);
  }
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// find root in order
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
int find(int root_value, int arr[], int start, int end) {
  int index;
  for (int i = 0; i <= end; i++) {
    if (arr[i] == root_value) {
      return i;
    }
  }
  return -1; // value not found
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// helper function to create a tree using recursively from pre and in order
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
TreeNode *build_tree(int pre_order[], int *in_order, int pre_start, int pre_end,
                     int in_start, int in_end) {
  // base case
  if (pre_start > pre_end || in_start > in_end) {
    return NULL;
  }

  // root from pre_order list
  int root_value = pre_order[pre_start];

  // create node
  TreeNode *root = initNode(root_value);

  // find the root_value in in-order and return it's index
  // if the root is not found in in_order then return NULL
  int root_index = find(root_value, in_order, in_start, in_end);
  if (root_index == -1) {
    fprintf(stderr, "Error: Root value %d not found in-order.\n", root_value);
    free(root);
    return NULL;
  }

  // left subtree
  int left_size = root_index - in_start;

  root->left = build_tree(pre_order, in_order, pre_start + 1,
                          pre_start + left_size, in_start, root_index - 1);
  root->right = build_tree(pre_order, in_order, pre_start + left_size + 1,
                           pre_end, root_index + 1, in_end);

  return root;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// create binary search tree using the helper function
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
TreeNode *create_root(int pre_order_list[], int size) {
  if (size <= 0)
    return NULL;

  int *in_order_list = get_in_order(pre_order_list, size);
  if (!in_order_list)
    return NULL;

  TreeNode *root =
      build_tree(pre_order_list, in_order_list, 0, size - 1, 0, size - 1);

  if (!root) {
    fprintf(stderr, "Error occurred during tree build!\n");
    free(root);
    return NULL;
  }

  return root;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// in order tree walk
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
void in_order(TreeNode *root) {
  if (root) {
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// main
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
int main(int argc, char *argv[]) {
  int pre_order[] = {20, 16, 5, 18, 17, 19, 60, 85, 70};
  int n = sizeof(pre_order) / sizeof(pre_order[0]);
  TreeNode *root = create_root(pre_order, n);

  if (root)
    printf("Tree created succesfully!\n");
  else
    printf("Error!\n");

  printf("In-order: ");
  in_order(root);
  printf(" \n");

  free_tree(root);
  return EXIT_SUCCESS;
}
