class Node:
    def __init__(self, item) -> None:
        self.data = item  # data part
        self.next = None  # next part
        self.prev = None  # prev part


class DoublyLinkedList:
    def __init__(self) -> None:
        self.head = None  # initialize head empty

    def createDoublyList(self):
        choice = 1
        while choice:
            data = int(input("Enter the data: "))
            newnode = Node(data)

            if self.head is None:
                self.head = newnode
            else:
                temp = self.head
                while temp.next:
                    temp = temp.next
                temp.next = newnode
                newnode.prev = temp

            choice_1 = input("Do you want to continue adding more node (y/n) : ")
            if choice_1 == "y":
                choice = 1
            else:
                choice = 0
        self.displayList()

    def displayList(self):
        temp = self.head
        print("\nElements in the list: [ ", end="")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL ]")


def main():
    linked_list = DoublyLinkedList()
    linked_list.createDoublyList()


if __name__ == "__main__":
    main()
