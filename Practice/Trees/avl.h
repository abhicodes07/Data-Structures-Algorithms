// create treenode
typedef struct treenode {
  int data;
  int height;
  struct treenode *left;
  struct treenode *right;
} TreeNode;

TreeNode *initNode(int);
int getHeight(const TreeNode *);
void updateHeight(TreeNode *);
int max(int, int);
int getBalanceFactor(TreeNode *);
TreeNode *leftRotate(TreeNode *);
TreeNode *rightRotate(TreeNode *);
TreeNode *insertNode(TreeNode *, int);
void inOrderWalk(const TreeNode *);
void freeTree(TreeNode *);
