/* Create binary search tree node*/
#include <cstdlib>
typedef struct treenode {
  int data;               // data part
  struct treenode *left;  // pointer to left nodes
  struct treenode *right; // pointer to right nodes
} TreeNode;

/* initialize the node */
TreeNode *initNode(int data);

/* create tree */
void create_binary_search_treee(TreeNode *root);
