# DELETION OPERATION IN DOUBLY CIRCULAR LINKED LIST

# create node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None
        self.prev = None


# doubly circular linked list
class DoulbyLinkedLL:
    def __init__(self) -> None:
        self.head = None
        self.tail = None

    def createDCLL(self):
        arr = [10, 20, 30, 40, 50]

        for i in range(len(arr)):
            newnode = Node(arr[i])

            # check if list is empty
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

    # delete from beginning of the list
    def deleteFromBeg(self):
        temp = self.head

        if self.head is None:
            print("LIST IS EMPTY")
            return
        elif self.head == self.head.next:
            self.head = None
            self.tail = None
            self.temp = None
            print("NODE SUCCESSFULLY DELTED AND LIST IS EMPTY")
            return

        self.head = self.head.next
        self.head.prev = self.tail
        self.tail.next = self.head
        print(f"Deleted Node: [ {temp.data} ]")
        temp = None
        self.display()

    # delete from the end of the list
    def deleteFromEnd(self):
        temp = self.tail

        # if list empty
        if self.tail is None:
            print("LIST IS EMPTY")
            return
        elif self.tail == self.tail.next:
            self.head = None
            self.tail = None
            self.temp = None
            print("NODE SUCCESSFULLY DELTED AND LIST IS EMPTY")
            return

        self.tail = self.tail.prev
        self.tail.next = self.head
        self.head.prev = self.tail
        print(f"Deleted Node: [ {temp.data} ]")
        temp = None
        self.display()

    # delete from a specific position in the list
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

        temp = self.head
        i = 1

        while i < pos:
            temp = temp.next
            i += 1

        temp.next.prev = temp.prev
        temp.prev.next = temp.next
        print(f"Deleted Node: [ {temp.data} ]")
        temp = None
        self.display()


def main():
    linked_list = DoulbyLinkedLL()
    linked_list.createDCLL()
    # linked_list.deleteFromBeg()
    # linked_list.deleteFromEnd()
    linked_list.deleteFromPos(3)


if __name__ == "__main__":
    main()
