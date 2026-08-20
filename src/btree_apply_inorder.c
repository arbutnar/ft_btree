#include "ft_btree.h"

// Inorder Traversal is a DFS (Depth-First Search) algo:
// it visits the left subtree, then the node, then right subtree.
//  - used to retrieve the non-decreasing order.
void btree_apply_inorder(t_btree *root, void (*applyf)(void *)) {
    if (root == NULL)
        return;

    btree_apply_inorder(root->left, applyf);
    applyf(root->item);
    btree_apply_inorder(root->right, applyf);
}

// void    multiply(void *item) {
//     printf("multiply item %d\n", *(int *)item );
//     *(int *)item *= 10;
// }

// int main() {
//     int a = 1;
//     int b = 2;
//     int c = 3;
//     int d = 4;
//     int e = 5;
//     int f = 6;
//     int g = 7;

//     t_btree *root = btree_create_node(&a);
//     root->left = btree_create_node(&b);
//     root->right = btree_create_node(&c);
//     root->left->left = btree_create_node(&d);
//     root->left->right = btree_create_node(&e);
//     root->right->left = btree_create_node(&f);
//     root->right->right = btree_create_node(&g);

//     btree_apply_inorder(root, multiply);
//     btree_print(root, print_decimal);
// }
