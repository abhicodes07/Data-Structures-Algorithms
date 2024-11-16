/*
 * TRAVERSAL OPERATION IN ARRAY
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int arr[100]; // Maximum size
  int size;     // user defined size

  std::cout << "Enter the size of an array: ";
  std::cin >> size;

  // Check OverFlow Bound
  if (size > 100) {
    std::cout << "OverFlow!" << endl;
  } else {
    for (int i = 0; i < size; i++) {
      std::cout << "\nEnter the " << i << " element of array: ";
      std::cin >> arr[i];
    }
  }

  // Display elements
  std::cout << "\nElements in array: ";
  for (int j = 0; j < size; j++) { // traverse through each element
    std::cout << arr[j] << " ";
  }
  return 0;
}
