#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct tree {
    int value;
    Tree *left;
    Tree *right;
};

/* Cria um nó com valor e filhos dados. Retorna NULL em falha. */
Tree* tree_create(int value, Tree *left, Tree *right) {
    Tree *root = malloc(sizeof(Tree));

    if (root == NULL)
        return NULL;

    root->value = value;
    root->left = left;
    root->right = right;

    return root;
}

/* Libera toda a árvore recursivamente. Aceita NULL. */
void tree_destroy(Tree *root) {
    if (root == NULL)
        return;

    tree_destroy(root->left);
    tree_destroy(root->right);
    free(root);
}

/* Retorna 1 se vazia, 0 caso contrário. */
int tree_is_empty(Tree *root) {
    return (root == NULL);
}

/* Retorna o número de nós. */
int tree_size(Tree *root) {
    if (root == NULL)
        return 0;

    return 1 + tree_size(root->left) + tree_size(root->right);
}

/* Retorna a altura. Convenção: vazia = -1, folha = 0. */
int tree_height(Tree *root) {
    if (root == NULL)
        return -1;

    int left_height = 1 + tree_height(root->left);
    int right_height = 1 + tree_height(root->right);

    if (left_height > right_height)
        return left_height;
    else
        return right_height;
}

/* Percursos em profundidade com impressão em stdout. */
void tree_preorder(Tree *root) {  /* raiz, esquerda, direita */
    if (root == NULL)
        return;

    printf("%d ", root->value);
    tree_preorder(root->left);
    tree_preorder(root->right);
}

void tree_inorder(Tree *root) {   /* esquerda, raiz, direita */
    if (root == NULL)
        return;

    tree_inorder(root->left);
    printf("%d ", root->value);
    tree_inorder(root->right);
}

void tree_posorder(Tree *root) {  /* esquerda, direita, raiz */
    if (root == NULL)
        return;

    tree_posorder(root->left);
    tree_posorder(root->right);
    printf("%d ", root->value);
}

/* Percurso em largura com impressão em stdout. */
void tree_width(Tree *root) {
    if (root == NULL)
        return;

    Tree **queue = malloc(tree_size(root) * sizeof(Tree *));
    if (queue == NULL)
        return;

    int front = 0, back = 0;

    queue[back] = root;
    back++;

    while (front < back) {
        Tree *current = queue[front];
        front++;

        printf("%d ", current->value);

        if (current->left != NULL) {
            queue[back] = current->left;
            back++;
        }
        if (current->right != NULL) {
            queue[back] = current->right;
            back++;
        }
    }

    free(queue);
}

/* Inserir em árvore binária de busca */
Tree* insert_root(Tree *root, int value) {
    if (root == NULL) {
        Tree *new_root = tree_create(value, NULL, NULL);
        return new_root;
    }

    if (value < root->value) {
        root->left = insert_root(root->left, value);
    } else if (value > root->value) {
        root->right = insert_root(root->right, value);
    }

    return root;
}