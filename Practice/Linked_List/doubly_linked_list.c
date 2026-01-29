#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct DoublyNode *head;
struct DoublyNode *temp;
struct DoublyNode *newnode;
int count = 0;

struct DoublyNode *initDoublyNode(int data) {
  struct DoublyNode *node =
      (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
  if (node == NULL) {
    printf("Memory allocation failed!\n");
    exit(0);
  }
  node->data = data;
  node->next = 0;
  node->prev = 0;
  return node;
}

// create doubly linked list
struct DoublyNode *doubly_linked_list() {
  head = 0;
  printf("Enter the number of  nodes in the list: ");
  scanf("%d", &count);
  int data;

  for (int i = 0; i < count; i++) {
    printf("Enter the data for %d node: ", i);
    scanf("%d", &data);
    newnode = initDoublyNode(data);

    // if list is empty
    if (head == 0) {
      head = newnode;
      temp = head;
    } else {
      newnode->prev = temp;
      temp->next = newnode;
      temp = newnode;
    }
  }
  return head;
}

// insert node at beginning of the list
struct DoublyNode *doubly_insert_at_beg(struct DoublyNode *head, int data) {
  newnode = initDoublyNode(data);
  if (head == 0) {
    head = newnode;
  } else {
    newnode->next = head;
    head = newnode;
  }
  count++;
  return head;
}

// insert node at the end of the list
struct DoublyNode *doubly_insert_at_end(struct DoublyNode *head, int data) {
  newnode = initDoublyNode(data);
  if (head == 0) {
    head = newnode;
  } else {
    temp = head;
    while (temp->next != 0) { // traverse till last node
      temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
  }
  count++;
  return head;
}

// insert at the certain position in the list
struct DoublyNode *doubly_insert_at_pos(struct DoublyNode *head, int data,
                                        int pos) {
  if (pos > count || pos < 1) {
    printf("Position out of bounds!\n");
    exit(0);
  } else {
    newnode = initDoublyNode(data);
    if (pos == 1 && head == 0) { // if there's no node in the list
      head = newnode;
    } else {
      temp = head;
      int i = 1;
      while (i < pos - 1) { // stop at 1 item before position
        temp = temp->next;
        i++;
      }
      newnode->prev = temp;
      newnode->next = temp->next;
      temp->next->prev = newnode;
      temp->next = newnode;
    }
    count++;
  }
  return head;
}

// delete at beginning of the list
struct DoublyNode *doubly_delete_at_beg(struct DoublyNode *head) {
  if (head == 0) {
    printf("List is empty!\n");
  } else {
    temp = head;
    head = head->next;
    printf("%d deleted from the beginning of list\n", temp->data);
    free(temp);
    count--;
  }
  return head;
}

// delete at end of the list
struct DoublyNode *doubly_delete_at_end(struct DoublyNode *head) {
  if (head == 0) {
    printf("List is empty!\n");
  } else {
    temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->prev->next = 0;
    printf("%d deleted from the end of list\n", temp->data);
    free(temp);
    count--;
  }
  return head;
}

// delete at specific position in the list
struct DoublyNode *doubly_delete_at_pos(struct DoublyNode *head) {
  int pos;
  printf("Enter the position: ");

  // check bound
  scanf("%d", &pos);
  if (pos > count || pos < 0) {
    printf("Position out of bounds\n");
    exit(0);
  }

  // if list is empty
  if (head == 0) {
    printf("List is empty!\n");
  } else if (pos == 1) {
    head = doubly_delete_at_beg(head);
  } else if (pos == count) {
    head = doubly_delete_at_end(head);
  } else {
    temp = head;
    int i = 0;
    while (i < pos - 1) { // stop one position back
      temp = temp->next;
      i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("%d deleted from position %d\n", temp->data, pos);
    free(temp);
    count--;
  }
  return head;
}

// display the list
void display_doubly_linked_list(struct DoublyNode *head) {
  printf("Elements in the list: ");
  temp = head;
  while (temp) {
    printf("| %d | -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// main
int main(int argc, char *argv[]) {
  struct DoublyNode *root = doubly_linked_list();
  display_doubly_linked_list(root);

  // root = doubly_insert_at_beg(root, 60);
  // display_doubly_linked_list(root);
  //
  // root = doubly_insert_at_end(root, 70);
  // display_doubly_linked_list(root);

  root = doubly_delete_at_pos(root);
  display_doubly_linked_list(root);
  root = doubly_delete_at_beg(root);
  display_doubly_linked_list(root);
  free(root);
  return EXIT_SUCCESS;
}
