/* Binary Tree */
typedef struct treenode {
  int data;               // data part
  struct treenode *left;  // points to left nodes
  struct treenode *right; // points to the right nodes
} Treenode;

// initialize treenode
Treenode *initNode(int);
