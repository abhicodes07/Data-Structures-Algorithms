#include <stdio.h>

/*** DISPLAY ***/
void displayValues(int arr[], int size) {
  // Display elements in array
  int i;
  printf("\nElements in array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/*** FIND ***/
int findElement(int arr[], int val);

/*** INSERTION ***/
void insertAt(int arr[], int val, int pos, int size) {
  // Insert Element at specific position
  if (pos < 0 || pos > size) {
    printf("Invalid position!\n\n");
  } else {
    for (int i = size - 1; i < pos - 1; i--) {
      arr[i + 1] = arr[i];
    }
    arr[pos - 1] = val;
    size++;
    displayValues(arr, size);
  }
}

void insert(int arr[], int size, int val);
void insertBegin(int arr[], int val, int size);
void insertEnd(int arr[], int val, int size);

/** DELETION **/
int deleteBegin(int arr[], int val, int size);
void deleteEnd(int arr[], int val, int size);
int deleteAt(int arr[], int pos, int size);

int main(int argc, char *argv[]) {
  // create array
  int arr[100];
  int size, i;

  printf("Enter the size of array: ");
  scanf("%d", &size);

  // check bound
  if (size > 100 || size < 0) {
    printf("Enter the valid size!\n");
  } else {
    for (i = 0; i < size; i++) {
      printf("Enter the %d value of array: ", i);
      scanf("%d", &arr[i]);
    }
  }

  // display values
  displayValues(arr, size);

  return 0;
}
