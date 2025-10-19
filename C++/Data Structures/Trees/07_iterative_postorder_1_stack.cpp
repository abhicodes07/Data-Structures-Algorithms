#include <cstdlib>
#include <iostream>
using namespace std;

// create treenode
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

void simple_postorder(Node *rootnode) {
  if (rootnode) {
    simple_postorder(rootnode->left);
    simple_postorder(rootnode->right);
    cout << rootnode->data << " ";
  }
}

void postorder_one_stack(Node *rootnode) {
  if (!rootnode)
    exit(0);
  Node *lastvisited;
  Node *current = rootnode;
}

int main() {
  Node *root = new Node(10);

  root->left = new Node(20);
  root->right = new Node(30);

  root->left->left = new Node(40);
  root->left->right = new Node(50);
  root->right->left = new Node(60);
  root->right->right = new Node(70);
  return 0;
}
