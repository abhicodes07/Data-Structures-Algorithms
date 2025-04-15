# implementation of queue on linked list using queue encapsulation

# create element node
class Node:
    def __init__(self, item) -> None:
        self.data = item
        self.next = None


# queue structure
class Queue:
    def __init__(self) -> None:
        self.front = None
        self.rear = None


# create queue using linked list
class QueueLinkedList:
    def __init__(self) -> None:
        # initialize queue
        self.q = Queue()

    # isnert element
    def enqueue(self, item):
        newnode = Node(item)

        if self.q.rear is None:
            self.q.front = newnode
            self.q.rear = newnode
            print(f"Enqueued: {self.q.rear.data}")
        else:
            self.q.rear.next = newnode
            self.q.rear = newnode
            print(f"Enqueued: {self.q.rear.data}")

    # remove element: deletion
    def dequeue(self):
        if self.q.front is None:
            print("Queue is empty!")
            return

        print(f"Dequeued: {self.q.front.data}")
        self.q.front = self.q.front.next

        if self.q.rear is None:
            self.q.front = None

    # disply elements
    def display(self):
        if self.q.front is None:
            print("Queue is empty!")
            return
        else:
            temp = self.q.front
            print("Elements in the list: [ ", end="")
            while temp:
                print(temp.data, end=" -> ")
                temp = temp.next
            print("NULL ]")
            print()

    def peek(self):
        if self.q.rear is None:
            print("Queue is empty")
            return

        print(f"Peek element: {self.q.rear.data}")


if __name__ == "__main__":
    q = QueueLinkedList()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.display()
    q.dequeue()
    q.display()
    q.enqueue(40)
    q.display()
    q.peek()
