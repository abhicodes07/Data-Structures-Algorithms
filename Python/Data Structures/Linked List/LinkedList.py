import re


class SimpleNode:
    """
    Node having only two parts, data for data part
    and next part for next address
    """

    def __init__(self, item) -> None:
        self.data = item  # data part
        self.next = None  # next address


class ComplexNode:
    """
    Node having three parts, data for storing data,
    next for next node's address and prev part for
    previous ndoe's address
    """

    def __init__(self, item) -> None:
        self.data = item
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None

    def display(self):
        if not self.head:
            print("LIST IS EMPTY")
            return

        temp = self.head
        print("Elements in the list: [ ", end="")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next

        print("NULL ]")

    def circularDisplay(self):
        if not self.head:
            print("LIST IS EMPTY")
            return

        temp = self.head
        print("Elements in the list: [ ", end="")

        while True:
            print(temp.data, end=" <-> ")
            temp = temp.next

            if temp == self.tail.next:
                break

        print(f"{self.tail.next.data} ]")

    def length(self):
        temp = self.head
        length = 0
        while temp:
            temp = temp.next
            length += 1
        return length

    def delete(self, node):
        print(f"Deleted Node: [ {node.data} ]")
        node = None


class SinglyLinkedList(LinkedList):
    def createSLL(self, *values: int):
        for i in values:
            newnode = SimpleNode(i)

            if self.head is None:
                self.head = newnode
            else:
                self.tail = self.head
                while self.tail.next:
                    self.tail = self.tail.next
                self.tail.next = newnode
                self.tail = newnode
        self.display()

    def insertAtBeg(self, item: int):
        newnode = ComplexNode(item)

        if not self.head:
            self.head = newnode
        else:
            newnode.next = self.head
            self.head = newnode

        self.display()

    def insertAtEnd(self, item: int):
        newnode = SimpleNode(item)

        if not self.head:
            self.head = newnode
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = newnode
            temp = newnode
        self.display()

    def insertAtPos(self, pos: int, item: int):
        len = self.length()
        newnode = SimpleNode(item)

        if pos > len or pos < 0:
            print("INVALID POSITION")
            return
        elif pos == 1:
            self.insertAtBeg(item)
            return
        elif pos == len:
            self.insertAtEnd(item)
            return

        temp = self.head
        i = 1
        while i < pos - 1:
            temp = temp.next
            i += 1
        newnode.next = temp.next
        temp.next = newnode
        self.display()

    def deleteFromBeg(self):
        if not self.head:
            print("List is empty")
            return
        temp = self.head
        self.head = self.head.next
        self.delete(temp)

    def deleteFromEnd(self):
        if not self.head:
            print("List is empty")
            return
        temp = self.tail
        self.tail = self.tail.prev
        self.delete(temp)

    def deleteFromPos(self, pos):
        len = self.length()
        if not self.head:
            print("LIST IS EMPTY")
            return
        elif pos > len or pos < 0:
            print("Invalid position")
            return
        elif pos == 1:
            self.deleteFromBeg()
            return
        elif pos == len:
            self.deleteFromEnd()
            return

        i = 1
        temp = self.head
        while i < pos:
            prevnode = temp
            temp = temp.next
            i += 1

        prevnode.next = temp.next
        self.delete(temp)


class DoublyLinkedList(LinkedList):
    def __init__(self) -> None:
        super().__init__()

    def createDLL(self, *values):
        for i in values:
            newnode = ComplexNode(i)

            if not self.head:
                self.head = newnode
                self.tail = newnode
            else:
                self.tail.next = newnode
                newnode.prev = self.tail
                self.tail = newnode
        self.display()

    def insertAtBeg(self, item: int):
        newnode = ComplexNode(item)
        if not self.head:
            self.head = newnode
            self.tail = newnode
        else:
            newnode.next = self.head
            self.head.prev = newnode
            self.head = newnode

        self.display()

    def insertAtEnd(self, item: int):
        newnode = ComplexNode(item)
        if not self.head:
            self.head = newnode
            self.tail = newnode
        else:
            self.tail.next = newnode
            newnode.prev = self.tail
            self.tail = newnode
        self.display()

    def insertAtPos(self, pos: int, item):
        len = self.length()
        newnode = ComplexNode(item)
        if pos > len or pos < 0:
            print("List is empty!")
            return
        elif pos == 1:
            self.insertAtBeg(item)
            return
        elif pos == len:
            self.insertAtEnd(item)
            return

        i = 1
        temp = self.head
        while i < pos - 1:
            temp = temp.next
            i += 1
        newnode.next = temp.next
        newnode.prev = temp
        temp.next = newnode

        self.display()

    def deleteFromBeg(self):
        if not self.head:
            print("LIST IS EMPTY")
            return
        temp = self.head
        self.head = self.head.next
        self.head.prev = None
        self.delete(temp)

    def deleteFromEnd(self):
        if not self.head:
            print("LIST IS EMPTY")
            return
        temp = self.tail
        self.tail = self.tail.prev
        self.tail.next = None
        self.delete(temp)

    def deleteFromPos(self, pos: int):
        len = self.length()
        if pos > len or pos < 0:
            print("INVALID POSITION")
            return
        elif pos == 1:
            self.deleteFromBeg()
            return
        elif pos == len:
            self.deleteFromEnd()
            return

        i = 1
        temp = self.head
        while i < pos:
            temp = temp.next
            i += 1
        temp.prev.next = temp.next
        temp.next.prev = temp.prev
        self.delete(temp)


