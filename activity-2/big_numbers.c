/*  ===========================================================================
    |    TRABALHO 2 -ALGORTIMOS E ESTRUTURAS DE DADOS - NÚMEROS ASTRONÔMICOS  |
    |       Renan Silva Blasques                - NUSP:  9784057              |
    |       Rodrigo De Jesus Ferreira Gonçalves - NUSP: 16899823              |
    ===========================================================================   */

#include <stdio.h>
#include <stdlib.h>
#include "big_numbers.h"

// Define o tipo BigNum
typedef struct BigNum {
    LinkedList *digits; // Lista encadeada para os dígitos
    int sign;           // Sinal para o grande número
} BigNum;

BigNum* bignum_create(const char number[], int size) {
    // Verifica se o número recebido existe
    // Caso não exista, já retorna nulo
    if (number == NULL)
        return NULL;

    // Verifica se o tamanho do número recebido é valido
    // Caso não seja, já retorna nulo
    if (size <= 0)
        return NULL;

    // Define o sinal do número inicialmente como positivo e
    // e o "começo" da string como o primeiro char
    // Obs: sign = 1 para positivo, sign = -1 para negativo
    int sign = 1, start = 0;

    // Verifica o sinal do número recebido
    if (number[0] == '-') {

        // Defino o sinal como negativo e o "começo" da string
        // é no segundo char da string
        sign = -1;
        start = 1;

        // Verifica se veio só um '-'
        if (size == 1)
            return NULL;
    }

    // Cria o número astronômico
    // Verifica se a função alocou memória para o número
    // Em caso de falha, já retorna nulo
    BigNum *n = malloc(sizeof(BigNum));
    if (n == NULL)
        return NULL;

    // Mesma coisa para a lista encadeada
    // Se houver erro desaloca o número alocado anteriormente
    n->digits = linked_list_create();
    if (n->digits == NULL) {
        free(n);
        return NULL;
    }

    // Atribui o sinal para o grande número
    n->sign = sign;

    // Define o número real de dígitos (funciona para + ou -)
    int num_digits = size - start;

    // i: "Ponteiro" para criar os nós da lista n (incrementa)
    // j: "Ponteiro" para pegar os dígitos do número (number) recebido (decrementa)
    int i = 0;
    int j = size - 1;

    // Loop para inserir os dígitos na lista encadeada
    for (i = 0; i < num_digits; i++) {

        // Verifica se é digito
        // Caso não seja, desaloca n->digits, n e retorna nulo
        if ((number[j] < '0') || (number[j] > '9')) {
            linked_list_free(&(n->digits));
            free(n);
            return NULL;
        }

        // Converte o dígito do número recebido (char) para int
        int digit = number[j] - '0';

        // Insere o dígito convertido de number na i-ésima posição da lista n (número astronômico)
        linked_list_insert_node(n->digits, i, digit);
        j--;
    }

    // Loop para remover os zeros à esquerda
    // Note que k vai até 1, pois o número pode ser 0
    for (int k = num_digits - 1; k >= 1; k--) {
        // Cria o dígito para verificação
        int digit;

        // Busca o dígito no k-ésimo nó
        linked_list_get_node(n->digits, k, &digit);

        // Caso o dígito seja um zero (à esquerda), remove da lista
        // Caso contrário, encerra o loop para não remover zeros do meio
        if (digit == 0)
            linked_list_remove_node(n->digits, k, NULL);
        else
            break;
    }

    // Por último, se o número for -0, remove o sinal
    if (linked_list_size(n->digits) == 1) {

        int unique_digit;
        linked_list_get_node(n->digits, 0, &unique_digit);

        if (unique_digit == 0)
            n->sign = 1;
    }

    // Se chegou até aqui, a lista foi preenchida com os dígitos corretamente
    // Retorna o número astronômico criado
    return n;
}

BigNum* bignum_sum(const BigNum *n1, const BigNum *n2) {
    // Verifica se n1 e n2 existem
    if (n1 == NULL || n2 == NULL)
        return NULL;

    // Verifica se os dois números para a soma são positivos
    if (n1->sign != 1 || n2->sign != 1)
        return NULL;

    // Armazena a quantidade de dígitos de n1 e n2
    int size_n1 = linked_list_size(n1->digits);
    int size_n2 = linked_list_size(n2->digits);

    // Armazena a maior quantidade de dígitos em max_size
    int max_size;

    if (size_n1 > size_n2)
        max_size = size_n1;
    else
        max_size = size_n2;

    // Cria o número sum que guardará a soma de n1 e n2
    // Se a memória não foi alocada, retorna nulo
    BigNum *sum = malloc(sizeof(BigNum));
    if (sum == NULL)
        return NULL;

    // Cria a lista encadeada do número sum (sum->digits)
    // Se a memória não foi alocada, desaloca sum e retorna nulo
    sum->digits = linked_list_create();
    if (sum->digits == NULL) {
        free(sum);
        return NULL;
    }

    // Define o sinal sempre positivo (para evitar lixo na memória)
    sum->sign = 1;

    // Cria o carry inicial valendo 0 (para a primeira soma)
    int carry = 0;

    // Cria as variáveis para realizar a soma
    int n1_digit, n2_digit, sum_digit;

    for (int i = 0; i < max_size; i++) {

        // Pega dígito de n1 se o i-ésimo dígito de n1 existir
        if (i < size_n1)
            linked_list_get_node(n1->digits, i, &n1_digit);

        // Caso contrário, se o dígito não existir, assume 0 para a soma
        else
            n1_digit = 0;

        // Pega dígito de n2 se o i-ésimo dígito de n2 existir
        if (i < size_n2)
            linked_list_get_node(n2->digits, i, &n2_digit);

        // Caso contrário, se o dígito não existir, assume 0 para a soma
        else
            n2_digit = 0;

        // Realiza a soma dos dígitos e o carry
        sum_digit = n1_digit + n2_digit + carry;

        // Se os dígitos somados ultrapassarem 9, subtrai 10 do dígito
        // e manda esse valor para o carry (carry = 1)
        if (sum_digit >= 10) {
            sum_digit -= 10;
            carry = 1;

        // Caso contrário, apenas define carry = 0
        } else {
            carry = 0;
        }

        // Insere resultado da soma dos dígitos em sum
        linked_list_insert_node(sum->digits, i, sum_digit);

        // Processo repete para o próximo dígito
        // ou apenas termina se for o último
    }

    // Se terminou o loop com carry = 1, adiciona um dígito extra em sum
    if (carry == 1)
        linked_list_insert_node(sum->digits, max_size, carry);
    
    // Se chegou até aqui, o número sum foi somado e já pode retornar
    return sum;
}


