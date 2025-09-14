#include "ft_btree.h"

void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)) {
    
}

int numcmp(void *item1, void *item2) {
    return *(int *)item1 - *(int *)item2;
}

int main() {
    t_btree *tree = NULL;
    int     items[] = {6,4,2,3};

    for (int i = 0; i < sizeof(items) / sizeof(int); i++) {
        void *item_ptr = &items[i];
        btree_insert_data(&tree, item_ptr, numcmp);
    }

    print_subtree(tree, " ", " ", print_buff, sizeof(print_buff));
    int level = btree_level_count(tree);
    printf("%d\n", level);
}