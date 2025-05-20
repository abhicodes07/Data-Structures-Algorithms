# IMPLEMENTATION OF TREES (BINARY TREE SPECIFICALLY)


class Node:
    """Create a tree node"""

    def __init__(self, data) -> None:
        self.left = None
        self.right = None
        self.data = data


class Tree:
    """Create a tree by creating the nodes recursively."""

    def __init__(self) -> None:
        self.root = None

    def createTree(self):
        val = int(input("Enter the data (-1 for no node): "))

        if val == -1:
            return None

        newnode = Node(val)

        # recursively create left nodes of tree
        print(f"LEFT NODE OF {val} --> ", end="")
        newnode.left = self.createTree()

        # recursively create right right nodes of tree
        print(f"RIGHT NODE OF {val} --> ", end="")
        newnode.right = self.createTree()


def main():
    tree = Tree()
    tree.createTree()

    if tree:
        print("SUCCESSFULLY CREATED A TREE!!")


if __name__ == "__main__":
    main()
