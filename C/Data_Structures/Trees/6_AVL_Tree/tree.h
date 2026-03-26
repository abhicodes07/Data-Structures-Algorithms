// create treenode
typedef struct treenode {
  int data;
  int height;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

// initialzie treenode
TreeNode *initNode(int data);

// get height
int getHeight(TreeNode *node);

// get maximum of height between left and right
int max(int a, int b);

// update height
void updateHeight(TreeNode *node);

// get balance factor
int getBalanceFactor(TreeNode *node);

// create tree
TreeNode *insertNode(TreeNode *root, int data);

// left rotation
TreeNode *leftRotate(TreeNode *y);

// right rotation
TreeNode *rightRotate(TreeNode *x);

// inorder treewalk
void inOrderWalk(TreeNode *root);

// free tree
void freeTree(TreeNode *root);
