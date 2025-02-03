# create Node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


# create circular linked list
class CircularLinkedList:
    def __init__(self) -> None:
        # initialize head none
        self.head = None
        self.tail = None

    # create linked list
    def createCLL(self):
        num = int(input("Enter the number of nodes in the list: "))

        for i in range(num):
            data = int(input(f"Enter the data for node {i}: "))
            newnode = Node(data)

            # check if list is empty
            if self.head is None:
                self.head = newnode
                self.tail = newnode
            else:
                self.tail.next = newnode
                self.tail = newnode

        # last node points to first node
        if self.tail:
            self.tail.next = self.head
        self.display()

    def display(self):
        temp = self.head

        print()
        print("Elements in the list: [ ", end="")

        while True:
            print(temp.data, end=" -> ")
            temp = temp.next

            if temp == self.head:
                break

        print(f"{temp.data} ]")


def main():
    cll = CircularLinkedList()
    cll.createCLL()


if __name__ == "__main__":
    main()