class CircularLinkedList(LinkedList):
    def createCLL(self, *values):
        for i in values:
            newnode = SimpleNode(i)

            if not self.head:
                self.head = newnode
                self.tail = newnode
                self.head.next = newnode
            else:
                newnode.next = self.head
                self.tail.next = newnode
                self.tail = newnode

        self.circularDisplay()

    def insertAtBeg(self, item):
        newnode = SimpleNode(item)

        if not self.head:
            self.head = newnode
            self.head.next = newnode
            self.tail = newnode
        else:
            newnode.next = self.head
            self.head = newnode
            self.tail.next = newnode

        self.circularDisplay()

    def insertAtEnd(self, item):
        newnode = SimpleNode(item)
        if not self.head:
            self.head = newnode
            self.head.next = newnode
            self.tail = newnode
        else:
            newnode.next = self.head
            self.tail.next = newnode
            self.tail = newnode

        self.circularDisplay()

    def insertAtPos(self, item, pos: int):
        len = self.length()
        newnode = SimpleNode(item)
        if pos > len or pos < 0:
            print("INVALID POSITION")
            return
        elif pos == 1:
            self.insertAtBeg(item)
            return
        elif pos == len:
            self.insertAtEnd(item)
            return

        i = 1
        temp = self.head
        while i < pos - 1:
            temp = temp.next
            i = i + 1

        newnode.next = temp.next
        temp.next = newnode
        self.circularDisplay()

    def deleteFromBeg(self):
        if not self.head:
            print("LIST IS EMPTY")
            return

        temp = self.head
        self.head = self.head.next
        self.tail.next = self.head
        self.delete(temp)
        self.circularDisplay()

    def deleteFromEnd(self):
        if not self.head:
            print("LIST IS EMPTY")
            return

        temp = self.tail
        self.tail = self.tail.next
        self.tail.next = self.head
        self.delete(temp)
        self.circularDisplay()

    def deleteFromPos(self, pos: int):
        if not self.head:
            print("LIST IS EMPTY")
            return
        if pos > self.length() or pos < 0:
            return "LIST IS EMPTY"
        elif pos == 1:
            self.deleteFromBeg()
            return
        elif pos == len:
            self.deleteFromEnd()
            return

        i = 1
        temp = self.head
        while i < pos:
            temp = temp.next
            prevnode = temp
            i += 1

        prevnode.next = temp.next
        self.delete(temp)
        self.circularDisplay()

    def reverse(self):
        pass


class DoublyCircularLinkedList(LinkedList):
    # display list
    def displayList(self):
        temp = self.head
        print("Elements in the list: [ ", end="")

        while True:
            print(temp.data, end=" <-> ")
            temp = temp.next

            if temp == self.tail.next:
                break

        print(f"{self.tail.next.data} ]")

    def createDCLL(self, *values):
        for i in values:
            newnode = ComplexNode(i)
            if not self.head:
                self.head = newnode
                self.tail = newnode
                self.head.next = newnode
                self.head.prev = newnode
            else:
                newnode.next = self.head
                newnode.prev = self.tail
                self.tail.next = newnode
                self.head.prev = newnode
                self.tail = newnode
        self.circularDisplay()

    def insertAtBeg(self, item):
        newnode = ComplexNode(item)
        if not self.head:
            self.head = newnode
            self.tail = newnode
            self.head.next = newnode
            self.head.prev = newnode
        else:
            newnode.next = self.head
            newnode.prev = self.tail
            self.tail.next = newnode
            self.head.prev = newnode
            self.head = newnode
        self.circularDisplay()

    def insertAtEnd(self, item):
        newnode = ComplexNode(item)
        if not self.head:
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
        self.circularDisplay()

    def insertAtPos(self, item, pos):
        len = self.length()
        newnode = ComplexNode(item)

        if pos < 0 or pos > len:
            print("INVALID POSITION!")
            return
        elif pos == 1:
            self.insertAtBeg(222)
            return
        elif pos == len or pos == len + 1:
            self.insertAtEnd(444)
            return

        i = 1
        temp = self.head

        while i < pos - 1:
            temp = temp.next
            i += 1

        newnode.next = temp.next
        newnode.prev = temp
        temp.next.prev = newnode
        temp.next = newnode
        self.displayList()

    def deleteFromBeg(self):
        pass

    def deleteFromEnd(self):
        pass

    def deleteFromPos(self, pos: int):
        pass

    def reverse(self):
        pass


def main():
    list = SinglyLinkedList()
    list.createSLL(10, 20, 30, 40, 50, 50)

    list.insertAtPos(3, 211)


if __name__ == "__main__":
    main()
