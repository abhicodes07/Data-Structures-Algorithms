/* BINARY SEARCH IMPLEMENTATION USING
 * RECURSIVE APPROACH
 */
#include <stdio.h>

// use divide and conquer
int recurBinarySearch(int arr[], int val, int low, int high) {
  int mid = -1; // mid of the list

  // if the problem is small that is
  // there is only single element in sequence
  if (low == high) {
    if (arr[low] == val) {
      return low;
    } else {
      return -1;
    }
  } else {
    // calculate mid
    mid = (low + high) / 2;

    if (arr[mid] == val) {
      return mid;
    }

    if (arr[mid] > val) {
      return recurBinarySearch(arr, val, low, mid - 1);
    } else {
      return recurBinarySearch(arr, val, mid + 1, high);
    }
  }
  return -1;
}

// main method
int main(void) {
  int arr[] = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};
  int low = 0;
  int high = sizeof(arr) / sizeof(arr[0]);
  int val = 36;

  int result = recurBinarySearch(arr, val, low, high);

  if (result == -1) {
    printf("Value not found in sequence.\n");
  } else {
    printf("VALUE FOUND\n \tValue: %d\n \tPosition: %d\n \tLocation: %d\n", val,
           result, result + 1);
  }
  return 0;
}
