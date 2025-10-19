#include <iostream>
#include <stack>
using namespace std;

// create Treenode
struct Treenode {
  int data;
  Treenode *right;
  Treenode *left;

  Treenode(int val) {
    data = val;
    left = right = nullptr;
  }
};

// Iterative post order using 2 stack
void iterative_post_order(Treenode *rootnode) {
  if (!rootnode)
    return;

  stack<Treenode *> st1;
  stack<Treenode *> st2;

  st1.push(rootnode);
  while (!st1.empty()) {
    Treenode *node = st1.top();
    st2.push(node);
    st1.pop();

    if (node->left) {
      st1.push(node->left);
    }

    if (node->right) {
      st1.push(node->right);
    }
  }

  cout << "Post order using Two Stack: ";
  while (!st2.empty()) {
    Treenode *temp = st2.top();
    cout << temp->data << " ";
    st2.pop();
  }
  cout << endl;
}

// main
int main() {
  Treenode *root = new Treenode(10);
  root->left = new Treenode(20);
  root->right = new Treenode(30);

  root->left->left = new Treenode(40);
  root->left->right = new Treenode(50);

  root->right->left = new Treenode(60);
  root->right->right = new Treenode(70);

  iterative_post_order(root);
  return 0;
}
