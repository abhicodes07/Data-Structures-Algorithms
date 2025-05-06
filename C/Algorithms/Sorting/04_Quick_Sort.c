#include <stdio.h>

// display the list
void display(int arr[], int size) {
  printf("List: [");
  for (int i = 0; i < size; i++) {
    printf(" %d ", arr[i]);
  }
  printf("]\n");
}

/* Partition the array */
int partition(int arr[], int low, int high) {
  int pivot = arr[low]; // first element as the pivot
  int i = low;          // will search for the elements less than pivot
  int j = high - 1;     // will serach for the elements greater than pivot

  // traverse through list
  while (i < j) {
    // search smaller elements than pivot
    while (i <= high && arr[i] <= pivot) {
      i++;
    }

    // search larger elements than pivot
    while (j >= low && arr[j] > pivot) {
      j--;
    }

    // swap if the larger element on left with smaller element on right
    if (i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp2 = arr[low];
  arr[low] = arr[j];
  arr[j] = temp2;

  return j;
}

/* Recursively perform quick sort on the array */
void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int j = partition(arr, low, high);
    quick_sort(arr, low, j);
    quick_sort(arr, j + 1, high);
  }
}

int main() {
  int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5, 18};
  int low = 0;
  int high = sizeof(arr) / sizeof(arr[0]);

  // partition(arr, low, high);
  display(arr, high);

  // partition(arr, low, high);
  quick_sort(arr, low, high);
  display(arr, high);
  return 0;
}
