#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// initialize treenode
TreeNode *initNode(int data) {
  TreeNode *newnode = malloc(sizeof(data));
  if (!newnode) {
    perror("Memory allocation failed!");
    exit(1);
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// get minimum element for sorting
int minimum(int arr[], int start, int end) {
  int min = start;
  for (int i = start; i < end; i++) {
    if (arr[i] < arr[min])
      min = i;
  }
  return min;
}

// sort the array
void sort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int min = minimum(arr, i, size);
    if (min != i) {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

// get in order (sorted) list from pre_order
int *get_in_order(int pre_order[], int size) {
  // allocate memory to in-order list
  int *in_order = malloc(size * sizeof(*in_order));
  if (!in_order) {
    printf("Memory allocation failed!\n");
    return NULL;
  }

  // copy elements of pre-order to in-order
  for (int i = 0; i < size; i++) {
    in_order[i] = pre_order[i];
  }

  // sort the in-order list
  sort(in_order, size);

  return in_order;
}

// free tree nodes
void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    free(root);
    freeTree(root->right);
  }
}

// find root in order
int find(int value, int arr[], int size) {
  int index;
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      index = i;
    }
  }
  return index;
}

// create tree from given pre-order list
void createTree(int pre_order[], int size) {
  // get in-order using pre-order list (sorted)
  int *in_order = get_in_order(in_order, size);
}

// main
int main(int argc, char *argv[]) {
  int pre_order[] = {20, 16, 5, 18, 17, 19, 60, 85, 70};
  int n = sizeof(pre_order) / sizeof(pre_order[0]);
  createTree(pre_order, n);
  return EXIT_SUCCESS;
}
