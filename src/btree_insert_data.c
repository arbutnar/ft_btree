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
//     btree_insert_data(&tree, &item1, numcmp);
//     int item2 = 2;
//     btree_insert_data(&tree, &item2, numcmp);
//     int item3 = 1;
//     btree_insert_data(&tree, &item3, numcmp);
//     int item4 = 3;
//     btree_insert_data(&tree, &item4, numcmp);
//     int item5 = 5;
//     btree_insert_data(&tree, &item5, numcmp);

//     btree_print(tree, print_decimal);
// }
