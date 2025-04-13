// Includes
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines
#define MAX 100

// initialize stack and TOP
int stack[MAX];
int TOP = -1;

// push stack
void push(char val) {
  if (TOP < MAX - 1)
    stack[++TOP] = val;
}

// pop stack
int pop() {
  if (TOP >= 0) {
    int val = stack[TOP--];
    return val;
  }
  return 0;
}

// if encountered element is operator
int isOperator(char *token) {
  return strlen(token) == 1 && strchr("+-/*^", token[0]);
}

// evaluate expressions based on operator symbol
int evaluate(int op1, int op2, char operator) {
  switch (operator) {
  case '+':
    return op1 + op2;
  case '*':
    return op1 * op2;
  case '-':
    return op1 - op2;
  case '/':
    return op1 / op2;
  case '^':
    return (int)pow(op1, op2);
  }
  return 0;
}

// evaluate prefix
void evalPrefix(char *exp) {
  /*
   * since we will be tokenizing the expression
   * create a copy of the input expression since strtok affects
   * the original string expression directly since it used pointer to the string
   */
  int len = strlen(exp);
  char exp_copy[100];
  strcpy(exp_copy, exp);

  // store tokens in a array
  char *tokens[MAX];

  // TOKENIZATION: strip white spaces and get each character from the expression
  char *token = strtok(exp_copy, " "); // returns a char * not an array
  int count = 0;

  while (token != NULL) {
    tokens[count++] = token;
    token = strtok(NULL, " ");
  }

  // scan right to left
  for (int i = count - 1; i >= 0; i--) {
    if (isOperator(tokens[i])) {
      int val_1 = pop(); // top value
      int val_2 = pop(); // one next to top
      int res = evaluate(val_1, val_2, tokens[i][0]);
      printf("%d %s %d = %d\n", val_1, tokens[i], val_2, res);
      push(res);
    } else {
      // convert to encountered string operand to integer using method
      push(atoi(tokens[i]));
    }
  }

  printf("Expression: %s\n", exp);
  printf("Result: %d\n", pop());
}

// main
int main() {
  char e1[] = "- + 2 * 3 4 / 16 ^ 2 3";
  evalPrefix(e1);
  return 0;
}
