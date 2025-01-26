# create node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.prev = None
        self.next = None


# Linked List
class LinkedList:
    def __init__(self) -> None:
        self.head = None

    # create list
    def createList(self):
        num = int(input("Enter the number of nodes in the lsit: "))

        for i in range(num):
            data = int(input(f"Enter the data for node {i}: "))
            newnode = Node(data)

            if self.head is None:
                self.head = newnode
            else:
                tail = self.head
                while tail.next:
                    tail = tail.next
                tail.next = newnode
                newnode.prev = tail
        self.display()

    # length of the linked list
    def length(self):
        length = 0
        temp = self.head
        while temp:
            temp = temp.next
            length += 1
        return length

    # insert at the end of linked list
    def insertAtEnd(self, item: int):
        newnode = Node(item)

        # if list is empty
        if self.head is None:
            self.head = newnode
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = newnode
            newnode.prev = temp
        self.display()

    # insert at the beginning of the list
    def insertAtBeginning(self, item: int):
        newnode = Node(item)

        # if list is empty
        if self.head is None:
            self.head = newnode
            return
        else:
            self.head.prev = newnode
            newnode.next = self.head
            self.head = newnode

        self.display()

    # insert at certain position in the list
    def insertAtPos(self, pos: int, item: int):
        if pos < 0 or pos > self.length():
            print("INVALID POSITION!!!")
            return
        elif pos == 1:
            self.insertAtBeginning(item)
        else:
            newnode = Node(item)
            i = 1
            temp = self.head

            # traverse till last node
            while i < pos - 1:
                temp = temp.next
                i += 1

            nextnode = temp.next
            newnode.next = nextnode
            newnode.prev = temp
            temp.next = newnode
            nextnode.prev = newnode
            self.display()

    # display list
    def display(self):
        tail = self.head
        print("Elements in the list: [ ", end="")
        while tail:
            print(tail.data, end=" -> ")
            tail = tail.next
        print(" NULL ]")


def main():
    linked_list = LinkedList()
    linked_list.createList()
    linked_list.insertAtPos(3, 777)


if __name__ == "__main__":
    main()
