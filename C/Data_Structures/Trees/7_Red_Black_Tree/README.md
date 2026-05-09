```text
            root
          /     \
      parent    parent's sibling (Grandparent of current)
      /    \
  current   NIL
  /     \
NIL     NIL

```

- Grandparent : Parent's parent `x->parent->parent`.
- Uncle : Sibling of parent
  - if parent is left-child of Grandparent then uncle is `x->parent->parent->right`
  - if parent is right-child of Grandparent then uncle is `x->parent->parent->left`
