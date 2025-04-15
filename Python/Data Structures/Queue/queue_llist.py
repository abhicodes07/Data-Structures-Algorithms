# implementation of queue using linked list


class Node:
    def __init__(self, item) -> None:
        self.next = None
        self.data = item


class Queue:
    def __init__(self) -> None:
        self.front = None  # head: deletion
        self.rear = None  # tail: insertion

    def enqueue(self, x):
        newnode = Node(x)

        if self.rear is None:
            self.rear = newnode
            self.front = newnode
        else:
            self.rear.next = newnode
            self.rear = newnode

        print(f"{x} enqueued.")

    def dequeue(self):
        if self.front is None:
            print("Queue is empty!")
            return
        else:
            print(f"{self.front.data} dequeued.")
            self.front = self.front.next

    def display(self):
        temp = self.front
        print("Elements in queue: ", end="")
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

    def peek(self):
        if self.rear:
            print(f"Peek element: {self.rear.data}")


if __name__ == "__main__":
    q = Queue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.display()
    q.dequeue()
    q.display()
    q.enqueue(40)
    q.display()
