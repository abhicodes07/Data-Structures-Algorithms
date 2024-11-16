/*
 * INSERTION OPERATION AT SPECIFIED POSITION
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int arr[100];    // Maximum size of array
  int size;        // User defined size of array
  int pos, val, i; // Position and index of the element to add

  printf("Enter the size of an array: ");
  scanf("%d", &size);

  // Check Overflow and Underflow
  if (size > 100) {
    printf("Overflow!\n");
  } else if (size < 0) {
    printf("Underflow!");
  } else {
    for (i = 0; i < size; i++) {
      printf("Enter the %d element of array: ", i);
      scanf("%d", &arr[i]);
    }
    printf("\n");
  }

  // Display Elements
  printf("Elements in array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  // Insert Element at specific position
  printf("\nEnter the value: ");
  scanf("%d", &val);
  printf("Enter the position: ");
  scanf("%d", &pos);

  // Check Overflow and Underflow again
  if (pos > size) {
    printf("Overflow!");
  } else if (pos < 0) {
    printf("Underflow!");
  } else {
    /*
     * Upon adding an element at certian postion will overwrite
     * the existing value holding this position.
     * To avoid this, we need to shift the postion of the Elements
     * to the right starting from the postion till size of array
     * where user wants to insert the element.
     */
    for (int j = size - 1; j >= pos - 1; j--) {
      arr[j + 1] = arr[j];
    }
    arr[pos - 1] = val;
    size++;
  }

  // Display Elements
  printf("\nElements in array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
