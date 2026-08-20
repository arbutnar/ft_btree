#include "ft_btree.h"

// Postorder Traversal is a DFS (Depth-First Search) algo:
// it visits the left subtree, then right subtree, then the node.
//  - used to delete the tree.
//  - used to get the postfix expression of an expression tree.
//  - it can help in garbage collection algorithms, particularly in systems where manual memory management is used.
void    btree_apply_postorder(t_btree *root, void (*applyf)(void *)) {
    if (root == NULL)
        return;

    btree_apply_postorder(root->left, applyf);
    btree_apply_postorder(root->right, applyf);
    applyf(root->item);
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

//     btree_apply_postorder(root, multiply);
//     btree_print(root, print_decimal);
// }
