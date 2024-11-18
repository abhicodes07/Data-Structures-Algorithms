import java.util.Scanner;
public class java_03_insertion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[100];
        int size, i;
        int pos, val;
        System.out.print("Enter the size of an array: ");
        size = sc.nextInt();

        // Check Overflow and Underflow bound
        if (size > 100) {
            System.out.println("Overflow!");
        } else if (size < 0) {
            System.out.println("Underflow!");
        } else {
            // Insert values
            for (i = 0; i < size; i++) {
                System.out.print("Enter the " + i + " value of array: ");
                arr[i] = sc.nextInt();
            }
        }

        // Display Elements
        System.out.print("Elements in array: ");
        for (int j = 0; j < size; j++) {
            System.out.print(" " + arr[j]);
        }
        
        // Insert elements at specific index
        System.out.print("Enter the value to insert: ");
        val = sc.nextInt();
        System.out.print("Enter the position: ");
        pos = sc.nextInt();

        // Check Overflow and Underflow!
        if (pos > size + 1) {
            System.out.println("Overflow!");
        } else if (pos < 0) {
            System.out.println("Underflow!");
        } else {
            // insert value
            for (int j = size - 1; j >= pos - 1; j--) {
                arr[j + 1] = arr[j];
            }
            arr[pos - 1] = val;
            size++;
        }
        
        // Display Elements
        System.out.print("Elements in array: ");
        for (int j = 0; j < size; j++) {
            System.out.print(" " + arr[j]);
        }
    }
}
