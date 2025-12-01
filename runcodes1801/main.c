#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    int n;
    scanf("%d", &n);

    Tree *root = NULL;

    for (int i = 0; i < n; i++) {
        int new_value;
        scanf("%d", &new_value);

        root = insert_root(root, new_value);
    }

    tree_preorder(root);
    printf("\n");
    tree_inorder(root);
    printf("\n");
    tree_posorder(root);
    printf("\n");

    printf("%d\n", 1 + tree_height(root));

    tree_destroy(root);

    return 0;
}