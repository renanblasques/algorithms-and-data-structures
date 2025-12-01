#ifndef TREE_H
#define TREE_H

/* TAD Árvore binária como ponteiro opaco */
typedef struct tree Tree;

/* Cria um nó com valor e filhos dados. Retorna NULL em falha. */
Tree* tree_create(int value, Tree *left, Tree *right);

/* Libera toda a árvore recursivamente. Aceita NULL. */
void tree_destroy(Tree *root);

/* Retorna 1 se vazia, 0 caso contrário. */
int tree_is_empty(Tree *root);

/* Retorna o número de nós. */
int tree_size(Tree *root);

/* Retorna a altura. Convenção: vazia = -1, folha = 0. */
int tree_height(Tree *root);

/* Percursos em profundidade com impressão em stdout. */
void tree_preorder(Tree *root);  /* raiz, esquerda, direita */
void tree_inorder(Tree *root);   /* esquerda, raiz, direita */
void tree_posorder(Tree *root);  /* esquerda, direita, raiz */

/* Percurso em largura com impressão em stdout. */
void tree_width(Tree *root);

/* Inserir em árvore binária de busca */
Tree* insert_root(Tree *root, int value);

#endif