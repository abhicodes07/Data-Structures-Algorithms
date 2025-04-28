/* IMPLEMENTATION OF INSERTION SORT ALGORITHM */
#include <stdio.h>

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void display(int arr[], int n) {
  printf("Sorted array: [ ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

int main(void) {
  int arr[] = {5, 3, 10, 7, 1, 8, 4, 2, 9, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, n);
  display(arr, n);
  return 0;
}
