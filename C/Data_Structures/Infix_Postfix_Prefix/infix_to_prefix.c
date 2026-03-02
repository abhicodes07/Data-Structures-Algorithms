#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// precedence of operators
int precedence(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  return -1;
}

// convert to postfix expresssion
char *infixToPostfix(char *exp) {
  int len = strlen(exp);
  char *stack = (char *)malloc(len);
  char *result = (char *)malloc(len + 1);
  int TOP = -1;
  int i = 0, j = 0;

  for (i = 0; i < len; i++) {
    char c = exp[i];

    if (isalnum(c)) {
      result[j++] = c;
    } else if (c == '(') {
      stack[++TOP] = c;
    } else if (c == ')') {
      while (TOP != -1 && stack[TOP] != '(') {
        result[j++] = stack[TOP--];
      }
      TOP--;
    } else {
      while (TOP != -1 &&
             (precedence(c) < precedence(stack[TOP]) ||
              (precedence(c) == precedence(stack[TOP]) && c != '^'))) {
        result[j++] = stack[TOP--];
      }
      stack[++TOP] = c;
    }
  }

  while (TOP != -1) {
    result[j++] = stack[TOP--];
  }

  result[j] = '\0';
  // printf("Infix Expression: %s\n", exp);
  // printf("Postfix Expression: %s\n", result);

  free(stack);
  return result;
}

// convert infix to prefix expression
void infixToPrefix(char *exp) {
  int len = strlen(exp);
  char *reversed = (char *)malloc(len + 1);

  // reverse the infix
  for (int i = 0; i < len; i++) {
    reversed[i] = exp[len - 1 - i];
  }

  // convert the expression to postfix
  char *postfix = infixToPostfix(reversed);

  // reverse the resulting postfix to prefix
  char *prefix = (char *)malloc(len);
  for (int i = 0; i < len; i++) {
    prefix[i] = postfix[len - 1 - i];
  }

  printf("Infix: %s\n", exp);
  printf("Reversed: %s\n", reversed);
  printf("Postfix: %s\n", postfix);
  printf("Prefix: %s\n", prefix);

  // free memory
  free(prefix);
  free(postfix);
}

int main() {
  char e1[] = "A-B/C*D+E";
  char e2[] = "K+L-M*N+(O^P)*W/U/V*T+Q^J^A";

  infixToPrefix(e1);
  infixToPrefix(e2);
  return 0;
}