int bignum_compare(const BigNum *n1, const BigNum *n2) {
    // Verifica se n1 e n2 existem
    if ((n1 == NULL) || (n2 == NULL))
        return -1;

    // Inicialmente, compara pelo sinal
    if (n1->sign > n2->sign)
        // n1 é maior que n2
        return 1;

    if (n1->sign < n2->sign)
        // n1 é menor que n2
        return 2;

    // Se chegou até aqui, ambos possuem o mesmo sinal
    int both_sign = n1->sign;

    // Obtém a quantidade de dígitos de cada número
    int n1_size = linked_list_size(n1->digits);
    int n2_size = linked_list_size(n2->digits);

    // Verifica agora o tamanho dos dígitos baseado no sinal
    // Se ambos são positivos (mais dígitos -> maior)
    if (both_sign == 1) {
        if (n1_size > n2_size)
            // n1 é maior que n2
            return 1;
    
        if (n1_size < n2_size)
            // n1 é menor que n2
            return 2;
    }

    // Se ambos são negativos, a lógica se inverte (mais dígitos -> menor)
    if (both_sign == -1) {
        if (n1_size < n2_size)
            // n1 é maior que n2
            return 1;
    
        if (n1_size > n2_size)
            // n1 é menor que n2
            return 2;
    }

    // Se chegou aqui, possuem número de dígitos iguais
    // Verificar dígito a dígito

    // Cria as variáveis para a lógica de verificação
    int greater = 0, n1_digit, n2_digit;

    // Percorre as listas paralelamente, dígito a dígito,
    // do mais significativo para o menos significativo

    // Se ambos forem positivos:
    if (both_sign == 1) {

        for (int i = n1_size - 1; i >= 0; i--) {

            // Obtém os i-ésimos dígitos de n1 e n2 e armazena
            // em n1_digit e n2_digit, respectivamente
            linked_list_get_node(n1->digits, i, &n1_digit);
            linked_list_get_node(n2->digits, i, &n2_digit);

            // Se os dígitos forem iguais, recomeça o loop para o dígito
            // menos significativo que o atual
            if (n1_digit == n2_digit)
                continue;

            // Se o dígito de n1 for maior, ele é maior
            else if (n1_digit > n2_digit)
                greater = 1;

            // Se o dígito de n1 for menor, ele é menor
            else
                greater = 2;

            // Se chegou aqui, os dígitos são diferentes, logo já se
            // sabe qual é o maior e pode encerrar o loop.
            break;
        }

    // Se ambos forem negativos:
    } else if (both_sign == -1) {

        for (int i = n1_size - 1; i >= 0; i--) {

            // Obtém os i-ésimos dígitos de n1 e n2 e armazena
            // em n1_digit e n2_digit, respectivamente
            linked_list_get_node(n1->digits, i, &n1_digit);
            linked_list_get_node(n2->digits, i, &n2_digit);

            // Se os dígitos forem iguais, recomeça o loop para o dígito
            // menos significativo que o atual
            if (n1_digit == n2_digit)
                continue;

            // Se o dígito de n1 for menor, ele é maior (inverte)
            else if (n1_digit < n2_digit)
                greater = 1;

            // Se o dígito de n1 for maior, ele é menor (inverte)
            else
                greater = 2;

            // Se chegou aqui, os dígitos são diferentes, logo já se
            // sabe qual é o maior e pode encerrar o loop.
            break;
        }
    }
    
    // Retorna a variável que indica qual caso chegou.
    return greater;
}

int bignum_print(const BigNum *n) {
    // Antes de tudo, verifica se o número existe
    if (n == NULL)
        return -1;

    // Se a lista existe, verifica também se está vazia
    if (linked_list_is_empty(n->digits))
        return 0;

    // Obtém o número de dígitos do número
    int n_size = linked_list_size(n->digits);
    int digit;
    
    // Percorre a lista do final para o começo e imprime cada dígito
    for (int i = n_size - 1; i >= 0; i--) {
        linked_list_get_node(n->digits, i, &digit);
        printf("%d", digit);
    }

    // Imprime uma quebra de linha
    printf("\n");

    // Se chegou até aqui, retorna 1 (sucesso)
    return 1;
}

void bignum_destroy(BigNum **n) {
    // Verifica se n é nulo
    if (n == NULL)
        return;

    // Verifica se existe um grande número
    if (*n == NULL)
        return;

    // Desaloca a lista encadeada dos dígitos
    linked_list_free(&((*n)->digits));

    // Desaloca todo o grande número e atribui nulo ao ponteiro
    free(*n);
    *n = NULL;
}