import java.util.Scanner;

public class java_04_deletion {
    static Scanner sc = new Scanner(System.in);

    // Insert elements
    static void insert(int arr[], int size) {
        if (size > 100 || size < 0) {
            System.out.println("Invalid size!");
        } else {
            for (int i = 0; i < size; i++) {
                System.out.print("Enter the " + i + "th element: ");
                arr[i] = sc.nextInt();
            }
        }
    }

    // Display elements
    static void display(int arr[], int size) {
        System.out.print("Elements in array: ");
        for (int i = 0; i < size; i++) {
            System.out.print(" " + arr[i]);
        }
    }

    // Delete Element at specific position
    static void deleteAt(int arr[], int size) {
        int pos;
        System.out.print("\n\nEnter the position you want to delete at: ");
        pos = sc.nextInt();
        
        if (pos > size || pos < 0) {
            System.out.println("Invalid Postion!");
        } else {
            for (int i = pos - 1; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            display(arr, size);
        }
    }

    public static void main(String[] args) {
        int n;

        // Initialise array
        int arr[] = new int[100];

        System.out.print("Enter the size of array: ");
        n = sc.nextInt();

        insert(arr, n);
        display(arr, n);
        deleteAt(arr, n);

        sc.close();
    }
}