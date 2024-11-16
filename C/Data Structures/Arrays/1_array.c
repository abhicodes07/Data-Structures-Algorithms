/*
 * ARRAY DECLAARTION AND DEFINITION
 */

#include "stdio.h"

int main(int argc, char *argv[]) {
  // initilize array
  int arr[5];

  // Initial value stored in array
  printf("value = %d\n", arr[0]);

  // specify values
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  // Display values
  printf("Elements in array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
