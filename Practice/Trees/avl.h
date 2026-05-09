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
int getBalanceFactor(const TreeNode *);
TreeNode *findPredecessor(TreeNode *);
TreeNode *leftRotate(TreeNode *);
TreeNode *rightRotate(TreeNode *);
TreeNode *insertNode(TreeNode *, int);
TreeNode *deleteNode(TreeNode *, int);
void inOrderWalk(const TreeNode *);
void freeTree(TreeNode *);
