#include <ft_btree.h>

char    print_buff[1024];

void    btree_print(t_btree *root, char *prf_right, char *prf_left, char *buf, int buf_sz) {
    if (root->right) {
        int res = snprintf(buf, buf_sz, "%s", prf_right);
        btree_print(root->right, "  ", "| ", buf + res, buf_sz - res);
        *buf = '\0';
    }
    printf("%s+-%d\n", print_buff, *(int*)root->item);
    if (root->left) {
        int res = snprintf(buf, buf_sz, "%s", prf_left);
        btree_print(root->left, "| ", "  ", buf + res, buf_sz - res);
        *buf = '\0';
    }
}
