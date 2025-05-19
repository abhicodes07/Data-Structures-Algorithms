# Steps for implementation of iterative post-order traversal using stack

1. **Initialization**:

- Set a pointer `curr` to the tree's root.
- Create an empty stack `st`.
- Prepare an empty list `post_order` to hold the post-order result.

2. **Traverse Down the Left Subtree:**

- While `curr` is not null, push `curr` onto the stack.
- Move `curr` to its left child.
  (This continues until you hit a null, meaning you've reached the leftmost node.)

3. **Backtracking and Processing:**

- When `curr` becomes null (i.e., there’s no further left child), peek at the node on top of the stack.
- Set a temporary pointer `temp` to the right child of the node at the top of the stack.

4. **Deciding the Next Step:**

- _If `temp` is null_:

  - The top node (from the stack) has no right child, so it can be processed now.
  - Pop this node from the stack and add its value to the `post_order` result.
  - Next, check if the popped node is the right child of the new stack top. If it is, continue to pop and process nodes until either the stack is empty or the current node is not the right child of the top node.

- _If temp is not null:_
  - This means there is a right subtree that hasn’t been processed yet.
  - Set `curr` to temp to begin processing that right subtree.

5. **Loop Continuation:**

- Continue the entire process (steps 2–4) as long as either `curr` is not null or the stack is not empty.

6. **Completion:**

- When both `curr` is null and the stack is empty, the list post_order contains the tree nodes in post-order sequence.
