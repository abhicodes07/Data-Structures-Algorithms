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

    # delete from the beginning of the circular list
    def deleteFromBeg(self):
        temp = self.tail.next

        # check if list is empty or not
        if self.tail is None:
            print("List is already empty")
            return
        # if there's only single node
        elif self.tail.next == self.tail:
            self.tail = None
            print()
            print(f"Deleted Node: [ {temp.data} ]")
            temp = None
            self.display()
        else:
            # tail points to the second list in the list
            self.tail.next = temp.next
            print()
            print(f"Deleted Node: [ {temp.data} ]")
            temp = None
            self.display()

    # delete from the end of the circular list
    def deleteFromEnd(self):
        # traverse list till last node
        current = self.tail.next

        if self.tail is None:
            print("List is already empty")
            return
        # if there's only single node in the list
        elif self.tail.next == self.tail:
            self.tail = None
            print()
            print(f"Deleted Node: [ {current.data} ]")
            current = None
            print("LIST IS EMPTY!!")
        else:
            # traverse till last node
            while current != self.tail:
                prevnode = current  # one node previous from last node
                current = current.next

            prevnode.next = self.tail.next
            self.tail = prevnode
            print()
            print(f"Deleted Node: [ {current.data} ]")
            current = None
            self.display()

    # delete from a specific position of the circular list
    def deleteFromPos(self, pos):
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
        else:
            i = 1
            current = self.tail.next
            while i < pos - 1:
                current = current.next
                i += 1
            nextnode = current.next  # on position node
            current.next = nextnode.next
            print()
            print(f"Deleted Node: [ {nextnode.data} ]")
            nextnode = None
            self.display()


def main():
    linked_list = CircularLinkedList()
    linked_list.creatCLL()
    # linked_list.deleteFromBeg()
    # linked_list.deleteFromEnd()
    linked_list.deleteFromPos(1)


if __name__ == "__main__":
    main()
