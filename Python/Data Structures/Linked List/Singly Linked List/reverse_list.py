class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def createNode(self):
        num = int(input("Enter the number of nodes in the list: "))

        for i in range(num):
            data = int(input(f"Enter the data for the node {i}: "))
            newnode = Node(data)

            # append nodes at the end of the list
            if self.head is None:
                # if list is empty
                self.head = newnode
            else:
                # if list is not empty
                temp = self.head
                # traverse till last node
                while temp.next:
                    temp = temp.next
                temp.next = newnode
        self.displayList()

    def displayList(self):
        """
        Display elements in a Linked list
        """
        temp = self.head

        print("Elements in list: [ ", end=" ")
        # last node
        while temp:
            print(f"{temp.data}", end=" -> ")
            temp = temp.next
        print("NULL ]")

    def reverse(self):
        """
        Reverse a linked list:
        Initially currentnode and nextnode points head i.e., first node
        and prevnode node stores None.
        """
        currentnode = self.head
        nextnode = self.head
        prevnode = None  # initially prevnode stores None

        while nextnode:
            nextnode = nextnode.next
            currentnode.next = prevnode  # currentnode stores address of previous node
            prevnode = currentnode  # move prevnode
            currentnode = nextnode  # move nextnode

        self.head = prevnode  # at end head points towards the last node
        self.reversed = self.displayList()


def main():
    linked_list = LinkedList()
    linked_list.createNode()
    linked_list.reverse()


if __name__ == "__main__":
    main()
