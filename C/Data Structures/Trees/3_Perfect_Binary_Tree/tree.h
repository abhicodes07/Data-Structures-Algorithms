typedef struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

TreeNode *initNode(int data);
