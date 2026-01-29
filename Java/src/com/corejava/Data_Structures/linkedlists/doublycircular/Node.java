package com.corejava.Data_Structures.linkedlists.doublycircular;

class Node {
    Node prev;
    Node next;
    int data;

    public Node (int data) {
        this.data = data;
        this.next = this.prev = null;
    }
}
