/* Linked Lists */
#include <stdio.h>
#include <stdlib.h>

// Node for singly linked list
struct SinglyNode {
  int data;                // data
  struct SinglyNode *next; // next
};

// Node for Doubly linked list
struct DoublyNode {
  int data;                // data
  struct DoublyNode *next; // next pointer
  struct DoublyNode *prev; // prev pointer
};

/* Singly Linked list and it's operations */
struct SinglyNode *initSinglyNode(int data);
struct SinglyNode *singly_linked_list();
struct SinglyNode *insert_at_beg(struct SinglyNode *head, int data);
struct SinglyNode *insert_at_end(struct SinglyNode *head, int data);
struct SinglyNode *insert_at_pos(struct SinglyNode *head, int data, int pos);
struct SinglyNode *delete_from_beg(struct SinglyNode *head);
struct SinglyNode *delete_from_end(struct SinglyNode *head);
struct SinglyNode *delete_from_pos(struct SinglyNode *head);

/* Doubly linked list and it's operations */
struct DoublyNode *initDoublyNode(int data);
struct DoublyNode *doubly_linked_list();
struct DoublyNode *doubly_insert_at_beg(struct DoublyNode *head, int data);
struct DoublyNode *doubly_insert_at_end(struct DoublyNode *head, int data);
struct DoublyNode *doubly_insert_at_pos(struct DoublyNode *head, int data,
                                        int pos);
struct DoublyNode *doubly_delete_at_beg(struct DoublyNode *head);
struct DoublyNode *doubly_delete_at_end(struct DoublyNode *head);
struct DoublyNode *doubly_delete_at_pos(struct DoublyNode *head);

/* Display linked list*/
void display_singly_linked_list(struct SinglyNode *head);
void display_doubly_linked_list(struct DoublyNode *head);
