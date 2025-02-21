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
  int min = arr[0];
  int i = 1;
  while (i <= TOP) {
    if (arr[i] < min) {
      min = arr[i];
    }
    i++;
  }
  printf("Minimum: %d\n", min);
}

// maximum
void maximum() {
  int max = arr[0];
  int i = 1;

  while (i <= TOP) {
    if (arr[i] > max) {
      max = arr[i];
    }
    i++;
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
