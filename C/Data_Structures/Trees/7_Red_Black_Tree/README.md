# Red Black Tree In C

- A Red-black tree is a self-balancing binary search tree in which each node contains extra of storage for denoting the color of the node, either Red or Black.

- Ensures that no simple path from root to leaf is more than twice as long as any other so that the tree is approximately balanced.

## Red-Black Properties

1. Every node is either Red or Black 1. Every node is either Red or Black
2. The root is always **Black**.
3. Every leaf `NIL` node is **Black**.
4. If a node is **Red**, then both it's children are **Black**.
5. For each node, all simple paths from the node to descendant leaves `NIL` contains the same number of **Black** nodes.

## File structure

- `rbtree.c` : red-black tree library file
- `rbtree.h` : red-black tree header file
- `rbtree_data.c` : red-black tree data header file
- `rbtree_data.h` : red-black tree data processing library
- `main.c` : example application of red-black tree
- `README.md` : Notes

## Tree and Node Structure

Node structure:

```c
typedef struct rbNode {
  struct rbNode *left;   // left pointer
  struct rbNode *right;  // right pointer
  struct rbNode *parent; // parent pointer
  rbColor color;         // enum color of the node, RED (0) and Black (1)
  void *data;            // generic: tree can store any dtype
} rbNode;
```

Tree Structure:

```c
typedef struct rbTree {
  int (*compare)(const void *, const void *); // comparator like strcmp
  void (*print)(void *);                      // print (optional)
  void (*destroy)(void *);                    // destructor

  rbNode root; // sentinal root (actual data starts at root.left)
  rbNode nil;  // sentinal NIL (leaf nodes, always black)

#ifdef RB_MIN
  rbNode *min; // pointer to minimum node if enable
#endif
} rbTree;

```

The tree maintains two sentinel nodes for efficiency:

- `root` : Sentinel serving as a parent
- `nil` : Sentinel representing leaf nodes
- `min` : pointer to the minimum node (optional, for O(1) lookups)

```text
        NIL
        |
      Root (sentinel)
      /
    Node (root with real data)
  /    \
NIL    NIL

```

## Method overview

| Function                 | Use Cases                                                |
| ------------------------ | -------------------------------------------------------- |
| `rbTreeCreate`           | Initialize a new red-black tree                          |
| `rbTreeDestroy`          | Free the entire tree (calls `destroy` on each data)      |
| `rbTreeFind`             | Search for a node                                        |
| `rbTreeInsert`           | Insert new data                                          |
| `rbTreeDelete`           | Delete a node                                            |
| `rbTreeSuccessor`        | Successor of a given node                                |
| `rbTreeApply`            | Traverse subtree applying a function (PRE/IN/POST order) |
| `rbTreePrint`            | Print the tree                                           |
| `rbTreeCheckOrder`       | Verify BST property                                      |
| `rbTreeCheckBlackHeight` | Verify red-black black-height property                   |

## Insertion and Deletion in Red-Black Trees

We can insert or delete a node in Red-Black tree same as Binary search tree by maintaining the Binary search property (aka order property).

Binary search property states that the key in each node must be greater than or equal to any key stored in the left subtree, and less than or equal to any key in the right subtree.

```
left <= root <= right
```

We then call an auxiliary procedure to preserve the Red-Black properties if violated by recoloring nodes and performing necessary rotations.

**Procedure**

1. If tree is empty, create newnode as rootnode with color black.
2. If tree is not empty, create newnode as leaf node with color Red.
3. If parent of newnode is black, then no recoloring or rotation is needed, exit.
4. If parent of newnode is Red, then check the color of parent's sibling of newnode
   - If node is Black or `NIL` then do suitable rotation & recolor.
   - If color is Red then recolor and also check if parent's parent (grandparent of newnode) is not root node then recolor it & recheck.
