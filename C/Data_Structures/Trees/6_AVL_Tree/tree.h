// create treenode
typedef struct treenode {
  int data;
  int height;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

// initialize treenode
TreeNode *initNode(int);

// get height
int getHeight(const TreeNode *);

// get maximum of height between left and right
int max(int, int);

// update height
void updateHeight(TreeNode *);

// get balance factor
int getBalanceFactor(TreeNode *);

// left rotation
TreeNode *leftRotate(TreeNode *);

// right rotation
TreeNode *rightRotate(TreeNode *);

// create tree
TreeNode *insertNode(TreeNode *, int);

// inorder treewalk
void inOrderWalk(const TreeNode *);

// free tree
void freeTree(TreeNode *);
