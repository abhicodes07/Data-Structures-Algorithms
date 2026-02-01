package com.corejava.Data_Structures.trees.binarytrees;
import java.util.*;

class Node {
    Node left; // points to left node
    Node right; // points to right node
    int data; // data part

    // private constructor because
    // we are not going to use this class
    // outside the BinaryTrees class scope
    public Node() {
        this.left = null;
        this.right = null;
    }
}

public class BinaryTree {
    static Scanner sc = new Scanner(System.in);

    // create binary tree
    Node createTree() {
        System.out.print("Enter the data (-1 for no node): ");
        int data = sc.nextInt();

        // BASE CASE:
        if (data == -1) {
            return null;
        }

        // create a new node
        Node head = new Node();
        head.data = data;

        // create tree using recursion
        System.out.print("\nLeft node of "+ data +" ~~> ");
        head.left = this.createTree();
        System.out.print("\nRight node of "+ data +" ~~> ");
        head.right = this.createTree();

        return head;
    }

    void display(Node head) {
        if (head != null) {
            System.out.print(head.data + ", ");
            this.display(head.left);
            this.display(head.right);
        }
    }
}