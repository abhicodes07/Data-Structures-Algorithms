# create a node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None
        self.prev = None


# create a doubly linked list
class DLinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None

    def display(self):
        """Display linked list"""
        temp = self.head
        print("Elements in the list: [ ", end="")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL ]")

    def createDLL(self):
        """create doubly linked list"""
        num = int(input("Enter the number of nodes in the list: "))
        for i in range(num):
            data = int(input(f"Enter the data for node {i}: "))
            newnode = Node(data)

            # if list is empty
            if self.head is None:
                self.head = newnode
                self.tail = newnode
            else:
                temp = self.head
                while temp.next:
                    temp = temp.next

                temp.next = newnode
                newnode.prev = temp
                self.tail = newnode
        self.display()

    def reverse(self):
        current = self.head

        while current:
            nextnode = current.next  # store next node from current
            current.next = current.prev  # swap next with prev
            current.prev = nextnode  # swap prev with next
            current = nextnode  # update current

        # swap head with tail
        nextnode = self.head
        self.head = self.tail
        self.tail = nextnode

        self.display()


def main():
    linked_list = DLinkedList()
    linked_list.createDLL()
    linked_list.reverse()


if __name__ == "__main__":
    main()
