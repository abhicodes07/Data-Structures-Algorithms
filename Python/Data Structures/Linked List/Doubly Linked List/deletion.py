# create node
class Node:
    def __init__(self, item) -> None:
        self.data = item  # data part
        self.next = None  # next node address
        self.prev = None  # previous node address


# create a doubly linked list
class LinkedList:
    def __init__(self) -> None:
        # initialize head null
        self.head = None

    def createDLL(self):
        """Create a doubly linked list"""
        num = int(input("Enter the number of nodes in the list: "))
        for i in range(num):
            data = int(input(f"Enter the data for node {i}: "))
            newnode = Node(data)

            # check if list is empty
            if self.head is None:
                self.head = newnode
                self.tail = newnode
            else:
                temp = self.head
                while temp.next:
                    temp = temp.next
                temp.next = newnode  # update next of last node with newnode
                newnode.prev = temp  # update prev of newnode with temp
                self.tail = newnode
        print()
        self.display()

    def display(self):
        """Display linked list"""
        temp = self.head
        print("Elements in the list: [ ", end="")
        while temp:
            print(temp.data, end="->")
            temp = temp.next
        print(" NULL ]")

    def length(self):
        """Length of Doubly Linked List"""
        temp = self.head
        length = 0
        while temp:
            temp = temp.next
            length += 1
        return length

    def deleteFromEnd(self):
        """Delete from end of the linked list"""
        if self.head is None:
            print("LIST IS EMPTY!!")
            return
        else:
            temp = self.tail
            self.tail = self.tail.prev
            self.tail.next = None

            # display deleted node and free temp
            print(f"\nDeleted Node: {temp.data}")
            temp = None
            self.display()

    def deleteFromBeg(self):
        """Delete from the beginning of the linked list"""
        if self.head is None:
            print("LIST IS EMPTY!!")
            return
        else:
            temp = self.head
            self.head = self.head.next
            self.head.prev = None

            # display deleted node and free temp
            print(f"\nDeleted Node: {temp.data}")
            temp = None
            self.display()

    def deleteFromPos(self, pos: int):
        """Delete from the beginning of the linked list"""
        if pos < 0 or pos > self.length():  # check position bound
            print("INVALID POSITION!")
            return
        elif pos == 0:  # call function if position is first node
            self.deleteFromBeg()
            return
        elif pos == self.length():  # call function if position is last node
            self.deleteFromEnd()
            return
        else:
            i = 1
            temp = self.head
            while i < pos:  # move to specified position
                temp = temp.next
                i += 1
            # update addresses of previous and next nodes from temp
            temp.prev.next = temp.next
            temp.next.prev = temp.prev

            # display deleted node and free temp
            print(f"\nDeleted Node: {temp.data}")
            temp = None
            self.display()


def main():
    linked_list = LinkedList()
    linked_list.createDLL()
    linked_list.deleteFromPos(3)
    linked_list.deleteFromBeg()
    linked_list.deleteFromEnd()


if __name__ == "__main__":
    main()
