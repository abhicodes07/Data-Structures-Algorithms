# Prefix to infix exxpression
def toInfix(expr: str):
    stack = []
    rev = expr[::-1]

    for i in rev:
        # push encountered operand to stack
        if i.isalnum():
            stack.append(i)
        else:
            # RULE: <A> <operator> <B>
            op_1 = stack.pop()
            op_2 = stack.pop()
            stack.append(f"({op_1}{i}{op_2})")

    result = stack.pop()
    print(f"Expression: {expr}")
    print(f"Result: {result}")


if __name__ == "__main__":
    e1 = "*+ab/ef"
    toInfix(e1)
