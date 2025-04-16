# Implementation of circular queue on a array
class CircularQueue:
    # initialize front and rear
    def __init__(self, capicity: int) -> None:
        self.front = -1
        self.rear = -1
        self.capicity = capicity
        self.queue = [None] * self.capicity
        self.size = 0

    def enqueue(self, val):
        if self.front == -1 and self.rear == -1:
            self.front = 0
            self.rear = 0
            self.queue[self.rear] = val
            self.size += 1

        elif (self.rear + 1) % self.capicity == self.front:
            print("Queue is full.")
            raise OverflowError

        else:
            self.rear = (self.rear + 1) % self.capicity
            self.queue[self.rear] = val
            self.size += 1

        print(f"Enqueued: {val}")

    def dequeue(self):
        if self.front == -1 and self.rear == -1:
            print("Queue is empty!")
        elif self.front == 0 and self.rear == 0:
            print(f"Dequeued: {self.front}")
            self.queue[self.front] = None
            self.front = -1
            self.rear = -1
            self.size -= 1
        else:
            print(f"Dequeued: {self.queue[self.front]}")
            self.queue[self.front] = None
            self.front = self.front + 1 % self.capicity
            self.size -= 1

    def display(self):
        if self.rear == -1 and self.front == -1:
            print("Queue is empty")
            return

        temp = self.front
        items = []
        for _ in range(self.size):
            items.append(self.queue[temp])
            temp = (temp + 1) % self.capicity

        print("Elements in the list: ", items)


if __name__ == "__main__":
    q = CircularQueue(5)

    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)
    q.enqueue(50)
    q.display()

    q.dequeue()
    q.dequeue()
    q.display()

    q.enqueue(60)
    q.enqueue(70)
    q.display()
