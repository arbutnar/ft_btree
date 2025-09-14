#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_btree {
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
} t_btree;

extern char    print_buff[1024];

t_btree *btree_create_node(void *item);
void    btree_preorder_traversal_apply(t_btree *root, void (*applyf)(void *));
void    btree_inorder_traversal_apply(t_btree *root, void (*applyf)(void *));
void    btree_postorder_traversal_apply(t_btree *root, void (*applyf)(void *));
void    btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int     btree_level_count(t_btree *root);
void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

void    print_subtree(t_btree *root, char *prf_right, char *prf_left, char *buf, int buf_sz);

#endif