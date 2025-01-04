#include <stdio.h>

int main(int argc, char *argv[]) {
  int MAX = 100;
  int arr[MAX];
  int size;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // check bound
  if (size > MAX) {
    printf("Invalid Size! Hit an Upper bound.");
  } else if (size < 0) {
    printf("Lower Bound");
  } else {
    for (int i = 0; i < size; i++) {
      printf("Enter the %d th elemets of an array: ", i);
      scanf("%d", &arr[i]);
    }
  }

  // print elements
  printf("Elements in array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
