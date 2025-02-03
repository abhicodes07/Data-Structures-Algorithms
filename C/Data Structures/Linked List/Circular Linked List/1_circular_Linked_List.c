/*
 * IMPLEMENTATION OF CIRCULAR LINKED LIST WITH ONLY HEAD POINTER
 */

#include <stdio.h>
#include <stdlib.h>

// create a node data type
struct Node {
  int data;          // data part
  struct Node *next; // next part
};

// defines
struct Node *head;
struct Node *temp;
struct Node *newnode;

// display elements
void display(void) {
  temp = head;
  printf("\nElements in the list: [ ");
  /* traverse till temp reaches last node
   * and temp->next becomes equal to head
   * since last node will be pointing to
   * first node.
   */
  while (temp->next != head) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  /* the above loop terminates before pointing
   * last node so explicitly print it along with
   * HEAD
   */
  printf("%d -> %d ]", temp->data, temp->next->data);
  printf("\nHEAD = [ %d ]", temp->next->data);
}

// create circular linked list
void createCLL() {
  head = 0; // initialize head null

  int num;
  printf("Enter the number of nodes in the list: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for %d st node: ", i);
    scanf("%d", &newnode->data);
    newnode->next = 0;

    // if list is empty and only single node is being apppended
    if (head == 0) {
      head = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      temp = newnode;
    }
  }
  // last node in the list poiting towards head i.e., first node
  temp->next = head;
}

// main
int main(int argc, char *argv[]) {
  createCLL();
  display();
  return 0;
}
