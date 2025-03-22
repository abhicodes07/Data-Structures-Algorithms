/* Refer to notes for rules of conversion */

// Includes
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// precedence of operators
int precedence(char c) {
  if (c == '^') {
    return 3; // highest precedency
  } else if (c == '*' || c == '/') {
    return 2; // medium precedency
  } else if (c == '+' || c == '-') {
    return 1; // lowest precedency
  }
  return -1;
}

// conversion
void infix_to_postfix(char *exp) {
  int len = strlen(exp); // length of the given expression
  char result[len + 1];  // array for storing result
  char stack[len];       // stack of length of expression
  int TOP = -1;          // top flag for stack
  int j = 0, i = 0;

  for (i = 0; i < len; i++) {
    char c = exp[i]; // single character from the expression

    // if the incoming character is alpha numeric, append it result
    if (isalnum(c)) {
      result[j++] = c; // store c in result and then increment 'j'
    } else if (c == '(') {
      stack[++TOP] = c; // increment TOP from -1 and then store 'c'
    } else if (c == ')') {
      while (TOP != -1 && stack[TOP] != '(') {
        result[j++] = stack[TOP--];
      }
      // if left paranthesis is found then remove it from the stack
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

  // at the end, pop the stack until empty and append it to result
  while (TOP != -1) {
    result[j++] = stack[TOP--];
  }

  // print result
  result[j] = '\0';
  printf("Expression: %s\n", exp);
  printf("Infix to Postfix: %s\n", result);
}

int main() {
  // given expression
  char e1[] = "A-B/C*D+E";
  char e2[] = "K+L-M*N+(O^P)*W/U/V*T+Q^J^A";
  infix_to_postfix(e1);
  infix_to_postfix(e2);
  return 0;
}
