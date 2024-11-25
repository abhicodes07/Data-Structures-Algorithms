arr = []
size = int(input("Enter the size of array: "))

for i in range(size):
    num = int(input(f"Enter the {i}th element: "))
    arr.append(num)

print("Element in array: ", end=" ")
for i in range(len(arr)):
    print(arr[i], end=" ")

val = int(input("\nEnter the value you want to delete: "))
arr.remove(val)

print("Element in array: ", end=" ")
for i in range(len(arr)):
    print(arr[i], end=" ")
