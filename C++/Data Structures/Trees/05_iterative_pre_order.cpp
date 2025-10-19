// iterative pre order
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

// recursive post order
void recursive_postorder(Node *rootnode) {
  if (rootnode) {
    recursive_postorder(rootnode->left);
    recursive_postorder(rootnode->right);
    cout << rootnode->data << " ";
  }
}

// iterative postorder
void iterative_postorder(Node *root) {
  if (!root)
    exit(0);

  stack<Node *> s1, s2;

  // push the root on stack 1
  s1.push(root);

  while (!s1.empty()) {
    Node *temp = s1.top();
    s1.pop();
    s2.push(temp);

    if (temp->left) {
      s1.push(temp->left);
    }

    if (temp->right) {
      s1.push(temp->right);
    }
  }

  cout << "Iterative Post-order: [ ";
  while (!s2.empty()) {
    Node *temp = s2.top();
    cout << temp->data << " ";
    s2.pop();
  }
  cout << "]" << endl;
}

// main
int main() {
  // create root node
  Node *root = new Node(10);

  root->left = new Node(20);
  root->right = new Node(30);

  root->left->left = new Node(40);
  root->left->right = new Node(50);
  root->right->left = new Node(60);
  root->right->right = new Node(70);

  if (root) {
    cout << "Recursive Post-order: [ ";
    recursive_postorder(root);
    cout << "]" << endl;
    iterative_postorder(root);
  }
}
