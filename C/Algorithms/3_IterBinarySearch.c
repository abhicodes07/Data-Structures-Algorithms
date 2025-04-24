/* IMPLEMENTATION OF BINARY SEARCH USING
 * ITERATIVE APPROACH
 */
#include <stdio.h>

void binarySearch(int arr[], int val, int size) {
  int low = 0;     // start of the list
  int high = size; // end of the list
  int mid = -1;    // mid of the list
  int pos = -1;    // position of the found element

  while (low <= high) {
    // calculate mid value
    mid = (low + high) / 2;

    if (arr[mid] == val) {
      pos = mid;
      break;
    }

    // serach it in left side of the list
    if (arr[mid] > val) {
      high = mid - 1;
    }
    // search in right side of the list
    else {
      low = mid + 1;
    }
  }

  if (pos == -1) {
    printf("Value not found in sequence.\n");
  } else {
    printf("VALUE FOUND\n \tValue: %d\n \tPosition: %d\n \tLocation: %d\n", val,
           pos, pos + 1);
  }
}

// main method
int main(void) {
  int arr[] = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};
  int n = sizeof(arr) / sizeof(arr[0]);
  binarySearch(arr, 12, n);
  return 0;
}
