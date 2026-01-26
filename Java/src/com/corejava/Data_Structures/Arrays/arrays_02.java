package com.corejava.Data_Structures.Arrays;

public class arrays_02 {
  public static void main(String[] args) {
    int[][] arr = new int[3][2];

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        // assign a random value and type cast it
        arr[i][j] = (int) (Math.random() * 100);
      }
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        System.out.print(arr[i][j]);
      }
      System.out.println();
    }
  }
}
