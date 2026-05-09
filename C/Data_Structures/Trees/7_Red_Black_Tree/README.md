```text
            root
          /     \
      parent    parent's sibling (uncle of current)
      /    \
  current   NIL
  /     \
NIL     NIL

```

- Grandparent : Parent's parent `current->parent->parent`.
- Uncle : Sibling of parent
  - if parent is left-child of Grandparent then uncle is `current->parent->parent->right`
  - if parent is right-child of Grandparent then uncle is `current->parent->parent->left`
