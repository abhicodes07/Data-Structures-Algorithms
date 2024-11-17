import java.util.Scanner;

public class java_02_traversal {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // Initialise array
    int[] arr = new int[100];
    int size;

    // Append values
    System.out.print("Enter the size of array: ");
    size = sc.nextInt();

    // Overflow and Underflow Bound
    if (size > 100) {
      System.out.println("Overflow!\n");
    } else if (size < 0){
      System.out.println("Undeflow!");
    } else {
      for (int i = 0; i < size; i++) {
        System.out.print("Enter the " + i + " value of array: ");
        arr[i] = sc.nextInt();
      }
    }
    System.out.println();

    // Traverse array and display elements
    System.out.println("Elements in array: ");
    for (int j = 0; j < size; j++) {
      System.out.print(arr[j] + " ");
    }

  }
}
