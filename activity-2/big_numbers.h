#ifndef BIG_NUMBERS_H
#define BIG_NUMBERS_H

#include "linked_list.h"

// Apenas troca o nome da lista encadeada para BigSum
// para melhorar legibilidade do código
typedef LinkedList BigNum;

/* 
    Função para criar o grande número
    Recebe o número (string) e o número de dígitos
    Retorna o número criado ou nulo em caso de falha
*/
BigNum* bignum_create(const char *number, int size);

/* 
    Função para somar dois grandes números
    Recebe os dois números que serão somados
    Retorna a soma dos números ou nulo em caso de falha
*/
BigNum* bignum_sum(const BigNum *n1, const BigNum *n2);

/* 
    Função para comparar dois grandes números
    Recebe os dois números que serão comparados
    Retorna 0 se n1 = n2, 1 se n1 > n2 ou 2 se n1 < n2
    Retorna -1 se houve algum erro
*/
int bignum_compare(const BigNum *n1, const BigNum *n2);

/* 
    Função para imprimir um grande número
    Recebe o número e imprime com stdout
    Retorna 1 se imprimiu ou 0 se não há nada para imprimir
    Retorna -1 se houve algum erro
*/
int bignum_print(const BigNum *n);

/*
    Função para liberar o grande número da memória
    Mesma função que linked_list_free
*/
void bignum_destroy(BigNum **n);

#endif