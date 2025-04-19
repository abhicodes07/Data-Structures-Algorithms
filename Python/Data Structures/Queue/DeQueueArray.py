# Implementation of deque using array


class Deque:
    def __init__(self, size: int) -> None:
        self.rear = -1
        self.front = -1
        self.size = size
        self.deque = [None] * self.size

    def enqueueFront(self, val):
        """
        Front part of a standard queue is used for dequeue or
        deletion operation by incrementing it's value. however,
        in order to enqueue element using front we need to
        decrement it backwards.
        """
        if self.isFull():
            print("DEQUE IS FULL.")
            return
        elif self.rear == -1 and self.front == -1:
            # if there's nothing in the list simply increment rear
            # and front to 0 from -1 and enqueue the value.
            self.rear = 0
            self.front = 0
            self.deque[self.front] = val
            print(f"Enqueued: {self.deque[self.front]}")

        elif self.front == 0:
            # if front is 0 that is, at the initial position, then move
            # front to size - 1, at last of the deque
            self.front = self.size - 1
            self.deque[self.front] = val
            print(f"Enqueued: {self.deque[self.front]}")

        else:
            # if front is not at the 0 or max size then
            # simply decrement it.
            self.front -= 1
            self.deque[self.front] = val
            print(f"Enqueued: {self.deque[self.front]}")

    def enqueueRear(self, val):
        """
        Enqueue from rear is the standard operation of queue and
        gets incremented whenever an element is to be inserted.
        However on a circular array queue, the rear part needs
        to be relocated to initial positon once it reaches max
        size if the initial position is empty or front points
        to it.
        """

        if self.isFull():
            print("DEQUE IS FULL.")
            return
        elif self.front == -1 and self.rear == -1:
            # if deque is empty simple increment both rear
            # and front to 0 and enqueue element.
            self.rear = 0
            self.front = 0
            self.deque[self.rear] = val
            print(f"Enqueued: {self.deque[self.rear]}")
        elif self.rear == self.size - 1:
            # if rear is at max size of the deque and there's
            # still space in the qeueue then move rear to the
            # initial position.
            self.rear = 0
            self.deque[self.rear] = val
            print(f"Enqueued: {self.deque[self.rear]}")
        else:
            # if rear is not at intial or last position then
            # keep incrementing it.
            self.rear += 1
            self.deque[self.rear] = val
            print(f"Enqueued: {self.deque[self.rear]}")

    def dequeueFront(self):
        """
        Dequeue element from front part of the deque by incrementing
        it. If front points to max size of the queue then move it forward
        to initial position that is, 0.
        """
        if self.isEmpty():
            print("DEQUE IS EMPTY.")
            return
        elif self.front == self.rear:
            # when rear and front point to same element in the queue
            # then queue has single element
            print(f"Dequeued: {self.deque[self.front]}")
            self.front = -1
            self.rear = -1
        elif self.front == self.size - 1:
            # if front points to max size, move it to initial position.
            print(f"Dequeued: {self.deque[self.front]}")
            self.front = 0
        else:
            print(f"Dequeued: {self.deque[self.front]}")
            self.front += 1

    def dequeueRear(self):
        """
        Dequeue operation using rear part of the dequeu is performed
        by decrementing it from it's position.
        And if rear is 0 and front is greater than rear then move rear
        to max size.
        """
        if self.isEmpty():
            print("DEQUE IS EMPTY.")
            return
        elif self.rear == self.front:
            # if rear and front point to same element then there's
            # only single element in the deque
            print(f"Dequeued: {self.deque[self.rear]}")
            self.rear = -1
            self.front = -1
        elif self.rear == 0:
            # if rear points to inital position in the queue and is smaller than
            # front then move rear to max size or last position
            print(f"Dequeued: {self.deque[self.rear]}")
            self.rear = self.size - 1
        else:
            print(f"Dequeued: {self.deque[self.rear]}")
            self.rear -= 1

    def display(self):
        """Display elements in deque."""
        if self.isEmpty():
            print("DEQUE IS EMPTY, NOTHING TO DISPLAY.")
            return

        print("Elements in queue: [", end=" ")
        i = self.front
        while i != self.rear:
            print(self.deque[i], end=" ")
            i = (i + 1) % self.size
        print(f"{self.deque[self.rear]} ]")
        print()

    def getFront(self):
        """Get front value."""
        if self.isEmpty():
            print("DEQUE IS EMPTY.")
            return
        print(f"FRONT: {self.front}")

    def getRear(self):
        """Get rear value."""
        if self.isEmpty():
            print("DEQUE IS EMPTY.")
            return
        print(f"REAR: {self.rear}")

    # check if deque is empty
    def isEmpty(self):
        if self.rear == -1 and self.front == -1:
            return True
        return False

    # check if deque is full
    def isFull(self):
        if (self.rear + 1) % self.size == self.front:
            return True
        return False


if __name__ == "__main__":
    d = Deque(5)
    # d.enqueueFront(10)
    # d.enqueueFront(20)
    # d.enqueueFront(30)
    # d.enqueueFront(40)
    # d.display()

    d.enqueueRear(10)
    d.enqueueRear(20)
    d.enqueueRear(30)
    d.enqueueRear(40)
    d.enqueueRear(50)
    d.display()
    d.dequeueFront()
    d.dequeueFront()
    d.display()
    d.enqueueFront(60)
    d.enqueueFront(70)
    d.display()
    d.getFront()
    d.getRear()
    d.dequeueFront()
    d.display()
    d.getFront()
    d.getRear()
    d.enqueueRear(90)
    d.display()
    d.getFront()
    d.getRear()
