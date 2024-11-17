lst = []

size = int(input("Enter the size: "))

# append elements
for i in range(size):
    val = int(input(f"Enter the {i} element: "))
    lst.append(val)

# Traverse
print("Elements in array: ", end=" ")
for i in lst:
    print(i, end=" ")
