#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "../ft_list/ft_list.h"

typedef struct s_btree {
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
} t_btree;

extern char    print_buff[1024];

t_btree *btree_create_node(void *item);
void    btree_apply_preorder(t_btree *root, void (*applyf)(void *));
void    btree_apply_inorder(t_btree *root, void (*applyf)(void *));
void    btree_apply_postorder(t_btree *root, void (*applyf)(void *));
void    btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int     btree_level_count(t_btree *root);
void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
void    btree_delete_node(t_btree **root, void *ref_item, int (*cmpf)(void *, void *));

void    btree_clear(t_btree *root);
void    btree_print(t_btree *root, char *prf_right, char *prf_left, char *buf, int buf_sz);

#endif