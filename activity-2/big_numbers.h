/*  ===========================================================================
    |    TRABALHO 2 -ALGORTIMOS E ESTRUTURAS DE DADOS - NÚMEROS ASTRONÔMICOS  |
    |       Renan Silva Blasques                - NUSP:  9784057              |
    |       Rodrigo De Jesus Ferreira Gonçalves - NUSP: 16899823              |
    ===========================================================================   */

#ifndef BIG_NUMBERS_H
#define BIG_NUMBERS_H

#include "linked_list.h"

// Define o tipo opaco BigSum
typedef struct BigNum BigNum;

/* 
    Função para criar o grande número
    Recebe o número (string) e o número de dígitos
    Retorna o número criado ou nulo em caso de falha
*/
BigNum* bignum_create(const char *number, int size);

/* 
    Função para somar dois grandes números
    Recebe os dois números que serão somados (n1 >= n2)
    Retorna a subtração dos números ou nulo em caso de falha
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

// ======================= Funções Auxiliares =======================

/* 
    Função auxiliar de subtração dos módulos
    Recebe os dois números 
    Retorna o número criado ou nulo em caso de falha
*/
BigNum* bignum_sub_abs(const BigNum *n1, const BigNum *n2);

/* 
    Função auxiliar de comparar valores absolutos dos números
    Recebe os dois números e compara o tamanho dos dois (sem sinal)
    Retorna 0 se |n1| = |n2|, 1 se |n1| > |n2| ou 2 se |n1 < n2|
*/
int bignum_compare_abs(const BigNum *n1, const BigNum *n2);

#endif