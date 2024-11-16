/*
 * ARRAY DECLARATION AND INITIALISATION IN CPP
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  // Declare array
  int arr[5];

  // Initialise Array
  arr[0] = 23;
  arr[1] = 4;
  arr[2] = 79;
  arr[3] = 12;
  arr[4] = 2;

  // display elements
  std::cout << "Elements in array: ";
  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
