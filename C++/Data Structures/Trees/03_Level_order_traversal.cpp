#include <cstdlib>
#include <iostream>
#include <queue>
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

// level order tree traversal
void level_order_traversal(Node *root) {
  if (!root) {
    exit(0);
  }

  // enqueue root node in queue
  queue<Node *> q;
  q.push(root);

  cout << "Level Order Traversal: [ ";
  while (!q.empty()) {
    Node *node = q.front();
    cout << node->data << " ";
    q.pop();

    // enqueue left nodes if there
    if (node->left) {
      q.push(node->left);
    }

    // enqueue right nodes if there
    if (node->right) {
      q.push(node->right);
    }
  }
  cout << "]" << endl;
}

// in order traversal
void in_order(Node *rootnode) {
  if (rootnode) {
    in_order(rootnode->left);
    cout << rootnode->data << " ";
    in_order(rootnode->right);
  }
}

// main
int main() {
  // init root
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);

  root->left->left = new Node(40);
  root->left->right = new Node(50);

  root->right->left = new Node(60);
  root->right->right = new Node(70);

  cout << "In order traversal: [ ";
  in_order(root);
  cout << "]" << endl;

  level_order_traversal(root);
  return 0;
}
