#include "ft_btree.h"

/* Postorder Traversal is a DFS (Depth-First Search) algo:
    It visits the left subtree, then right subtree, then the node.
    - used to delete the tree.
    - used to get the postfix expression of an expression tree.
    - it can help in garbage collection algorithms, particularly in systems where manual memory management is used. */
void    btree_apply_postorder(t_btree *root, void (*applyf)(void *)) {
    if (root == NULL)
        return;

    btree_apply_postorder(root->left, applyf);
    btree_apply_postorder(root->right, applyf);
    applyf(root->item);
}
