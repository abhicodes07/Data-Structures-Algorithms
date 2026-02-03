package com.corejava.Data_Structures.trees.binarytrees;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        Node root = new Node();
        root = bt.createTree();

        System.out.print("In order: [ ");
        bt.in_order(root);
        System.out.println();

        System.out.print("Pre order: [ ");
        bt.pre_order(root);
        System.out.println();

        System.out.print("Post order: [ ");
        bt.post_order(root);
        System.out.println();
    }
}
