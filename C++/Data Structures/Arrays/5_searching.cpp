#include <iostream>
#define MAX 1000

using namespace std;

// Search Item
void searchItem(int size, int arr[]) {
  int pos = -1;
  int i;
  int key;

  std::cout << "\n\nEnter the value you want to search: ";
  std::cin >> key;

  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      pos = i;
      break;
    }
  }

  if (pos == -1) {
    std::cout << "Value not found!" << endl;
  } else {
    std::cout << "Value found at position: " << pos << endl;
  }
}

// Main
int main(int argc, char *argv[]) {
  int arr[MAX];
  int size;

  std::cout << "Enter the size of array: ";
  std::cin >> size;

  if (size > MAX || size < 0) {
    std::cout << "Invalid Size!" << endl;
  } else {
    for (int i = 0; i < size; i++) {
      std::cout << "Enter the " << i << "th element: ";
      std::cin >> arr[i];
    }
  }

  // Display Elements
  std::cout << "Elements in array: ";
  for (int i = 0; i < size; i++) {
    std::cout << " " << arr[i];
  }

  searchItem(size, arr);
  return 0;
}
