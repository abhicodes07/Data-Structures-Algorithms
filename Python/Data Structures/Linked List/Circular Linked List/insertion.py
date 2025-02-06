# create node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


class CircularLinkedList:
    def __init__(self) -> None:
        self.tail = None

    # create circular Linked list
    def creatCLL(self):
        num = int(input("Enter the number of nodes in the list: "))

        for i in range(num):
            val = int(input(f"Enter the data for node {i}: "))
            newnode = Node(val)

            if self.tail is None:
                self.tail = newnode
                self.tail.next = newnode
            else:
                newnode.next = self.tail.next
                self.tail.next = newnode
                self.tail = newnode
        self.display()

    # display the nodes
    def display(self):
        temp = self.tail.next
        print("Elements in the list: [ ", end="")
        while True:
            print(temp.data, end=" -> ")
            temp = temp.next

            if temp == self.tail.next:
                break
        print(f"{self.tail.next.data} ]")

    # length of the list
    def length(self):
        temp = self.tail.next
        length = 0
        while True:
            temp = temp.next
            length += 1

            if temp == self.tail.next:
                break

        return length

    # insert at the beginning of the circular list
    def insertAtBeg(self, item):
        # create a newnode
        newnode = Node(item)

        # if list is already empty
        if self.tail is None:
            self.tail = newnode
            self.tail.next = newnode
        else:
            newnode.next = self.tail.next
            self.tail.next = newnode

        self.display()

    # insert at the end of the circular list
    def insertAtEnd(self, item: int):
        newnode = Node(item)

        # check if list is empty
        if self.tail is None:
            self.tail = newnode
            self.tail.next = newnode
        else:
            newnode.next = self.tail.next
            self.tail.next = newnode
            self.tail = newnode

        self.display()

    # insert at the specific position
    def insertAtPos(self, pos: int, item: int):
        # create a newnode
        newnode = Node(item)

        len = self.length()

        if pos < 0 or pos > len:
            print("INVALID POSITION!!")
            return
        elif pos == 1:
            self.insertAtBeg(item)
        elif pos == len + 1:
            self.insertAtEnd(item)
        else:
            temp = self.tail.next
            i = 1

            # traverse till position
            while i < pos - 1:
                temp = temp.next
                i += 1

            # append node at position
            newnode.next = temp.next
            temp.next = newnode

        self.display()


def main():
    linked_list = CircularLinkedList()
    linked_list.creatCLL()
    # linked_list.insertAtBeg(777)
    # linked_list.insertAtEnd(999)
    linked_list.insertAtPos(3, 555)


if __name__ == "__main__":
    main()
