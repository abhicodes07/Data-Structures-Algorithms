# ALGORITHM TO TRAVERSE TREE IN POST, PRE AND IN
# ORDER IN A SINGLE RUN

# create a treenode
class Treenode:
    def __init__(self, data) -> None:
        self.left = None
        self.right = None
        self.data = data


def traversal(rootnode):
    """
    Traverse treenodes in pre/post/in order in a single run.
    """
    stack = []
    pre = []
    post = []
    inorder = []
    if not rootnode:
        return
    # push rootnode along with it's state
    stack.append([rootnode, 1])

    while len(stack) != 0:
        # pop top node
        node = stack.pop()

        # if state is 1, then process for preorder
        # increment 1 to 2
        # push the left subtree
        if node[1] == 1:
            pre.append(node[0].data)
            node[1] += 1
            stack.append(node)
            if node[0].left:
                stack.append([node[0].left, 1])

        # if state is 2, then process for inorder
        # increment 2 to 3
        # push the right subtree
        elif node[1] == 2:
            inorder.append(node[0].data)
            node[1] += 1
            stack.append(node)
            if node[0].right:
                stack.append([node[0].right, 1])

        # do not push again
        else:
            post.append(node[0].data)

    print("Pre-order: ", pre)
    print("Post-order: ", post)
    print("In-order: ", inorder)


def main():
    rootnode = Treenode(1)
    rootnode.left = Treenode(2)
    rootnode.right = Treenode(3)
    rootnode.left.left = Treenode(4)
    rootnode.left.right = Treenode(5)
    rootnode.right.left = Treenode(6)
    rootnode.right.right = Treenode(7)

    traversal(rootnode)


if __name__ == "__main__":
    main()
