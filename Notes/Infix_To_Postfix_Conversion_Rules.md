# Rules For Infix To Postfix Conversion Using Stack

### 🌿 Precedence and Associativity of operators

Infix Expression Syntax: `<operand><operation><operand>`

| Precedence | Operator   | Associativity |
| ---------- | ---------- | ------------- |
| 1          | (), {}, [] |               |
| 2          | ^          | Right to Left |
| 3          | \*, /      | Left to Right |
| 4          | +, -       | Left to Right |

### 🌿 Rules

- Print operands as they arrive.
- If stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
- If incoming symbol is '(', push it onto stack.
- If incoming symbol is ')', pop the stack & Print the operators until left parenthesis is found.
- If incoming symbol has higher Precedence than than the top of the stack, push it on the stack.
- If incoming symbol has lower Precedence than the to of the stack , pop & print the top, then test the incoming operator against the new top of the stack.
- If incoming operator has equal Precedence with the top of stack, use Associativity rule.
- At the end of the Expression, pop & print all the operator in stack.

#### Associativity rules

1. **_Associativity (Left to Right):_** Pop and print the top of the stack & then push the incoming operator.
1. **_Associativity (Right to Left):_** Push the incoming operator into the stack.
