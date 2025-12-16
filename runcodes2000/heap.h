#ifndef HEAP_H
#define HEAP_H

// Tipo opaco que representa uma max-heap
typedef struct heap Heap;

// Cria uma heap vazia com capacidade máxima informada e retorna seu ponteiro
Heap *heap_create(int max_cap);

// Libera toda a memória associada à heap e seta o ponteiro para NULL
void heap_destroy(Heap **h);

// Insere um novo valor na heap e retorna 1 em caso de sucesso ou 0 em erro
int heap_insert(Heap *h, int value);

// Remove o maior elemento da heap guardando em removido e retorna 1 em caso de sucesso
int heap_remove_max(Heap *h, int *removed);

// Consulta o maior elemento da heap sem removê-lo guardando em maximo e retornando 1 em sucesso
int heap_max(Heap *h, int *max);

// Retorna 1 se a heap está vazia ou 0 caso contrário
int heap_is_empty(Heap *h);

// Retorna 1 se a heap está cheia ou 0 caso contrário
int heap_is_full(Heap *h);

// Retorna a quantidade atual de elementos armazenados na heap
int heap_size(Heap *h);

// Retorna a capacidade máxima de elementos que a heap suporta
int heap_capacity(Heap *h);

#endif /* HEAP_H */

