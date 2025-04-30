# Implementation of selection sort algorihtm


def minimum(seq, start):
    """Use linear search approach to find the minimum element."""

    min = start
    for i in range(start, len(seq)):
        if seq[i] < seq[min]:
            min = i

    # return the index of found minimum element
    return min


def selectionSort(seq):
    for i in range(len(seq) - 1):
        min = minimum(seq, i)
        if min != i:
            temp = seq[min]
            seq[min] = seq[i]
            seq[i] = temp

    print(f"   Sorted list: {seq}")


def main():
    arr = [5, 3, 10, 7, 1, 8, 4, 2, 9, 6]
    print(f"Unsorted array: {arr}")
    selectionSort(arr)


if __name__ == "__main__":
    main()
