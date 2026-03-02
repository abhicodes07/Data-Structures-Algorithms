# Finding Successor of key in BST

- In a BST, successor of a node with key `x` is the node with the smallest key that is greater than x.
- If represents the next node in the In-order traversal of the BST.
- If no such node exists (eg, if `x` is the maximum key in the tree), then successor is typically considered as NULL or undefined.

## Cases

- If the node has a right subtree, the successor is the minimum node (leftmost leaf) in that right subtree or _the smallest element from the right subtree_.

- If the node has no right subtree, traverse upwards to the nearest ancestor (parent) where the _current subtree is a left child of that ancestor_. That ancestor is the successor.

# Finding Predecessor of key in BST

- In a BST, Predecessor of a node with key `x` is the node with the largest key that is greater than x.
- If represents the previous node in the In-order traversal of the BST.
- If no such node exists (eg, if `x` is the minimum key in the tree), then predecessor is typically considered as NULL or undefined.

## Cases

- If the node has a left subtree, the predecessor is the maximum node (leftmost leaf) in that left subtree.

- If the node has no left subtree, traverse upwards to the nearest ancestor (parent) where the _current subtree is a right child of that ancestor_. That ancestor is the predecessor.
