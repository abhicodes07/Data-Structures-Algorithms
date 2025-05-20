# IMPLEMENTATION OF ITERATIVE PREORDER TRAVERSAL

# create tree node
class Node:
    def __init__(self, item) -> None:
        self.left = None
        self.right = None
        self.data = item


# Implement stack
class Stack:
    def __init__(self) -> None:
        self.stack = []
        self.top = -1

    # push tree node into stack
    def push(self, node):
        self.top += 1
        self.stack.append(node)

    # pop tree node from the stack
    def pop(self):
        temp = self.stack.pop()
        self.top -= 1
        return temp

    def is_empty(self):
        return self.top < 0


def iterative_preorder(root):
    """
    Since stack follows FIFO we need to push right node first
    and then left node.
    """
    s = Stack()

    if not root:
        return
    s.push(root)

    print("Pre-order: ", end="")
    while not s.is_empty():
        node = s.pop()
        print(node.data, end=" ")
        if node.right:
            s.push(node.right)
        if node.left:
            s.push(node.left)
    print("")


# main
def main():
    root = Node(10)
    root.left = Node(20)
    root.right = Node(30)
    root.left.left = Node(40)
    root.left.right = Node(50)
    root.right.left = Node(60)
    root.right.right = Node(70)
    iterative_preorder(root)


if __name__ == "__main__":
    main()
