# Red Black Tree In C

- A Red-black tree is a self-balancing binary search tree in which each node contains extra of storage for denoting the color of the node, either Red or Black.

- Ensures that no simple path from root to leaf is more than twice as long as any other so that the tree is approximately balanced.

## Red-Black Properties

1. Every node is either Red or Black 1. Every node is either Red or Black
2. The root is always **Black**.
3. Every leaf `NIL` node is **Black**.
4. If a node is **Red**, then both it's children are **Black**.
5. For each node, all simple paths from the node to descendant leaves `NIL` contains the same number of **Black** nodes.

## Insertion and Deletion in Red-Black Trees

We can insert or delete a node in Red-Black tree same as Binary search tree by maintaining the Binary search property (aka order property).

Binary search property states that the key in each node must be greater than or equal to any key stored in the left subtree, and less than or equal to any key in the right subtree.

```
left <= root <= right
```

We then call an auxiliary procedure to preserve the Red-Black properties if violated by recoloring nodes and performing necessary rotations.

## Insertion

While inserting a new node, it is always inserted as a **Red** node. After insertion of a newnode, if the tree is violating the properties of the Red Black tree then we perform recoloring and rotation operations.

### Insertion in simple binary search tree

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

Procedure:

-
