public class java_01_arrays {
  public static void main(String[] args) {
    // Initialise Array
    int[] arr = new int[5];

    // Display elements
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    // Display Elements
    System.out.print("Elements: ");
    for (int i = 0; i < 5; i++) {
      System.out.print(" " + arr[i]);
    }
  }
}
