# IMPLEMENTATION OF BINARY SEARCH USING RECURSIVE
# AND ITERATIVE APPROACH


def iterativeBinarSearch(seq, key: int):
    """Binary search using iterative approach"""

    low = 0  # start of list
    mid = None  # mid of list
    high = len(seq)  # end of list
    pos = None  # position of found value

    while low <= high:
        # find mid position
        mid = (low + high) // 2

        # if mid value matches key
        if seq[mid] == key:
            pos = mid
            break
        if seq[mid] > key:
            # search in left side
            high = mid - 1
        else:
            # search in right side
            low = mid + 1

    if pos:
        print("VALUE FOUND")
        print(f"\t Value: {key}")
        print(f"\t Position: {pos}")
        print(f"\t Location: {pos + 1}")
        print()
    else:
        print("Value not found.")


def recuriseBinarySearch(seq, key: int, low: int, high: int):
    """Binary search with recursive approach using divide and conquer"""

    # solve smaller problem
    # if the list contains single element
    if low == high:
        if seq[low] == key:
            return low
        else:
            return -1
    else:
        # calculate mid of list and sub lists
        mid = (low + high) // 2

        if seq[mid] == key:
            return mid
        if seq[mid] > key:
            # serach in left side
            return recuriseBinarySearch(seq, key, low, mid - 1)
        else:
            # search in right side
            return recuriseBinarySearch(seq, key, mid + 1, high)
    return -1


# main method
def main():
    arr = [3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62]
    low = 0
    high = len(arr)
    val = 42

    iterativeBinarSearch(arr, 17)
    iterativeBinarSearch(arr, 31)
    result = recuriseBinarySearch(arr, val, low, high)

    if result != -1:
        print("VALUE FOUND")
        print(f"\t Value: {val}")
        print(f"\t Position: {result}")
        print(f"\t Location: {result + 1}")
        print()
    else:
        print("Value not found.")


if __name__ == "__main__":
    main()
