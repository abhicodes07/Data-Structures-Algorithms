# Implementation of Level order traversal


class Node:
    """Create tree node"""

    def __init__(self, item) -> None:
        self.data = item
        self.left = None
        self.right = None


class Queue:
    """Implement queue"""

    def __init__(self) -> None:
        self.queue = []

    def is_empty(self):
        return len(self.queue) == 0

    # enqueue element in queue
    def enqueue(self, node):
        self.queue.append(node)

    # dequeue element from queue
    def dequeue(self):
        if self.is_empty():
            print("Underflow!")
            return
        return self.queue.pop(0)


# level order traversal: left to right
def level_order_traversal(root):
    if not root:
        return

    queue = Queue()
    queue.enqueue(root)

    print("Level Order traversal: ", end="")
    while not queue.is_empty():
        node = queue.dequeue()
        print(node.data, end=" ")

        if node.left:
            queue.enqueue(node.left)
        if node.right:
            queue.enqueue(node.right)

    print()


def main():
    root = Node(10)
    root.left = Node(20)
    root.right = Node(30)

    root.left.left = Node(40)
    root.left.right = Node(50)

    root.right.left = Node(60)
    root.right.right = Node(70)

    level_order_traversal(root)
