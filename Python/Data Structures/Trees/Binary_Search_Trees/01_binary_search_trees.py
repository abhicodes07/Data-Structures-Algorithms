# IMPLEMENTATION OF BINARY SERACH TREES


class Tree:
    """Implement Tree node."""

    def __init__(self, item):
        self.left = None
        self.item = item
        self.right = None


class BinarySearchTree:
    """
    Create binary search tree using following property:
        [Left <= Root <= Right]
    """

    def __init__(self, root) -> None:
        self.root = root

    # searching
    def search(self, root):
        pass

    # minimum
    def minimum(self, root):
        pass

    def maximum(self, root):
        pass
