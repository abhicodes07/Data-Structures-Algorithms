// Implementation of two way merge sort
// or Merge sort usin iterative approach
#include <stdio.h>

// display list fx
void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

// merge the two lists or arrays and produce a single one
void merge(int arr[], int low, int mid, int high) {
  // divide
  int size1 = mid - low + 1;
  int size2 = high - mid;

  // temp arrays to store right and left subarrays
  int left[size1], right[size2];

  for (int i = 0; i < size1; i++) {
    left[i] = arr[low + i];
  }

  for (int j = 0; j < size2; j++) {
    right[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = low;
  while (i < size1 && j < size2) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }

  // if there are remaining elements in either of the list
  // insert them all to result
  while (i < size1) {
    arr[k++] = left[i++];
  }

  while (j < size2) {
    arr[k++] = right[j++];
  }
}

void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    // calculate mid using much safer way for overflow conditions
    int mid = low + (high - low) / 2;
    printf("Mid: %d\n", mid);

    // NOTE: keep dividing/conquering the list until there's only single element
    // left then start merging.
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // combine
    merge(arr, low, mid, high);
  }
}

int main(void) {
  int list[] = {9, 3, 7, 5, 6, 4, 8, 2};
  int low = 0;
  int high = sizeof(list) / sizeof(list[0]);

  printf("List: [ ");
  display(list, high);

  mergeSort(list, low, high - 1);
  printf("Sorted: [ ");
  display(list, high);

  return 0;
}
