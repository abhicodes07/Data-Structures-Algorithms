#include <stdio.h>
#include <stdlib.h>

/* Create a node data type */
struct node {
  int data;          // data part
  struct node *next; // next part
};

int main(int argc, char *argv[]) {
  struct node *head;                          // create a head pointer
  struct node *node1, *node2, *node3, *node4; // stores the address of new node
  struct node *temp; // traverse through list and update addresses
  head = 0;          // initially stores null

  /* Assign memmory to nodes */
  node1 = (struct node *)malloc(
      sizeof(struct node)); // allocate the block of memory of 8 bytes
  node2 = (struct node *)malloc(
      sizeof(struct node)); // allocate the block of memory of 8 bytes
  node3 = (struct node *)malloc(
      sizeof(struct node)); // allocate the block of memory of 8 bytes
  node4 = (struct node *)malloc(
      sizeof(struct node)); // allocate the block of memory of 8 bytes

  /* Enter the data */
  printf("Enter the data of node 1: ");
  scanf("%d", &node1->data);
  printf("Enter the data of node 2: ");
  scanf("%d", &node2->data);
  printf("Enter the data of node 3: ");
  scanf("%d", &node3->data);
  printf("Enter the data of node 4: ");
  scanf("%d", &node4->data);

  /* point head to first node and others to next */
  head = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = 0; // last node stores 0

  /* print the nodes */
  printf("%d->%d->%d->%d", node1->data, node2->data, node3->data, node4->data);
  return 0;
}
