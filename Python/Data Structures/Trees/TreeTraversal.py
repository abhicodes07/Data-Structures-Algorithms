# implementation of tree traversal operations on tree


class Node:
    """Create a node of tree."""

    def __init__(self, item) -> None:
        self.left = None
        self.right = None
        self.data = item


class Tree:
    """create tree using recurssion approach"""

    # create tree
    def create_tree(self):
        val = input("Enter the data ('n' for no node): ")
        if val == "n":
            return None

        # recurssively create nodes
        newnode = Node(val)

        print(f"LEFT NODE OF {val} --> ", end="")
        newnode.left = self.create_tree()

        print(f"RIGHT NODE OF {val} --> ", end="")
        newnode.right = self.create_tree()

        return newnode

    # in order traversal
    def in_order(self, root):
        if root:
            self.in_order(root.left)  # left sub-tree
            print(root.data, end=" ")  # root
            self.in_order(root.right)  # right sub-tree

    # post order traversal
    def post_order(self, root):
        if root:
            self.post_order(root.left)  # left sub-tree
            self.post_order(root.right)  # right sub-tree
            print(root.data, end=" ")  # root

    # pre order traversal
    def pre_order(self, root):
        if root:
            print(root.data, end=" ")  # root
            self.pre_order(root.left)  # left sub-tree
            self.pre_order(root.right)  # right sub-tree


# main
def main():
    tree = Tree()
    root = tree.create_tree()

    if root:
        print("TREE CREATED SUCESSFULLY")

        print("In order: ", end=" ")
        tree.in_order(root)
        print()

        print("Pre order: ", end=" ")
        tree.pre_order(root)
        print()

        print("Post order: ", end=" ")
        tree.post_order(root)
        print()
    else:
        print("Tree is empty!!")


if __name__ == "__main__":
    main()
