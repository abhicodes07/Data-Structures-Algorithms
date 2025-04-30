/* IMPLEMENTATION OF SELECTION SORT ALGORITHM */
#include <stdio.h>

int searchMinimum(int arr[], int start, int end) {
  // find the minimum element using linear search approach
  int min = start;
  for (int i = start + 1; i < end; i++) {
    if (arr[i] < arr[min]) {
      min = i;
    }
  }
  return min;
}

/*Selection sort algorithm*/
void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = searchMinimum(arr, i, size);
    if (min != i) {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf(" %d", arr[i]);
  }
  printf(" ]\n");
}

// main function
int main(void) {
  int arr[] = {5, 3, 10, 7, 1, 8, 4, 2, 9, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Unsorted list: [");
  display(arr, n);

  selectionSort(arr, n);

  printf("Sorted list: [");
  display(arr, n);
  return 0;
}
