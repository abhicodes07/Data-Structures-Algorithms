/*
 * ARRAY TRAVERSAL
 */

#include "stdio.h"

int main(int argc, char *argv[]) {
  int array[100]; // Maximum size of input
  int size;       // User defined size

  printf("Enter the size of an array: ");
  scanf("%d", &size);

  // Check overflow bound
  if (size > 100) {
    printf("Overflow!\n");
  } else {
    // Insert elements
    for (int i = 0; i < size; i++) {
      printf("Enter the %d th element of an array: ", i);
      scanf("%d", &array[i]);
    }
    printf("\n");
  }

  // Display array elements
  printf("Elements in array: ");
  for (int j = 0; j < size; j++) {
    printf("%d ", array[j]);
  }
  return 0;
}
