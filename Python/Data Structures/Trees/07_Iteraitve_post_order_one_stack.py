# IMPLEMENTATION OF ITERATIVE POST ORDER TRAVERSAL
class Node:
    def __init__(self, value) -> None:
        self.data = value
        self.left = None
        self.right = None


def iterative_post_order(rootnode):
    """
    Iterative post order traversal using single stack and reversing
    the answer
    """
    if not rootnode:
        return

    s1 = []
    post_order = []
    s1.append(rootnode)

    while s1:
        node = s1.pop()
        post_order.append(node.data)
        if node.left:
            s1.append(node.left)
        if node.right:
            s1.append(node.right)

    print("Post-Order: ", post_order[::-1])


# main
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
