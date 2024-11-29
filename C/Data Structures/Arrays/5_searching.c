/*
 * SEARCHING OPERATION ON ARRAY
 */
#include <stdio.h>
#define MAX 100

// Search
void searchKey(int size, int arr[]) {
  int i;
  int key;
  int pos = -1;
  printf("\n\nEnter the value you want to search: ");
  scanf("%d", &key);

  for (i = 0; i < size; i++) {
    if (arr[i] == key) {
      pos = i;
      break;
    }
  }

  if (pos == -1) {
    printf("\nValue not found!");
  } else {
    printf("\nValue found at position: %d", pos);
  }
}

// Main
int main(int argc, char *argv[]) {
  int arr[MAX]; // Define array
  int size, i;

  // Evaluate size
  printf("Enter the size of an array: ");
  scanf("%d", &size);

  // Insert Elements
  if (size > MAX || size < 0) {
    printf("Invalid Size!\n");
  } else {
    for (i = 0; i < size; i++) {
      printf("Enter the %d element: ", i);
      scanf("%d", &arr[i]);
    }
  }

  // Display Elements
  printf("Elements in array: ");
  for (i = 0; i < size; i++) {
    printf(" %d", arr[i]);
  }

  searchKey(size, arr);
  return 0;
}
