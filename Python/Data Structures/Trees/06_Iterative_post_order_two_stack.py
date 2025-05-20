# IMPLEMENTATION OF ITERATIVE POST ORDER TRAVERSAL
class Node:
    def __init__(self, value) -> None:
        self.data = value
        self.left = None
        self.right = None


# implement stack
class Stack:
    def __init__(self) -> None:
        self.stack = []
        self.top = -1

    def push(self, node):
        self.stack.append(node)
        self.top += 1

    def pop(self):
        self.top -= 1
        return self.stack.pop()

    def isEmpty(self):
        return self.top == -1


def iterative_post_order(rootnode):
    if not rootnode:
        return

    s1 = Stack()
    s2 = Stack()
    s1.push(rootnode)

    while not s1.isEmpty():
        node = s1.pop()
        s2.push(node)
        if node.left:
            s1.push(node.left)
        if node.right:
            s1.push(node.right)

    print("Post-Order: ", end="")
    while not s2.isEmpty():
        node = s2.pop()
        print(node.data, end=" ")
    print()


def main():
    root = Node(10)
    root.left = Node(20)
    root.right = Node(30)
    root.left.left = Node(40)
    root.left.right = Node(50)
    root.right.left = Node(60)
    root.right.right = Node(70)

    iterative_post_order(root)


if __name__ == "__main__":
    main()
