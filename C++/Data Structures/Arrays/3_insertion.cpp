/*
 * INSERTION OPERATION AT SPECIFIED POSITION
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int arr[100];    // Maximum size of array
  int size;        // User defined size of array
  int pos, val, i; // Position and index of the element to add

  std::cout << "Enter the size of an array: ";
  std::cin >> size;

  // Check overflow and underflow bound
  if (size > 100) {
    std::cout << "Overflow!" << endl;
  } else if (size < 0) {
    std::cout << "Undeflow!" << endl;
  } else {
    // get items of array at runtime
    std::cout << "\n";
    for (i = 0; i < size; i++) {
      std::cout << "Enter the " << i << " value of array: ";
      std::cin >> arr[i];
    }
  }

  // Display elements
  std::cout << endl << "\nElements in array: ";
  for (i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }

  // Insert element at certain position
  std::cout << "\nEnter the value you want to insert: ";
  std::cin >> val;
  std::cout << "Enter the position: ";
  std::cin >> pos;

  // Check Overflow and Underflow
  if (pos > size + 1) { // User can still add value at the end
    std::cout << "Overflow!" << endl;
  } else if (pos < 0) {
    std::cout << "Underflow!" << endl;
  } else {
    // Shift elements to right by one index
    for (i = size - 1; i >= pos - 1; i--) {
      arr[i + 1] = arr[i];
    }
    arr[pos - 1] = val; // Insert value
    size++;             // Increment size
  }

  // Display elements
  std::cout << endl << "\nElements in array: ";
  for (i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
