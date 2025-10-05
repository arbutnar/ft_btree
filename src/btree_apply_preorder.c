#include "ft_btree.h"

/* Preorder Traversal is a DFS (Depth-First Search) algo:
    It visits the node first, then left subtree, then right subtree.
    - used to create a copy of the tree.
    - used to get prefix expressions on an expression tree. */
void    btree_apply_preorder(t_btree *root, void (*applyf)(void *)) {
    if (root == NULL)
        return;

    applyf(root->item);
    btree_apply_preorder(root->left, applyf);
    btree_apply_preorder(root->right, applyf);
}
