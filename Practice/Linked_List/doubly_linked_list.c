#include "linkedlist.h"

struct DoublyNode *head;
struct DoublyNode *temp;
struct DoublyNode *newnode;
int count;

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

struct DoublyNode *doubly_linked_list() {
  head = 0;
  printf("Enter the number of  nodes in the list: ");
  scanf("%d", &count);
  int data;

  for (int i = 0; i < count; i++) {
    printf("Enter the data for %d node: ", i);
    scanf("%d", &data);
    newnode = initDoublyNode(data);

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

void display_doubly_linked_list(struct DoublyNode *head) {
  printf("Elements in the list: ");
  temp = head;
  while (temp) {
    printf("| %d | -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main(int argc, char *argv[]) {
  struct DoublyNode *root = doubly_linked_list();
  display_doubly_linked_list(root);
  return EXIT_SUCCESS;
}
