# create structure of node


class Node:
    """
    Node having two seperate partiions.
        -> data : data part of the node
        -> next : pointer to next node.
    """

    def __init__(self, item) -> None:
        self.data = item
        self.next = None


class LinkedList:
    """Create Linked list"""

    def __init__(self) -> None:
        self.head = None

    def createNode(self, item):
        """
        Create and append nodes in a list.
        Roles of variable:
            -> temp : used as a traversal pointer
            -> head : head pointer stores first node
        """
        newnode = Node(item)
        if self.head is None:
            self.head = newnode
            # Stop further execution of the method
            # because the new node is already at the
            # end (and also the beginning) of the list.
            return  # means end the method
        temp = self.head
        while temp.next:  # traverse to the last node
            temp = temp.next  # move temp to the last node in the list
        temp.next = newnode

    def displayList(self):
        """Display Linked List"""
        temp = self.head  # move temp to initial Node
        while temp is not None:
            print(f"{temp.data}", end="->")
            temp = temp.next
        print("NULL")


if __name__ == "__main__":
    linked_list = LinkedList()
    linked_list.createNode(10)
    linked_list.createNode(20)
    linked_list.createNode(30)
    linked_list.createNode(40)
    linked_list.createNode(50)
    linked_list.displayList()
