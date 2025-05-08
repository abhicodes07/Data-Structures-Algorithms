# implementation of merge sort algorithm

# merge procedure
def merge(arr, left_sub, right_sub):
    i = j = k = 0

    while i < len(left_sub) and j < len(right_sub):
        if left_sub[i] <= right_sub[j]:
            arr[k] = left_sub[i]
            i += 1
        else:
            arr[k] = right_sub[j]
            j += 1
        k += 1

    # append any remaining elements in both sub-arrays
    while i < len(left_sub):
        arr[k] = left_sub[i]
        i += 1
        k += 1

    while j < len(right_sub):
        arr[k] = right_sub[j]
        j += 1
        k += 1


# merge sorting
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2

        # divide
        left = arr[:mid]
        right = arr[mid:]

        # conquer
        merge_sort(left)
        merge_sort(right)

        # combine
        merge(arr, left, right)


# main fx
def main():
    seq = [9, 3, 7, 5, 6, 4, 8, 2]
    print(f"Unsorted list: {seq}")
    merge_sort(seq)
    print(f"Sorted list:   {seq}")


if __name__ == "__main__":
    main()
