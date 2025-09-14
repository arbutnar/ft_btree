#include "ft_btree.h"

/* Uses of Postorder Traversal
- to create a copy of the tree.
- to get prefix expressions on an expression tree.
*/
void    btree_preorder_traversal_apply(t_btree *root, void (*applyf)(void *)) {
    if (root == NULL)
        return;
    applyf(root->item);
    btree_preorder_traversal_apply(root->left, applyf);
    btree_preorder_traversal_apply(root->right, applyf);
}

// void    multiply(void *item) {
//     *(int *)item *= 10;
// }

// int main() {
//     int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7;
//     t_btree *root = btree_create_node(&a);
//     root->left = btree_create_node(&b);
//     root->right = btree_create_node(&c);
//     root->left->left = btree_create_node(&d);
//     root->left->right = btree_create_node(&e);
//     root->right->left = btree_create_node(&f);
//     root->right->right = btree_create_node(&g);

//     btree_print_node(root);
//     btree_print_node(root->left);
//     btree_print_node(root->right);
//     printf("\n");

//     btree_preorder_traversal_apply(root, multiply);
//     btree_print_node(root);
//     btree_print_node(root->left);
//     btree_print_node(root->right);
//     printf("\n");
// }