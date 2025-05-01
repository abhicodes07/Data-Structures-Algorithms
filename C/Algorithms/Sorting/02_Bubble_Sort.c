/*
 * Implementation of Bubble sort algorithm
 */
#include <stdio.h>

// compare adjancent elements, swap if needed. Repeat passes.
// Like bubbles rising to the top - largest elements bubble up.
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j + 1] < arr[j]) {
        // swap both values
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// display list
void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

int main(void) {
  int arr[] = {5, 3, 10, 7, 1, 8, 4, 2, 9, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted list: [ ");
  display(arr, n);

  printf("Sorted list:   [ ");
  bubbleSort(arr, n);
  display(arr, n);

  return 0;
}
