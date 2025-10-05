#include "ft_btree.h"

int     btree_level_count(t_btree *root) {
    int left = 0, right = 0;

    if (root == NULL)
        return (left > right) ? left : right;
    left = btree_level_count(root->left) + 1;
    right = btree_level_count(root->right) + 1;
    return (left > right) ? left : right;
}
