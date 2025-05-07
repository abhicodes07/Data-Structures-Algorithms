# implementation of quick sort algorithm in python


def partition(arr: list, low: int, high: int):
    pivot = arr[low]  # first element as pivot
    i = low  # search values greater than pivot
    j = high - 1  # search values less than pivot

    while i < j:
        while i <= high and arr[i] <= pivot:
            i += 1

        while j >= 0 and arr[j] > pivot:
            j -= 1

        # swap values
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]

    # swap the value of pivot with it's right position
    arr[low], arr[j] = arr[j], arr[low]

    return j


# recurssively sort array
def quickSort(arr, low, high):
    if low < high:
        j = partition(arr, low, high)
        quickSort(arr, low, j)
        quickSort(arr, j + 1, high)


def main():
    seq = [10, 16, 8, 12, 15, 6, 3, 9, 5, 18]
    low = 0
    high = len(seq) - 1
    quickSort(seq, low, high)
    print(seq)


if __name__ == "__main__":
    main()
