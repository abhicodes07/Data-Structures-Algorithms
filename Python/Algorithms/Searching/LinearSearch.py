# IMPLEMENTATION OF LINEAR SEARCH USING
# RECURSIVE AND ITERATIVE APPROACHES

# itertive approach
def linearSearchIterative(seq, val: int, size: int):
    position = -1
    for i in range(size):
        if seq[i] == val:
            position = i
            break

    if position == -1:
        print("Value not found.")
    else:
        print("Value found at: ")
        print(f"\t Position: {position}")
        print(f"\t Location: {position + 1}")


# recursive approach
def linearSearchRecursive(seq, val: int, pos: int):
    # base case: value not found
    if pos >= len(seq):
        return -1

    # base case: value found
    if seq[pos] == val:
        return pos

    # recursive case
    return linearSearchRecursive(seq, val, pos + 1)


if __name__ == "__main__":
    values = [34, 12, 43, 65, 33, 2, 10, 4, 70]
    linearSearchIterative(values, 33, len(values))
    result = linearSearchRecursive(values, 43, 0)

    if result == -1:
        print("Value not found.")
    else:
        print("Value found at: ")
        print(f"\t Position: {result}")
        print(f"\t Location: {result + 1}")
