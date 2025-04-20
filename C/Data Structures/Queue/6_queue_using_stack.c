/* QUEUE IMPLEMENTATION USING STACK */
#include <stdio.h>
#define MAX 5

// create stack
typedef struct {
  int top;
  int arr[MAX];
} Stack;

// create queue
typedef struct {
  Stack s1, s2;
} Queue;

/* IMPLEMENT STACK OPERATIONS */

// push in stack 1
void push(Stack *s, int val) {
  s->top++;
  s->arr[s->top] = val;
}

// pop element from stack1
int pop(Stack *s) { return s->arr[s->top--]; }

/* QUEUE OPERATIONS */
// enqueue element in queue
void enqueue(Queue *q, int val) {
  push(&q->s1, val);
  printf("Enqueued: %d\n", val);
}

// dequeue element from stack
void dequeue(Queue *q) {
  if (q->s1.top == -1) {
    printf("QUEUE IS EMPTY\n");
    return;
  }

  while (q->s1.top != -1) {
    push(&q->s2, pop(&q->s1));
  }
  int value = pop(&q->s2);
  printf("Dequeued: %d\n", value);

  // push all the elements back from stack 2 (temporary) to original stack 1
  while (q->s2.top != -1) {
    push(&q->s1, pop(&q->s2));
  }
}

// display elements
void display(Queue *q) {
  if (q->s1.top < 0) {
    printf("QUEUE IS EMPTY!\n");
    return;
  }

  printf("Elements in queue: [ ");
  for (int i = 0; i <= q->s1.top; i++) {
    printf("%d ", q->s1.arr[i]);
  }
  printf("]\n");
}

// main method
int main(void) {
  // struct memeber declaration order
  Queue q1 = {{-1}, {-1}};

  enqueue(&q1, 10);
  enqueue(&q1, 20);
  enqueue(&q1, 30);
  enqueue(&q1, 40);
  enqueue(&q1, 50);
  display(&q1);

  dequeue(&q1);
  display(&q1);

  return 0;
}
