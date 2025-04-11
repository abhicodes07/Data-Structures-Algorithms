class Expression:
    def __init__(self, expr: str) -> None:
        self.expr = expr.split(" ")

    def evaluate(self, symbol: str, value1: int, value2: int):
        """Evaluates Expression based on the encountered symbol"""
        match symbol:
            case "^":
                # raise to the power
                return value1**value2
            case "*":
                return value1 * value2
            case "/":
                return value1 / value2
            case "+":
                return value1 + value2
            case "-":
                return value1 - value2

    def evalPrefix(self):
        stack = []
        rev = self.expr[::-1]  # reverse the list

        for i in rev:
            if i.isalnum():
                # typecast operand to integer
                stack.append(int(i))
            else:
                val_1 = stack.pop()  # top
                val_2 = stack.pop()  # one next to top
                stack.append(self.evaluate(i, val_1, val_2))  # push result to stack

        # pop the result from stack
        result = stack.pop()
        print(f"Expression: {' '.join(self.expr)}")
        print(f"Result: {result}")

    def evalPostfix(self):
        pass


if __name__ == "__main__":
    e1 = Expression("- + 2 * 3 4 / 16 ^ 2 3")
    e1.evalPrefix()
