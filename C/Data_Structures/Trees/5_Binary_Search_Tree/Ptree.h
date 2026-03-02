/* Create binary search tree node*/
typedef struct treenode {
  int data;                // data part
  struct treenode *parent; // pointer to parent node
  struct treenode *left;   // pointer to left nodes
  struct treenode *right;  // pointer to right nodes
} TreeNode;

/* initialize the node */
TreeNode *init_node(TreeNode *parent, int data);

/* insert node in BST */
TreeNode *insert(TreeNode *root, TreeNode *parent, int key);

/* traverse tree using In-Order Treewalk */
void in_order(TreeNode *root);

/* free tree nodes to save memory */
void free_tree(TreeNode *root);
