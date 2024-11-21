/*
 * DELETION OPERATION
 */

#include <iostream>
using namespace std;

// insert values
void insert(int arr[], int size) {
  // check bound
  if (size > 100 || size < 0) {
    std::cout << "Invalid size!" << endl;
  } else {
    for (int i = 0; i < size; i++) {
      std::cout << "Enter the " << i << "th value of array: ";
      std::cin >> arr[i];
    }
  }
}

// Display elements
void displayValues(int arr[], int size) {
  // Display elements in array
  int i;
  std::cout << "Elements in array: ";
  for (i = 0; i < size; i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

// Delete Elements
void deleteAt(int arr[], int pos, int size) {
  // check bound
  int item = arr[pos - 1];
  if (pos < 0 || pos > size) {
    std::cout << "Invalid postion!" << endl;
  } else {
    for (int i = pos - 1; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }
    size--;
  }
  std::cout << "Deleted element: " << item << endl;
  displayValues(arr, size);
}

int main(int argc, char *argv[]) {
  int arr[50], size, pos;

  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  // insert values
  insert(arr, size);

  // display values
  displayValues(arr, size);

  // deletee element
  std::cout << "\nEnter the position of the element you want to delete: ";
  std::cin >> pos;
  deleteAt(arr, pos, size);
  return 0;
}
