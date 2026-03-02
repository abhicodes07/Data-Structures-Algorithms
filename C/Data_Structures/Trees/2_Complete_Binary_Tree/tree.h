/* create a complete binary tree */
typedef struct treenode {
  int data;               // data
  struct treenode *left;  // points to left nodes
  struct treenode *right; // points to right nodes
} TreeNode;

// initialize nodes
TreeNode *initNode(int data);
