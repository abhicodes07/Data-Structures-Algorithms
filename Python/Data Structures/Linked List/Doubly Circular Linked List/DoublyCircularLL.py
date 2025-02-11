# IMPLEMENTATION OF DOUBLY CIRCULAR LINKED LIST

# create node of doubly circular linked list
class Node:
    def __init__(self, item) -> None:
        self.data = item  # data part
        self.next = None  # stores address of next node
        self.prev = None  # stores address of prev node


# Doubly Circular Linked List
class DoublyCircularLL:
    def __init__(self) -> None:
        self.tail = None  # points to last node in the list
        self.head = None  # points to first node in the list

    # create Doubly Circular Linked list
    def createDCLL(self):
        val = [10, 20, 30, 40, 50]

        for i in range(len(val)):
            # create newnodes using values from list
            newnode = Node(val[i])

            # check if list is empty
            if self.head is None:
                self.head = newnode  # head points to newnode
                self.tail = newnode  # tail points to newnode

                # first node's next and prev points to itself
                self.head.next = newnode
                self.head.prev = newnode
            else:
                newnode.next = self.head  # newnode pointing to head
                newnode.prev = self.tail  # newnode pointing to previous node

                # head pointing to last node in the list i.e., newnode
                self.head.prev = newnode

                # the previous node before appending newnode points to newnode
                self.tail.next = newnode

                self.tail = newnode  # move tail to newnode
        self.display()

    # display DCLL
    def display(self):
        temp = self.head  # first node in the list
        print("Elements in the list: [ ", end="")

        while True:
            print(temp.data, end=" <-> ")
            temp = temp.next

            # this condition works because we are updating temp before checking this condition
            if temp == self.tail.next:
                break

        print(f"{self.tail.next.data} ]")
        print(f"tail pointing to first node: {self.tail.next.data}")
        print(f"head pointing to last node: {self.head.prev.data}")


# main
def main():
    linked_list = DoublyCircularLL()
    linked_list.createDCLL()


if __name__ == "__main__":
    main()
