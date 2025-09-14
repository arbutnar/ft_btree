#include "ft_btree.h"

void    btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *)) {
    if (*root == NULL) {
        *root = btree_create_node(item);
        return;
    }
    if (cmpf((*root)->item, item) <= 0)
        btree_insert_data(&(*root)->right, item, cmpf);
    else
        btree_insert_data(&(*root)->left, item, cmpf);

}

// int numcmp(void *item1, void *item2) {
//     return *(int *)item1 - *(int *)item2;
// }

// int main() {
//     t_btree *tree = NULL;

//     int item1 = 4;
//     void *item1_ptr = &item1;
//     btree_insert_data(&tree, item1_ptr, numcmp);
//     int item2 = 2;
//     void *item2_ptr = &item2;
//     btree_insert_data(&tree, item2_ptr, numcmp);
//     int item3 = 1;
//     void *item3_ptr = &item3;
//     btree_insert_data(&tree, item3_ptr, numcmp);
//     int item4 = 3;
//     void *item4_ptr = &item4;
//     btree_insert_data(&tree, item4_ptr, numcmp);
//     int item5 = 5;
//     void *item5_ptr = &item5;
//     btree_insert_data(&tree, item5_ptr, numcmp);

//     btree_print_node(tree);
//     btree_print_node(tree->left);
//     printf("\n");
// }