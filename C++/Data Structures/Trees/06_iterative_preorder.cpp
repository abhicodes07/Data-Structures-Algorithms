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

void recursive_preorder(Node *rootnode) {
  if (rootnode) {
    cout << rootnode->data << " ";
    recursive_preorder(rootnode->left);
    recursive_preorder(rootnode->right);
  }
}

void iterative_preorder(Node *rootnode) {
  if (!rootnode)
    return;

  stack<Node *> s1;
  s1.push(rootnode);

  cout << "Iterative Pre-order: [ ";
  while (!s1.empty()) {
    Node *temp = s1.top();
    s1.pop();
    cout << temp->data << " ";

    if (temp->right)
      s1.push(temp->right);
    if (temp->left)
      s1.push(temp->left);
  }
  cout << "]";
}

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
    recursive_preorder(root);
    cout << "]" << endl;
    iterative_preorder(root);
  }
}
