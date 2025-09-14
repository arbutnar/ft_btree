#include "ft_btree.h"

/* Uses of Postorder Traversal
- gives nodes in non-decreasing order.
*/
void btree_inorder_traversal_apply(t_btree *root, void (*applyf)(void *)) {
    if (root == NULL)
        return;
    btree_inorder_traversal_apply(root->left, applyf);
    applyf(root->item);
    btree_inorder_traversal_apply(root->right, applyf);
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

//     btree_inorder_traversal_apply(root, multiply);
//     printf("\n\n");

//     btree_print_node(root);
//     btree_print_node(root->left);
//     btree_print_node(root->right);
//     printf("\n");
// }