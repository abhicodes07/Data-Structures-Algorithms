class Node:
    def __init__(self, item):
        self.data = item
        self.next = None


class LinkedList:
    def __init__(self):
        # Initialise head pointer None
        self.head = None

    def createList(self):
        """
        Create a Linked List with few elements
        taken as input from the user.
        """
        num_elements = int(input("Enter the number of elements in list: "))

        for i in range(num_elements):
            data = int(input(f"Enter the data for node {i + 1}: "))
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

    def insertAtBeginning(self, item: int):
        """
        Insert at the beginning of the list.
        """
        newnode = Node(item)

        if self.head is None:
            # if list is empty then the newnode is the first and last node
            # and no need to further execute; exit
            self.head = newnode
            return
        else:
            # update the nodes in the list first then head pointer
            # so that we do not lose the link to the other nodes
            newnode.next = self.head
            self.head = newnode

        self.displayList()

    def insertAtEnd(self, item: int):
        """
        Insert at the End of the list.
        """
        newnode = Node(item)

        temp = self.head
        # traverse till last node till temp.next == NULL
        while temp.next:
            temp = temp.next
        temp.next = newnode

        self.displayList()

    def insertAtPosition(self, item: int):
        """
        Insert at certain position in the linked list.
        """
        newnode = Node(item)
        count = 0  # count the number of elements in the list
        i = 0

        # use a temporary pointer to count the elements
        current = self.head
        while current:
            current = current.next
            count += 1
        position = int(input("Enter the position: "))

        # bound
        if position > count or position < 0:
            print("INVALID POSITION")
            return

        temp = self.head
        # traverse till the specified position
        while i < position - 1:
            temp = temp.next
            i += 1
        # update right nodes first then left ones
        newnode.next = temp.next
        temp.next = newnode

        self.displayList()


def main():
    lnkd = LinkedList()
    lnkd.createList()
    lnkd.insertAtBeginning(100)
    lnkd.insertAtEnd(1000)
    lnkd.insertAtPosition(2000)


if __name__ == "__main__":
    main()
