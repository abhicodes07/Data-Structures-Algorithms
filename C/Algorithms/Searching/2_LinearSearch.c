/* IMPLEMENTATION OF LINEAR SEARCH
 * USING RECURSIVE METHOD
 */

#include <stdio.h>

int linearSearch(int arr[], int val, int size, int pos) {
  // base case: value not found
  if (pos >= size) {
    return -1;
  }

  // base case: value found
  if (arr[pos] == val) {
    return pos;
  }

  // recursive case
  return linearSearch(arr, val, size, pos + 1);
}

int main(void) {
  int arr[] = {54, 3, 23, 7, 43, 98, 5, 343, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = linearSearch(arr, 343, n, 0);

  if (result != -1) {
    printf("Value found:\n \tPosition: %d\n \tLocation: %d\n", result,
           result + 1);
  } else {
    printf("Value not found in sequence.\n");
  }

  return 0;
}
