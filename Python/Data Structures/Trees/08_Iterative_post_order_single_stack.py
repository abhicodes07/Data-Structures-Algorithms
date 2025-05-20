# IMPLEMENTATION OF ITERATIVE TREE ORDER TRAVERSAL

# Create Treenode
class Node:
    def __init__(self, value) -> None:
        self.data = value
        self.left = None
        self.right = None


def iterative_post_order(rootnode):
    """Iterative post order traversal using single stack"""
    if not rootnode:
        return

    stack = []
    last_visited = None
    current = rootnode

    print("Post-Order: ", end="")
    while stack or current:
        if current:
            stack.append(current)
            # traverse left most nodes
            current = current.left
        else:
            top = stack[-1]
            if top.right and last_visited != top.right:
                current = top.right
            else:
                print(top.data, end=" ")
                last_visited = stack.pop()
    print()


def main():
    root = Node(1)
    root.left = Node(2)
    root.left.left = Node(3)
    root.left.left.right = Node(4)
    root.left.left.right.right = Node(5)
    root.left.left.right.right.right = Node(6)
    root.right = Node(7)
    root.right.left = Node(8)

    iterative_post_order(root)


if __name__ == "__main__":
    main()
