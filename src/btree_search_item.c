#include "ft_btree.h"

void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
    if (root == NULL)
        return NULL;
    printf("%d\n", *(int*)root->item);
    if (btree_search_item(root->left, data_ref, cmpf) == NULL) {
        if (cmpf(root->item, data_ref) == 0)
            return root->item;
        btree_search_item(root->right, data_ref, cmpf);
    }
}

// int numcmp(void *item1, void *item2) {
//     return *(int *)item1 - *(int *)item2;
// }

// int main() {
//     t_btree *tree = NULL;
//     int     items[] = {6,4,2,3,1,0,8,9,7};

//     for (int i = 0; i < sizeof(items) / sizeof(int); i++) {
//         void *item_ptr = &items[i];
//         btree_insert_data(&tree, item_ptr, numcmp);
//     }

//     print_subtree(tree, " ", " ", print_buff, sizeof(print_buff));
//     int item0 = 93;
//     void *item0_ptr = &item0;
//     void *found = btree_search_item(tree, item0_ptr, numcmp);
//     if (found) printf("%d\n", *(int*)found); else printf("(nil)\n");
//     printf("\n");
// }