# Infix to Postfix Conversion
def precedence(char: str):
    if char == "+" or char == "-":
        return 1  # lowest precedency
    elif char == "*" or char == "/":
        return 2  # mid precedency
    elif char == "^":
        return 3  # highest precedency
    else:
        return -1


def infixToPostfix(equation: str):
    TOP = -1
    eq = []  # stack
    result = ""  # resulting conversion

    try:
        for i in equation:
            if i.isalnum():
                result += i

            elif i == "(":
                eq.append(i)
                TOP += 1

            elif i == ")":
                while eq[TOP] != "(":
                    result += eq.pop()
                    TOP -= 1
                eq.pop()
            else:
                while eq and (
                    precedence(i) < precedence(eq[TOP])
                    or precedence(i) == precedence(eq[TOP])
                ):
                    result += eq.pop()
                    TOP -= 1
                eq.append(i)

    except Exception as e:
        print("An Exception Occurred: ", e.__repr__())

    print(result)
    print(eq)


equation = "A-B/C*D+E"
infixToPostfix(equation)
