#include "ft_btree.h"

int     btree_level_count(t_btree *root) {
    int left = 0, right = 0;

    if (root == NULL)
        return (left > right) ? left : right;
    printf("left = %d, right=%d\n", left, right);
    left = btree_level_count(root->left) + 1;
    right = btree_level_count(root->right) + 1;
    return (left > right) ? left : right;
}

// int numcmp(void *item1, void *item2) {
//     return *(int *)item1 - *(int *)item2;
// }

// int main() {
//     t_btree *tree = NULL;
//     int     items[] = {6,4,2,3};

//     for (int i = 0; i < sizeof(items) / sizeof(int); i++) {
//         void *item_ptr = &items[i];
//         btree_insert_data(&tree, item_ptr, numcmp);
//     }

//     print_subtree(tree, " ", " ", print_buff, sizeof(print_buff));
//     int level = btree_level_count(tree);
//     printf("%d\n", level);
// }