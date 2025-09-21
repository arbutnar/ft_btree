#include "ft_btree.h"
#include "ft_list.h"

void    apply_by_level(t_list *begin_list, int current_level, void (*applyf)(void *item, int current_level, int is_first_elem)) {
    t_list  *next_list = NULL;
    t_list  *current = begin_list;
    int     is_first_elem = 1;

    while (current) {
        applyf(((t_btree*)current->data)->item, current_level, is_first_elem);
        if (((t_btree*)current->data)->left)
            ft_list_push_back(&next_list, ((t_btree*)current->data)->left);
        if (((t_btree*)current->data)->right)
            ft_list_push_back(&next_list, ((t_btree*)current->data)->right);

        is_first_elem = 0;
        current = current->next;
    }
    ft_list_clear(begin_list, NULL);

    if (next_list)
        apply_by_level(next_list, ++current_level, applyf);
}

void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)) {
    t_list  *list = NULL;
    int     current_level = 0;

    applyf(root->item, current_level, 1);
    ft_list_push_back(&list, root->left);
    ft_list_push_back(&list, root->right);

    apply_by_level(list, ++current_level, applyf);
    ft_list_clear(list, NULL);
}

// void    print(void *item, int current_level, int is_first_elem) {
//     printf("item=%d, current_level=%d, is_first_elem=%d\n", *(int *)item, current_level, is_first_elem);
// }

// int numcmp(void *item1, void *item2) {
//     return *(int *)item1 - *(int *)item2;
// }

// int main() {
//     t_btree *tree = NULL;
//     int     items[] = {5,4,2,3,8,7,6,9};

//     for (unsigned int i = 0; i < sizeof(items) / sizeof(int); i++) {
//         void *item_ptr = &items[i];
//         btree_insert_data(&tree, item_ptr, numcmp);
//     }

//     print_subtree(tree, " ", " ", print_buff, sizeof(print_buff));
//     btree_apply_by_level(tree, print);
// }