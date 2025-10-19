#include <cstdlib>
#include <iostream>
using namespace std;

// create a node
class Treenode {
public:
  int data;
  Treenode *left;
  Treenode *right;
};

Treenode *createNode() {
  int x;
  cout << "Enter the data (-1 for no node): ";
  cin >> x;

  if (x == -1)
    return 0;
  Treenode *newnode = new Treenode();
  newnode->data = x;

  // create left nodes
  cout << "Enter the left node for " << x << ": ";
  newnode->left = createNode();

  // create a right nodes
  cout << "Enter the right nodes for " << x << ": ";
  newnode->right = createNode();

  return newnode;
};

// main
int main() {
  Treenode *root = new Treenode();
  root = createNode();

  if (root)
    cout << endl << "Tree created Successfully";
  return 0;
}
