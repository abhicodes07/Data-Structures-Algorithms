/**
 * Copyright (c) 2026 Abhinav.
 * May be freely redistributed, but copyright notice must be retained.
 * https://github.com/abhicodes07
 */

#include "rbtree.h"
#include "rbtree_data.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  rbTree *rbt;
  rbt = rbTreeCreate(compareFunc, destroyFunc);

  /* initialize a red-black tree*/
  if (rbt == NULL) {
    fprintf(stderr, "initialization of red-black tree failed\n");
    return 1;
  }

  /* insert items */
  char a[] = {'R', 'E', 'D', 'B', 'L', 'A', 'C', 'K', 'T'};
  int size = sizeof(a) / sizeof(a[0]);

  myData *data;
  for (int i = 0; i < size; i++) {
    if ((data = makeData(a[i])) == NULL || rbTreeInsert(rbt, data) == NULL) {
      fprintf(stderr, "Insert %c: Out of memory\n", a[i]);
      free(data);
      break;
    }
    printf("Insert %c", a[i]);
    rbTreePrint(rbt, printCharFunc);
    printf("\n");
  }

  /* delete items */
  rbNode *node;
  myData query;
  query.key = 'B';
  printf("Delete %c", query.key);
  node = rbTreeFind(rbt, &query);
  if (node != NULL)
    rbTreeDelete(rbt, node, 0);
  rbTreePrint(rbt, printCharFunc);

#ifdef RB_MIN
  while ((node = RB_MINIMAL(rbt))) {
    printf("\ndelete ");
    printCharFunc(node->data);
    rbTreeDelete(rbt, node, 0);
    rbTreePrint(rbt, printCharFunc);
  }
#endif

  rbTreeDestroy(rbt);
  return EXIT_SUCCESS;
}
