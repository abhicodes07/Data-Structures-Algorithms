/* IMPLEMENTATION OF LINEAR SEARCH
 * USING ITERATIVE APPROACH
 */

#include <stdio.h>

void linearSearch(int arr[], int val, int size) {
  int pos = -1;

  for (int i = 0; i < size; i++) {
    if (arr[i] == val) {
      pos = i;
    }
  }

  if (pos == -1) {
    printf("Value not found in sequence.\n");
  } else {
    printf("Value found:\n \tPosition: %d\n \tLocation: %d\n", pos, pos + 1);
  }
}

int main() {
  int arr[] = {54, 3, 23, 7, 43, 98, 5, 343, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  linearSearch(arr, 343, n);
  return 0;
}
