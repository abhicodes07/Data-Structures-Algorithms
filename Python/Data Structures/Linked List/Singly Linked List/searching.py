# IMPLEMENTATION OF SEARCHING OPERATION ON SINGLY LINKED LIST
# USING BINARY SERACH AND LINEAR SEARCH

# create a node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


# create a linked list
class SinglyLinkedList:
    def __init__(self) -> None:
        # initialize head and tail
        self.head = None
        self.tail = None
        self.count = 0

    def insert(self, data):
        """Create Linked list with specified size and input values"""
        newnode = Node(data)

        if self.head is None:
            self.head = newnode
            self.tail = newnode
            self.count += 1
        else:
            while self.tail.next:
                self.tail = self.tail.next
            self.tail.next = newnode

    def search(self):
        """Seach specific element in the linked list"""
        value = int(input("Enter the value you want to search: "))
        print("Enter the method:\n\t1. Linear Search\n\t2. Binary Search")
        choice = int(input("Your choice: "))
        match choice:
            case 1:
                return self.linearSearch(value)
            case 2:
                return self.binarySearch(value)

    def linearSearch(self, value: int):
        """Search specific element in the linked list using linear search."""
        temp = self.head
        pos = 0
        while temp:
            if temp.data == value:
                return pos
            temp = temp.next
            pos += 1
        return -1

    # find mid of the linked list
    def findMid(self, low, high):
        # if list is empty
        if low is None:
            return None, -1

        slow = low
        fast = low
        pos = 0  # keep track of position

        while fast != high and fast.next != high:
            slow = slow.next
            pos += 1
            fast = fast.next.next

        # return mid and position of the mid as tuple
        return slow, pos

    def binarySearch(self, value: int):
        """Divide and conquer approach to find the element using binary serach."""
        low = self.head  # start of the linked list
        high = None  # end of the list
        start_pos = 0

        while low != high:
            mid, mid_offset = self.findMid(low, high)

            if mid is None:
                return -1

            mid_pos = start_pos + mid_offset

            if mid.data == value:
                return mid_pos
            elif mid.data > value:
                # search in left part
                high = mid
            else:
                # search in right part
                low = mid.next
                start_pos += mid_pos

        return -1  # value not found

    def display(self):
        """Display elements in linked list"""

        temp = self.head
        print("Elements in the list: [ ", end="")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL ]\n")


def main():
    values = [3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62]

    ll = SinglyLinkedList()

    for i in values:
        ll.insert(i)
    ll.display()

    result = ll.search()
    if result != -1:
        print(f"Value found at position: {result}")
    else:
        print("Value not found.")


if __name__ == "__main__":
    main()
