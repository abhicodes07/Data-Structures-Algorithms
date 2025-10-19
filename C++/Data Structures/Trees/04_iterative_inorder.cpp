// Iterative post order traversal
#include <cstdlib>
#include <iostream>
#include <stack>
#include <type_traits>
using namespace std;

// create a treenode
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

// simple traversal for test
void simple_in_order(Node *root) {
  if (root) {
    simple_in_order(root->left);
    cout << root->data << " ";
    simple_in_order(root->right);
  }
}

// iterative in order traversal
void iterative_in_order(Node *root) {
  if (!root)
    exit(0);
  Node *node = root;

  // push root node to stack
  stack<Node *> s;

  cout << "Iterative Post order: [ ";
  while (true) {
    // process leftmost nodes
    if (node) {
      s.push(node);
      node = node->left;
    } else {
      // process right nodes
      if (s.empty())
        break;
      node = s.top();
      s.pop();
    }
  }
  cout << "]" << endl;
}

// main
int main() {
  Node *root;
  root = new Node(10);

  root->left = new Node(20);
  root->right = new Node(30);

  root->left->left = new Node(40);
  root->left->right = new Node(50);

  root->right->left = new Node(60);
  root->right->right = new Node(70);

  cout << "In order traversal: [ ";
  simple_in_order(root);
  cout << "]" << endl;

  iterative_in_order(root);
  return 0;
}
