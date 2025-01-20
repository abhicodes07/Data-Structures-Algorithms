# Create structure of the node
class Node:
    def __init__(self, item) -> None:
        self.data = item  # data part
        self.next = None  # next part


class LinkedList:
    def __init__(self) -> None:
        # Initialize node
        self.head = None

    def createList(self):
        """Create Linked List"""
        num = int(input("Enter the number of elements in the list: "))
        for i in range(num):
            data = int(input(f"Enter the data for node {i}: "))
            newnode = Node(data)

            if self.head is None:
                self.head = newnode
            else:
                temp = self.head
                while temp.next:
                    temp = temp.next
                temp.next = newnode

        self.displayList()

    def length(self):
        """Return Length of the list"""

        len = 0
        temp = self.head
        while temp:
            temp = temp.next
            len += 1
        return len

    def displayList(self):
        """Display elements in the list."""

        temp = self.head
        print("\nElements in Linked List: [ ", end="")

        while temp:
            print(f"{temp.data}", end=" -> ")
            temp = temp.next
        print(" NULL ]")
        print(f"Length: {self.length()}")

    def deleteFromBeginning(self):
        """Delete from the beginning in the linked list"""

        temp = self.head  # points to the first noew
        if temp is None:  # if list is empty
            print("List is already empty!")
            return
        else:
            self.head = temp.next  # second node
            self.displayList()
            print(f"Deleted Node: {temp.data}")
            temp = None  # delete node

    def deleteFromEnd(self):
        """
        When deleting from the end of
        the list we need to traverse till
        last node and add NONE in next part
        of the second last node.
        """
        temp = self.head
        while temp.next:
            prevnode = temp
            temp = temp.next

        # if there's only single node
        if temp == self.head:
            self.head = None
            temp = None
        else:
            prevnode.next = None
            self.displayList()
            print(f"Deleted Node: {temp.data}")
            temp = None  # delete node

    def deleteFromPos(self, pos):
        """
        To delete from specified position
        we need two pointers:
        - temp : which points to one previous node from position
        - nextnode : which points to position node
        """
        temp = self.head
        i = 0
        while i < pos - 2:  # one previous node from the position
            temp = temp.next
            i += 1
        nextnode = temp.next  # another pointer to point on position node
        temp.next = nextnode.next  # update temp next part
        self.displayList()
        print(f"Deleted Node: {temp.data}")
        nextnode = None  # delete node


def main():
    lkd = LinkedList()
    lkd.createList()
    # lkd.deleteFromBeginning()
    # lkd.deleteFromEnd()
    lkd.deleteFromPos(3)


if __name__ == "__main__":
    main()
