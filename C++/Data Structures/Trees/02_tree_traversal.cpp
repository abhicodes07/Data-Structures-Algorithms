#include <cstdlib>
#include <iostream>
using namespace std;

// create a treenode
struct Treenode {
  int data;
  Treenode *left;
  Treenode *right;
};

// create tree
Treenode *createTree() {
  int val;

  cout << "Enter the data (-1 for no node): ";
  cin >> val;

  if (val == -1)
    return 0;

  Treenode *newnode = new Treenode();
  if (!newnode)
    exit(0);
  newnode->data = val;

  // recursively create left node
  cout << "LEFT NODE OF " << val << ": ";
  newnode->left = createTree();

  // recursively create right node
  cout << "RIGHT NODE OF " << val << ": ";
  newnode->right = createTree();

  return newnode;
}

// traversal
void in_order(Treenode *rootnode) {
  if (rootnode) {
    in_order(rootnode->left);
    cout << rootnode->data << " ";
    in_order(rootnode->right);
  }
}

void post_order(Treenode *rootnode) {
  if (rootnode) {
    post_order(rootnode->left);
    post_order(rootnode->right);
    cout << rootnode->data << " ";
  }
}

void pre_order(Treenode *rootnode) {
  if (rootnode) {
    cout << rootnode->data << " ";
    post_order(rootnode->left);
    post_order(rootnode->right);
  }
}

// main
int main() {
  Treenode *root = new Treenode();
  root = createTree();

  if (root) {
    cout << "In-order: [ ";
    in_order(root);
    cout << endl;

    cout << "Post-order: [ ";
    post_order(root);
    cout << endl;

    cout << "Pre-order: [ ";
    pre_order(root);
    cout << endl;
  }
  return 0;
}
