# Infix to Postfix Conversion

# Operator precedence
def precedence(char: str):
    if char == "+" or char == "-":
        return 1  # lowest precedency
    elif char == "*" or char == "/":
        return 2  # mid precedency
    elif char == "^":
        return 3  # highest precedency
    else:
        return -1


# conversion
def infixToPostfix(equation: str):
    eq = []  # stack
    result = ""  # resulting conversion

    try:
        for i in equation:
            # if the character is operand, append it to result
            if i.isalnum():
                result += i

            # if incoming symbol is '(' push it onto stack
            elif i == "(":
                eq.append(i)

            # if incoming symbol is ')', pop the stack & append the popped symbol to result
            # until left paranthesis '(' is found
            elif i == ")":
                while eq[-1] != "(":
                    result += eq.pop()
                eq.pop()

            # check precedence
            else:
                while eq and (
                    precedence(i) < precedence(eq[-1])
                    or (precedence(i) == precedence(eq[-1]) and i != "^")
                ):
                    result += eq.pop()
                eq.append(i)

        # pop the remaining symbols from stack and append them to result
        while eq:
            result += eq.pop()

        print("Equation: ", equation)
        print("Infix to postfix conversion: ", result)
        print()

    except Exception as e:
        print("An Exception Occurred: ", e.__repr__())


if __name__ == "__main__":
    equation1 = "A-(B/C)*D+E"
    equation2 = "K+L-M*N+(O^P)*W/U/V*T+Q^J^A"
    equation3 = "A-B+(M^N)*(O+P)-Q/R^S*T+Z"
    infixToPostfix(equation1)
    infixToPostfix(equation2)
    infixToPostfix(equation3)
