def prec(char):
    if char in ["+", "-"]:
        return 1
    elif char in ["*", "/"]:
        return 2
    elif char == "^":
        return 3

    return -1


def toPrefix(infix):
    rev = infix[::-1]
    result = ""
    stack = []

    try:
        for i in rev:
            if i.isalnum():
                result += i
            elif i == ")":
                stack.append(i)
            elif i == "(":
                while stack and stack[-1] != ")":
                    result += stack.pop()

                if stack:
                    stack.pop()
            else:
                while stack and (prec(i) < prec(stack[-1])):
                    result += stack.pop()
                stack.append(i)

        while stack:
            result += stack.pop()

    except Exception as e:
        print("Error", e.__repr__())

    prefix = result[::-1]
    # print(f"Infix Expression: {exp}")
    # print(f"Prefix: {prefix}")
    print(f"Infix: {infix}")
    print(f"Reversed: {rev}")
    print(f"Stack: {stack}")
    print(f"Result: {result}")
    print(f"Prefix: {prefix}")
    print()


if __name__ == "__main__":
    expr_1 = "K+L-M*N+(O^P)*W/U/V*T+Q"
    expr_2 = "A+(B*C)"

    toPrefix(expr_1)
    toPrefix(expr_2)
