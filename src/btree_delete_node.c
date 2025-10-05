#include "ft_btree.h"

void    btree_reassemble(t_btree *root, t_btree **new_tree, void *ref_item, int (*cmpf)(void *, void *)) {
    if (root == NULL)
        return;

    if (cmpf(root->item, ref_item) != 0)
        btree_insert_data(new_tree, root->item, cmpf);
    btree_reassemble(root->left, new_tree, ref_item, cmpf);
    btree_reassemble(root->right, new_tree, ref_item, cmpf);
}

void    btree_delete_node(t_btree **root, void *ref_item, int (*cmpf)(void *, void *)) {
    t_btree *new_root = NULL;

    btree_reassemble(*root, &new_root, ref_item, cmpf);
    btree_clear(*root);
    *root = new_root;
}
