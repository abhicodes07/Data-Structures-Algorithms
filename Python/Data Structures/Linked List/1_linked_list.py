class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None


if __name__ == "__main__":
    linked_list = LinkedList()

    # Create nodes
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)

    # Link nodes
    node1.next = node2  # Node 1 points to Node 2
    node2.next = node3  # Node 2 points to Node 3

    # Set head of the linked list
    linked_list.head = node1

    # Print the linked list
    current = linked_list.head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")

