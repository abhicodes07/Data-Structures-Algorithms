/* Singly Linked List */
#include "linkedlist.h"

struct SinglyNode *head;
struct SinglyNode *newnode;
struct SinglyNode *temp;
int count = 0;

// initialize a singly newnode
struct SinglyNode *initSinglyNode(int data) {
  struct SinglyNode *node;
  node = (struct SinglyNode *)malloc(sizeof(struct SinglyNode));
  if (node == NULL) {
    printf("Memory allocation failed!\n");
    exit(0);
  }
  node->data = data;
  node->next = 0;
  return node;
}

// create a singly linked list
struct SinglyNode *singly_linked_list() {
  head = 0;
  int data;
  struct SinglyNode *temp;
  printf("Enter the number of nodes in the list: ");
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    printf("Enter the value of %d node: ", i);
    scanf("%d", &data);
    newnode = initSinglyNode(data);
    // if linked list is empty
    if (head == 0) {
      head = newnode;
      temp = head;
    } else {
      temp->next = newnode;
      temp = newnode;
    }
  }
  return head;
}

// insert at beginning of the linked list
struct SinglyNode *insert_at_beg(struct SinglyNode *head, int data) {
  newnode = initSinglyNode(data);
  if (head == 0) {
    head = newnode;
    exit(1);
  } else {
    newnode->next = head;
    head = newnode;
  }
  count++;
  return head;
}

// insert at end of the linked list
struct SinglyNode *insert_at_end(struct SinglyNode *head, int data) {
  // create a newnode
  newnode = initSinglyNode(data);

  if (head == 0) { // if there's no node
    head = newnode;
  } else {
    temp = head;
    // traverse till last
    while (temp->next != 0) {
      temp = temp->next;
    }
    temp->next = newnode;
  }
  count++;
  return head;
}

// insert at position in the linked list
// count: 5, pos: 2, i = 0, pos:2 - 1= 1
struct SinglyNode *insert_at_pos(struct SinglyNode *head, int data, int pos) {
  newnode = initSinglyNode(data);
  if (pos > count) {
    printf("Position out of bounds!\n");
    exit(0);
  } else {
    if (pos == 1) {
      newnode->next = head;
      head = newnode;
    } else {
      int i = 0;
      temp = head;
      while (i < pos - 2) {
        temp = temp->next;
        i++;
      }
      newnode->next = temp->next;
      temp->next = newnode;
    }
  }
  count++;
  return head;
}

// delete from beginning in the list
struct SinglyNode *delete_from_beg(struct SinglyNode *head) {
  if (head == 0) {
    printf("List is empty!\n");
    exit(0);
  } else {
    printf("%d Deleted\n", head->data);
    temp = head;
    head = head->next;
    free(temp);
  }
  count--;
  return head;
}

// delete from the end in the list
struct SinglyNode *delete_from_end(struct SinglyNode *head) {
  if (head == 0) {
    printf("List is empty!\n");
  } else {
    temp = head;
    while (temp->next->next) {
      temp = temp->next;
    }
    printf("%d Deleted from the list\n", temp->next->data);
    temp->next = 0;
    free(temp->next);
    count--;
  }
  return head;
}

// delete from the specific postion
struct SinglyNode *delete_from_pos(struct SinglyNode *head) {
  int pos;
  printf("Enter the position: ");
  scanf("%d", &pos);

  if (pos < 0) {
    printf("Position out of bounds!\n");
  } else {
    if (head == 0) {
      printf("List is empty!\n");
    } else if (pos == 1) {
      temp = head;
      head = head->next;
      printf("%d deleted from the list!\n", temp->data);
      free(temp);
    } else {
      temp = head;
      int i = 0;
      while (i < pos - 2) {
        temp = temp->next;
        i++;
      }
      printf("%d deleted from the list\n", temp->next->data);
      struct SinglyNode *temp2 = temp->next;
      temp->next = temp->next->next;
      free(temp2);
    }
    count--;
  }

  return head;
}

// traversal
void display_singly_linked_list(struct SinglyNode *head) {
  temp = head;
  printf("Elements in the list: ");
  while (temp) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
  printf("Count: %d\n", count);
}

// main
int main(int argc, char *argv[]) {
  struct SinglyNode *root;
  root = singly_linked_list();
  display_singly_linked_list(root);

  // root = insert_at_beg(root, 60);
  // display_singly_linked_list(root);
  // root = insert_at_end(root, 70);
  // display_singly_linked_list(root);
  // root = insert_at_pos(root, 80, 3);
  // display_singly_linked_list(root);

  root = delete_from_pos(root);
  display_singly_linked_list(root);

  free(root);
  return EXIT_SUCCESS;
}
