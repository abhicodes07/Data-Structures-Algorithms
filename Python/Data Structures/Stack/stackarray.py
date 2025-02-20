# IMPLEMENTATION OF STACK USING ARRAY


class Stack:
    def __init__(self) -> None:
        self.top = -1
        self.stack = []

    def push(self, item: int):
        self.stack.append(item)
        self.top += 1

    def pop(self, item: int):
        self.stack.pop(item)
        self.top -= 1

    def peek(self):
        print(f"Top element: {self.stack[self.top]}")

    def display(self):
        print(f"Stack: {self.stack}")

    def maximum(self):
        max = self.stack[0]
        for i in range(self.top):
            if self.stack[i + 1] > max:
                max = self.stack[i + 1]

        print("Maximum:", max)

    def minimum(self):
        min = self.stack[0]
        for i in range(self.top):
            if self.stack[i + 1] < min:
                min = self.stack[i + 1]

        print("Minimum:", min)


def main():
    stack = Stack()
    stack.push(10)
    stack.push(100)
    stack.push(5)
    stack.push(1)
    stack.display()
    stack.maximum()
    stack.minimum()


if __name__ == "__main__":
    main()
