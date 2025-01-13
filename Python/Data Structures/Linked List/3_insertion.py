class Node:
    def __init__(self, item):
        self.data = item
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def createList(self):
        num_elements = int(input("Enter the number of elements in list: "))

        for i in range(num_elements):
            data = int(input(f"Enter the data for node {i + 1}: "))
            newnode = Node(data)

            if self.head is None:
                self.head = newnode
            else:
                temp = self.head
                while temp.next:
                    temp = temp.next
                temp.next = newnode

        self.displayList()

    def displayList(self):
        temp = self.head

        print("Elements in list: [ ", end=" ")
        while temp:
            print(f"{temp.data}", end=" -> ")
            temp = temp.next
        print("NULL ]")

    def insertAtBeginning(self, item: int):
        newnode = Node(item)

        if self.head is None:
            self.head = newnode
            return
        else:
            newnode.next = self.head
            self.head = newnode

        self.displayList()

    def insertAtEnd(self, item: int):
        newnode = Node(item)
        temp = self.head

        while temp.next:
            temp = temp.next
        temp.next = newnode
        self.displayList()

    def insertAtPosition(self, item: int):
        newnode = Node(item)
        count = 0
        i = 0

        current = self.head
        while current:
            current = current.next
            count += 1
        position = int(input("Enter the position: "))

        if position > count or position < 0:
            print("INVALID POSITION")
            return

        temp = self.head
        while i < position - 1:
            temp = temp.next
            i += 1
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
