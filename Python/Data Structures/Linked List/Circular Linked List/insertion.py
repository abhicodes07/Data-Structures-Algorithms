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

    def display(self):
        temp = self.tail.next
        print("Elements in the list: [ ", end="")
        while True:
            print(temp.data, end=" -> ")
            temp = temp.next

            if temp == self.tail.next:
                break
        print(f"{self.tail.next.data} ]")


def main():
    linked_list = CircularLinkedList()
    linked_list.creatCLL()


if __name__ == "__main__":
    main()
