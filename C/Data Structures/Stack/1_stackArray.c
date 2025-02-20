/* IMPLEMENTATION OF STACK USING ARRAY */

#include <stdio.h>
#include <stdlib.h>

// defines
#define MAX 10

int TOP = -1;
int arr[MAX];

// push operation
void push(int x) {
  if (TOP > MAX) {
    printf("OVERFLOW!\n");
    exit(0);
  }

  TOP++;
  arr[TOP] = x;
  printf("%d pushed into stack.\n", x);
}

// pop operation
void pop() {
  if (TOP < 0) {
    printf("UNDERFLOW!\n");
    exit(0);
  }
  int val = arr[TOP];
  printf("%d popped.\n", val);
  TOP--;
}

// display
void display() {
  int i = 0;
  printf("Elements in stack: [ ");
  while (i <= TOP) {
    printf("%d, ", arr[i]);
    i++;
  }
  printf(" ]\n");
}

// peek
void peek() { printf("Top Element: [ %d ]\n", arr[TOP]); }

// minimum
void minimum() {
  int i = 0;
  int j = 0;
  int min = 0;
  while (i <= TOP && j <= TOP) {
    if (arr[i] < arr[j + 1]) {
      min = arr[i];
      j++;
    } else {
      i++;
    }
  }
  printf("Minimum: %d\n", min);
}

// maximum
void maximum() {
  int i = 0;
  int j = 0;
  int max = 0;

  while (i <= TOP && j <= TOP) {
    if (arr[i] > arr[j + 1]) {
      max = arr[i];
      j++;
    } else {
      i++;
    }
  }
  printf("Maximum: %d\n", max);
}

int main() {
  push(10);
  push(5);
  push(30);
  push(2);
  push(50);
  peek();
  display();
  minimum();
  maximum();
  return 0;
}
