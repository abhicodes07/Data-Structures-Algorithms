# IMPLEMENTATION OF ITERATIVE INORDER TRAVERSAL

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
        self.top -= 1
        return self.stack.pop()

    def is_empty(self):
        return self.top < 0


# iterative inorder traversal
def iterative_inorder(root):
    s = Stack()
    node = root

    if not root:
        return

    print("In order: ", end="")
    while True:
        if node:
            s.push(node)
            node = node.left
        else:
            if s.is_empty():
                break
            node = s.pop()
            print(node.data, end=" ")
            node = node.right

    print(" ")


# main
def main():
    root = Node(10)
    root.left = Node(20)
    root.right = Node(30)
    root.left.left = Node(40)
    root.left.right = Node(50)
    root.right.left = Node(60)
    root.right.right = Node(70)

    iterative_inorder(root)


if __name__ == "__main__":
    main()
