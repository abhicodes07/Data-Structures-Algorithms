# implementation of stack using linked list

# create a node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


# create stack
class Stack:
    def __init__(self) -> None:
        self.TOP = None

    def push(self, item):
        """first node from down stores null and index start from top"""
        newnode = Node(item)
        newnode.next = self.TOP
        self.TOP = newnode
        print(f"{newnode.data} pushed into stack.")

    def pop(self):
        print(f"{self.TOP.data} popped.")
        self.TOP = self.TOP.next

    def display(self):
        temp = self.TOP
        print("Elements in stack: [ ", end="")
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print(" ]")

    def peek(self):
        print(f"Top most element in stack: {self.TOP.data}")

    def minimum(self):
        min = self.TOP.data
        temp = self.TOP.next

        while temp:
            if temp.data < min:
                min = temp.data
            temp = temp.next
        print("Minimum: ", min)

    def maximum(self):
        max = self.TOP.data
        temp = self.TOP.next

        while temp:
            if temp.data > max:
                max = temp.data
            temp = temp.next
        print("Maximum: ", max)


def main():
    stack = Stack()
    stack.push(10)
    stack.push(21)
    stack.push(5)
    stack.push(40)
    stack.push(25)
    stack.display()
    stack.minimum()
    stack.maximum()
    stack.peek()


if __name__ == "__main__":
    main()
