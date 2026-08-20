#include "ft_btree.h"

#define BTREE_PRINT_INDENT 4

void print_decimal(void *item) {
    printf("%d\n", *(int *)item);
}

void print_character(void *item) {
    printf("%c\n", *(char *)item);
}

void print_string(void *item) {
    printf("%s\n", (char *)item);
}

static void btree_print_rec(t_btree *root, void (*applyf)(void*), int depth) {
    if (root == NULL)
        return;

    btree_print_rec(root->right, applyf, depth + 1);
    printf("%*s", depth * BTREE_PRINT_INDENT, "");
    applyf(root->item);
    btree_print_rec(root->left, applyf, depth + 1);
}

void btree_print(t_btree *root, void (*applyf)(void *)) {
    btree_print_rec(root, applyf, 0);
}
