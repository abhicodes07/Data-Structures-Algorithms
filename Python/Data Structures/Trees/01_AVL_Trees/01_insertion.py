import sys


class Treenode(object):
    def __init__(self, data: int) -> None:
        self.data: int = data
        self.left = None
        self.right = None
        self.height: int = 1


class AVLTree:
    # get height of the current node
    def get_height(self, node):
        return 0 if not node else node.height

    def update_height(self, node):
        return 1 + max(self.get_height(node.left), self.get_height(node.right))

    def get_balance_factor(self, node):
        return (
            0
            if node is None
            else self.get_height(node.left) - self.get_height(node.right)
        )

    def left_rotate(self, x: Treenode):
        y = x.right
        t2 = y.left

        y.left = x
        x.right = t2

        self.update_height(x)
        self.update_height(y)

        return y

    def right_rotate(self, x: Treenode):
        y = x.left
        t2 = y.right

        y.right = x
        x.left = t2

        self.update_height(x)
        self.update_height(y)

        return y

    def insert_node(self, root: Treenode, key: int):
        if not root:
            return Treenode(key)

        if key > root.data:
            root.right = self.insert_node(root.right, key)
        else:
            root.left = self.insert_node(root.left, key)

        self.update_height(root)

        balance_factor = self.get_balance_factor(root)

        if balance_factor > 1:
            if key < root.left.data:
                return self.right_rotate(root)
            else:
                root.left = self.left_rotate(root.left)
                return self.right_rotate(root)

        if balance_factor < -1:
            if key > root.right.data:
                return self.left_rotate(root)
            else:
                root.right = self.right_rotate(root.right)
                return self.left_rotate(root)

        return root

    def in_order(self, root):
        if root:
            self.pre_order(root.left)
            print(f"{root.data}", end=" ")
            self.pre_order(root.right)

    # Print the tree
    def printHelper(self, currPtr, indent, last):
        if currPtr != None:
            sys.stdout.write(indent)
            if last:
                sys.stdout.write("R----")
                indent += "     "
            else:
                sys.stdout.write("L----")
                indent += "|    "
            print(currPtr.data)
            self.printHelper(currPtr.left, indent, False)
            self.printHelper(currPtr.right, indent, True)


myTree = AVLTree()
root = None
nums = [33, 13, 52, 9, 21, 61, 8, 11]
for num in nums:
    root = myTree.insert_node(root, num)
myTree.printHelper(root, "", True)
