/**
 * Copyright (c) 2026 Abhinav.
 * May be freely redistributed, but copyright notice must be retained.
 * https://github.com/abhicodes07
 */

#ifndef _RB_TREE_DATA_HEADER
#define _RB_TREE_DATA_HEADER

typedef struct data {
  int key;
} myData;

/* initialize new data */
myData *makeData(int key);

/* compare two data elements*/
int compareFunc(const void *d1, const void *d2);

/* free data */
void destroyFunc(void *d);

/* print data */
void printFunc(void *d);

/* print char data */
void printCharFunc(void *d);

#endif // !_RB_TREE_DATA_HEADER
