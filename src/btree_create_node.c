#include "ft_btree.h"

t_btree *btree_create_node(void *item) {
    t_btree *new_node;

    new_node = calloc(1, sizeof(t_btree));
    new_node->item = item;

    return new_node;
}

// int main() {
//     t_btree *node;
//     int     item, *item_ptr;

//     item = 3;
//     item_ptr = &item;
//     node = btree_create_node(item_ptr);
//     btree_print_node(node);
// }
