/**
 * Copyright (c) 2026 Abhinav.
 * May be freely redistributed, but copyright notice must be retained.
 * https://github.com/abhicodes07
 */

#include "rbtree_data.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* allocate and initialize data */
myData *makeData(int key) {
  myData *p;
  p = (myData *)malloc(sizeof(myData));
  if (p != NULL)
    p->key = key;
  return p;
}

/* compare two given data */
int compareFunc(const void *d1, const void *d2) {
  myData *p1, *p2;
  assert(d1 != NULL);
  assert(d2 != NULL);

  p1 = (myData *)d1;
  p2 = (myData *)d2;

  if (p1->key == p2->key)
    return 0;
  else if (p1->key > p2->key)
    return 1;
  else
    return -1;
}

/* destroy data */
void destroyFunc(void *d) {
  myData *p;
  assert(d != NULL);
  p = (myData *)d;
  free(p);
}

/* print data */
void printFunc(void *d) {
  myData *p;
  assert(d != NULL);
  p = (myData *)d;
  printf("%d", p->key);
}

/* print char data if any */
void printCharFunc(void *d) {
  myData *p;
  assert(d != NULL);
  p = (myData *)d;
  // convert integer to printable ASCII character
  printf("%c", p->key & 127);
}
