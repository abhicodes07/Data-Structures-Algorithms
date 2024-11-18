lst = []
size = int(input("Enter the size: "))

for i in range(size):
    value = int(input(f"Enter the {i}th value: "))
    lst.append(value)

# Display values
print("Values in list: ", end=" ")
for i in range(size):
    print(lst[i], end=" ")

# insert values
val = int(input("\n\nEnter the value: "))
pos = int(input("Enter the position: "))

if pos < size and pos > 0:
    lst.insert(pos - 1, val)

# Display values
print("Values in list: ", end=" ")
for i in range(size):
    print(lst[i], end=" ")
