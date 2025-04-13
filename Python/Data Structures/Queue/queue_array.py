class Queue:
    def __init__(self) -> None:
        self.rear = -1  # enqueue
        self.front = -1  # dequeue
        self.queue = []
        self.MAX = 100

    # insert element
    def enqueue(self, val):
        if self.rear > self.MAX - 1:
            raise OverflowError
        elif self.rear == -1 and self.front == -1:
            self.front += 1
            self.rear += 1
            self.queue.append(val)
            print(f"Enqueued: {val}")
        else:
            self.rear += 1
            self.queue.append(val)
            print(f"Enqueued: {val}")

    # delete element
    def dequeue(self):
        if self.front == -1 and self.rear == -1:
            print("Underflow Error!")
            return
        elif self.front == self.rear:
            print(f"Dequeued: {self.queue.pop()}")
            self.front -= 1
            self.rear -= 1
        else:
            print(f"Dequeued: {self.queue.pop(self.front)}")

    # display
    def display(self):
        print()
        print("Elements in queue: ", end="")
        for i in self.queue:
            print(f"{i}", end=", ")
        print()
        print(f"Rear: {self.rear}")
        print(f"Front: {self.front}")
        print()

    # peek first
    def peek(self):
        if self.rear > self.MAX:
            raise OverflowError
        else:
            print(f"Peek: {self.queue[0]}")

    def isFull(self):
        if self.rear == self.MAX:
            print("Queue is full!")

    def isEmpty(self):
        if self.rear == -1 and self.rear == -1:
            print("Queue is empty!")


if __name__ == "__main__":
    q = Queue()
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    # q.enqueue(5)
    q.display()
    q.peek()
    q.dequeue()
    q.display()
    q.dequeue()
    q.display()
    q.peek()
