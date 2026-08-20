#include "ft_btree.h"

void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
    int cmp;

    if (root == NULL)
        return NULL;
    cmp = cmpf(root->item, data_ref);
    if (cmp == 0)
        return root->item;
    if (cmp <= 0)
        return btree_search_item(root->right, data_ref, cmpf);
    return btree_search_item(root->left, data_ref, cmpf);
}
