# IMPLEMENTATION OF INSETION SORT IN A LIST


def insertionSort(seq):
    for i in range(len(seq)):
        key = seq[i]
        j = i - 1

        # if the value in sorted sublist is greater than key
        # then swap it with key
        while j >= 0 and seq[j] > key:
            seq[j + 1] = seq[j]
            j -= 1

        seq[j + 1] = key


def main():
    arr = [5, 3, 10, 7, 1, 8, 4, 2, 9, 6]
    print(f"Unsorted arraY: {arr}")
    insertionSort(arr)
    print(f"Sorted arraY: {arr}")


if __name__ == "__main__":
    main()
