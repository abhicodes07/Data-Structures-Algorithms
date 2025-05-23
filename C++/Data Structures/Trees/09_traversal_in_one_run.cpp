/*
 * ALGORITHM TO TRAVERSE A TREE IN
 * POST / IN / PRE ORDER IN SINGLE RUN
 * TIME COMPLEXITY: O(3N) -> O(N)
 * SPACE COMPLEXITY: O(3N)
 */

#include <cstdlib>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

// create a treenode
struct Treenode {
  int data;
  Treenode *left;
  Treenode *right;
  // struct constructor initializer
  Treenode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// display lists
void display(vector<int> pre, vector<int> post, vector<int> in) {
  cout << "Pre-Order: ";
  for (int i = 0; i < pre.size(); i++) {
    cout << pre[i] << " ";
  }
  cout << endl;
  cout << "Post-Order: ";
  for (int i = 0; i < post.size(); i++) {
    cout << post[i] << " ";
  }
  cout << endl;
  cout << "In-Order: ";
  for (int i = 0; i < in.size(); i++) {
    cout << in[i] << " ";
  }
  cout << endl;
}

// function to traverse a tree in post/in/pre orders in single run
void postPreInOrderTraversal(Treenode *rootnode) {
  // create a stack to store treenode and state
  stack<pair<Treenode *, int>> s;

  // vector list to store results
  vector<int> preorder, inorder, postorder;
  if (!rootnode)
    exit(1);

  // initially, push root node to stack
  s.push({rootnode, 1});

  while (!s.empty()) {
    // pop top node
    auto node = s.top();
    s.pop();

    // if state is 1 then process for preorder
    // increment 1 to 2
    // push the left subtree
    if (node.second == 1) {
      preorder.push_back(node.first->data);
      node.second++;
      s.push(node);
      // if there are left nodes push them to stack
      if (node.first->left) {
        s.push({node.first->left, 1});
      }
    }
    // if state is 2 then process for inorder
    // increment 2 to 3
    // push the right subtree
    else if (node.second == 2) {
      inorder.push_back(node.first->data);
      node.second++;
      s.push(node);
      if (node.first->left) {
        s.push({node.first->right, 1});
      }
    }
    // if state is 3 then process for postorder
    else {
      // do not push node back again
      postorder.push_back(node.first->data);
    }
  }
  display(preorder, postorder, inorder);
}

int main(int argc, char *argv[]) {
  Treenode *root = new Treenode(1);
  root->left = new Treenode(2);
  root->right = new Treenode(3);
  root->left->left = new Treenode(4);
  root->left->right = new Treenode(5);
  root->right->left = new Treenode(6);
  root->right->right = new Treenode(7);

  postPreInOrderTraversal(root);
  return 0;
}
