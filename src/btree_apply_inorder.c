#include "ft_btree.h"

/* Inorder Traversal is a DFS (Depth-First Search) algo:
    It visits the left subtree, then the node, then right subtree.
    - used to retrieve the non-decreasing order. */
void btree_apply_inorder(t_btree *root, void (*applyf)(void *)) {
    if (root == NULL)
        return;

    btree_apply_inorder(root->left, applyf);
    applyf(root->item);
    btree_apply_inorder(root->right, applyf);
}
