// create treenode
typedef struct treenode {
  int data;
  int height;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

// initialzie treenode
TreeNode *initNode(int data);

// create tree
TreeNode *insertNode(TreeNode *root, int data);

// inorder treewalk
void inOrderWalk(TreeNode *root);

// free tree
void freeTree(TreeNode *root);
