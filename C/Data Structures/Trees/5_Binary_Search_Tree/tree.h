/* Create binary search tree node*/
typedef struct treenode {
  int data;               // data part
  struct treenode *left;  // pointer to left nodes
  struct treenode *right; // pointer to right nodes
} TreeNode;

/* initialize the node */
TreeNode *initNode(int data);

/* insert node in BST */
TreeNode *insert(TreeNode *root, int key);

/* traverse tree using In-Order Treewalk */
void in_order(TreeNode *root);

/* free tree nodes to save memory */
void freeTree(TreeNode *root);
