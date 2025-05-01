# Implementation of bubble sort algorithm

# Like bubbles rising to the top - largest elements "bubble up"
def bubbleSort(seq):
    """Compare adjacent elements, swap if needed. Repeat passes."""

    for i in range(len(seq) - 1):
        for j in range(len(seq) - 1 - i):
            if seq[j + 1] < seq[j]:
                temp = seq[j + 1]
                seq[j + 1] = seq[j]
                seq[j] = temp
    return seq


def main():
    arr = [5, 3, 10, 7, 1, 8, 4, 2, 9, 6]
    print(f"Unsorted: {arr}")
    sorted = bubbleSort(arr)
    print(f"Sorted:   {sorted}")


if __name__ == "__main__":
    main()
