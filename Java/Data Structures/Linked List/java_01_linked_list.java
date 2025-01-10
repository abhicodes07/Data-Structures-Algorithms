// Define Node class
class Node {
    int data; // Data of the node
    Node next; // Reference to the next node

    Node(int item) {
        data = item; // Initialize data
        next = null; // Initialize next as null
    }
}

// Define LinkedList class
class LinkedList {
    Node head; // Head of the linked list

    LinkedList() {
        head = null; // Initialize the list as empty
    }

    void createNode(int item) {
        Node newNode = new Node(item); // Create a new node

        if (head == null) {
            head = newNode; // If the list is empty, make the new node the head
        } else {
            Node temp = head; // Start from the head
            while (temp.next != null) { // Traverse to the last node
                temp = temp.next;
            }
            temp.next = newNode; // Link the new node to the end of the list
        }
    }

    void display() {
        Node temp = head; // Start from the head
        while (temp != null) { // Traverse the list
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null"); // Mark the end of the list
    }
}

// Main class
public class java_01_linked_list {
    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList(); // Create a LinkedList object

        linkedList.createNode(10); // Add nodes
        linkedList.createNode(20);
        linkedList.createNode(30);

        linkedList.display(); // Display the list
    }
}

