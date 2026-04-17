class Treenode:
    def __init__(self, data: int) -> None:
        self.data: int = data
        self.left: object = None
        self.right: object = None
        self.height: int = 0


class AVLTree:
    def __init__(self) -> None:
        self.root = None
