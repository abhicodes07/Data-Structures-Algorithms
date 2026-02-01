package com.corejava.Data_Structures.trees.binarytrees;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        Node root = new Node();
        root = bt.createTree();
        System.out.print("Elements in tree: [ ");
        bt.display(root);
    }
}
