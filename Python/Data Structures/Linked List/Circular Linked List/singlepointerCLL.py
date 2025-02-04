# create node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


# circular linked list
class CircularLL:
    def __init__(self) -> None:
        # initialize single tail pointer
        self.tail = None

    # create circular linked list
    def createCLL(self):
        num = int(input("Enter the number of nodes in the list: "))

        for i in range(num):
            val = int(input(f"Enter the data for node {i}: "))
            newnode = Node(val)

            if self.tail is None:
                self.tail = newnode
                # since the first node is only single node in the
                # list it points to itself
                self.tail.next = newnode
            else:
                # update newnode's next part
                # since it's the single pointer
                # which can access previous node in the list
                newnode.next = self.tail.next
                self.tail.next = newnode
                self.tail = newnode  # move tail to newnode

        return self.tail

    def display(self, tail):
        temp = self.tail.next

        print()
        print("Elements in the list: [", end="")
        while True:
            print(temp.data, end=" -> ")
            temp = temp.next

            if temp == self.tail.next:
                break

        print(f"{self.tail.next.data} ]")


def main():
    linked_list = CircularLL()
    list = linked_list.createCLL()
    linked_list.display(list)


if __name__ == "__main__":
    main()
