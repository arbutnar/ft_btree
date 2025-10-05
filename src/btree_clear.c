#include "ft_btree.h"

void    btree_clear(t_btree *root) {
    if (root == NULL)
        return;
    btree_clear(root->left);
    btree_clear(root->right);
    free(root);
}
