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

    # reverse the circular linked list
    def reverse(self):
        if self.tail.next is None:
            print("list is empty")
            return  # exit func

        if self.tail.next == self.tail:
            self.display()
            return

        current = self.tail.next
        nextnode = current.next
        while current != self.tail:
            prevnode = current
            current = nextnode
            nextnode = current.next
            current.next = prevnode
        nextnode.next = self.tail
        self.tail = nextnode
        self.display()


def main():
    linked_list = CircularLinkedList()
    linked_list.creatCLL()
    linked_list.reverse()


if __name__ == "__main__":
    main()
