#ifndef BIG_NUMBERS_H
#define BIG_NUMBERS_H

#include "linked_list.h"

/* 
    Função para criar o grande número
    Recebe o número (string) e o número de dígitos
    Retorna o número criado ou nulo em caso de falha
*/
LinkedList* bignum_create(const char *number, int size);

/* 
    Função para somar dois grandes números
    Recebe os dois números que serão somados
    Retorna a soma dos números ou nulo em caso de falha
*/
LinkedList* bignum_sum(const LinkedList *n1, const LinkedList *n2);

#endif
