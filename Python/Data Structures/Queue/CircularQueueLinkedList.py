# Implementation of queue using linked list and queue encapsulation


class Node:
    """Create node element structure"""

    def __init__(self, value: int) -> None:
        self.data = value  # data part
        self.next = None  # next part


class CircularQueue:
    """
    Circular queue using linked list works same as circular linked list
    in which last node points to head i.e., first node.
    """

    # Create circular queue
    def __init__(self) -> None:
        self.front = None  # head part: initially, points to first node
        self.rear = None  # tail part: points to last added node in queue

    # insert element in the queue
    def enqueue(self, x: int):
        newnode = Node(x)

        # if queue is empty
        if self.front is None:
            self.rear = newnode
            self.front = newnode
        else:
            self.rear.next = newnode  # connect newnode with list
            self.rear = newnode  # move rear to last node
            self.rear.next = self.front  # last node points to first node

        print(f"Enqueued: {newnode.data}")

    # delete element from the queue
    def dequeue(self):
        temp = self.front

        if self.front is None:
            print("Queue is empty.")
            return
        elif self.front.next == self.front:  # if there's only one node
            self.rear = None
            self.front = None
            print(f"Dequeued: {temp.data}")
            temp = None
        else:
            self.front = self.front.next
            self.rear.next = self.front
            print(f"Dequeued: {temp.data}")
            temp = None

    # display queue
    def display(self):
        if self.rear is None:
            print("Queue is empty!")
            return

        temp = self.front
        print("Elements in queue: [", end=" ")
        while True:
            print(temp.data, end=" -> ")
            temp = temp.next

            if temp == self.front:
                break
        print("NULL ]\n")

    # peek element in the queue
    def peek(self):
        if self.rear is None:
            print("Queue is empty!\n")
            return
        print(f"Peek element: {self.rear.data}")

    # is empty
    def isEmpty(self):
        if self.rear is None:
            print("Queue is empty!\n")
            return
        print("Queue is not empty!\n")


if __name__ == "__main__":
    q = CircularQueue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)
    q.enqueue(50)
    q.display()

    q.dequeue()
    q.display()

    q.enqueue(60)
    q.display()
