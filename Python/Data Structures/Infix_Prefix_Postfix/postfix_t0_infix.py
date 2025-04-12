# Postfix to infix exxpression
def toInfix(expr: str):
    stack = []

    for i in expr:
        # push encountered operand to stack
        if i.isalnum():
            stack.append(i)
        else:
            # RULE: <B> <operator> <A>
            op_1 = stack.pop()
            op_2 = stack.pop()
            stack.append(f"({op_2}{i}{op_1})")

    result = stack.pop()
    print(f"Expression: {expr}")
    print(f"Result: {result}")


if __name__ == "__main__":
    e1 = "ab+ef/*"
    toInfix(e1)
