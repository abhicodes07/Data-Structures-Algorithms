# INSERTION OPERATION IN DOUBLY CIRCULAR LINKED LIST

# create node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None
        self.prev = None


# doulby circular linked list
class DoublyCircularLL:
    def __init__(self) -> None:
        # initialize head and tail none
        self.head = None
        self.tail = None

    # create doubly circular linked list
    def createDCLL(self):
        val = [10, 20, 30, 40, 50]

        for i in range(len(val)):
            newnode = Node(val[i])

            if self.head is None:
                self.head = newnode
                self.tail = newnode
                self.head.next = newnode
                self.head.prev = newnode
            else:
                newnode.next = self.head
                newnode.prev = self.tail
                self.head.prev = newnode
                self.tail.next = newnode
                self.tail = newnode
        self.display()

    # display list
    def display(self):
        temp = self.head
        print("Elements in the list: [ ", end="")

        while True:
            print(temp.data, end=" <-> ")
            temp = temp.next

            if temp == self.tail.next:
                break

        print(f"{self.tail.next.data} ]")

    # get length
    def length(self):
        temp = self.head
        length = 0
        while True:
            temp = temp.next
            length += 1

            if temp == self.tail.next:
                break

        return length

    # insert node at the beginning of the list
    def insertAtBeg(self, item: int):
        # create a newnode
        newnode = Node(item)

        # check if list is empty
        if self.head is None:
            self.head = newnode
            self.tail = newnode
            self.head.next = newnode
            self.head.prev = newnode
        else:
            newnode.next = self.head
            newnode.prev = self.head.prev
            self.head.next.prev = newnode
            self.tail.next = newnode
            self.head = newnode

        self.display()

    # insert node at the end of the list
    def insertAtEnd(self, item: int):
        newnode = Node(item)

        # check if list is empty
        if self.head is None:
            self.head = newnode
            self.tail = newnode
            self.head.next = newnode
            self.head.prev = newnode
        else:
            newnode.next = self.tail.next
            newnode.prev = self.tail
            self.tail.next = newnode
            self.head.prev = newnode
            self.tail = newnode

        self.display()

    # insert node at a specific position in the list
    def insertAtPos(self, item: int, pos: int):
        len = self.length()
        newnode = Node(item)

        if pos < 0 or pos > len:
            print("INVALID POSITION!")
            return
        elif pos == 1:
            self.insertionAtBeg(222)
            return
        elif pos == len or pos == len + 1:
            self.insertAtEnd(444)
            return

        i = 1
        temp = self.head
        while i < pos - 1:
            temp = temp.next
            i += 1

        newnode.prev = temp
        newnode.next = temp.next
        temp.next = newnode
        temp.next.prev = newnode
        self.display()


def main():
    linked_list = DoublyCircularLL()
    linked_list.createDCLL()
    # linked_list.insertAtBeg(77)
    # linked_list.insertAtEnd(99)
    linked_list.insertAtPos(88, 3)


if __name__ == "__main__":
    main()
