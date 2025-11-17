#include <stdio.h>
#include <stdlib.h>
#include "big_numbers.h"

BigNum* bignum_create(const char number[], int size) {
    // Verifica se o número recebido existe
    // Caso não exista, já retorna nulo
    if (number == NULL)
        return NULL;

    // Verifica se o tamanho do número recebido é valido
    // Caso não seja, já retorna nulo
    if (size <= 0)
        return NULL;

    // Cria a lista encadeada (número astronômico)
    BigNum *n = linked_list_create();

    // Verifica se a função alocou memória para a lista
    // Em caso de falha, já retorna nulo
    if (n == NULL)
        return NULL;

    // i: "Ponteiro" para criar os nós da lista n (incrementa)
    // j: "Ponteiro" para pegar os dígitos do número (number) recebido (decrementa)
    int i = 0;
    int j = size - 1;

    // Loop para inserir os dígitos na lista encadeada
    for (i = 0; i < size; i++) {

        // Verifica se é digito
        // Caso não seja, desaloca n e retorna nulo
        if ((number[j] < '0') || (number[j] > '9')) {
            linked_list_free(&n);
            return NULL;
        }

        // Converte o dígito do número recebido (char) para int
        int digit = number[j] - '0';

        // Insere o dígito convertido de number na i-ésima posição da lista n (número astronômico)
        linked_list_insert_node(n, i, digit);
        j--;
    }

    // Loop para remover os zeros à esquerda
    // Note que k vai até 1, pois o número pode ser 0
    for (int k = size - 1; k >= 1; k--) {
        // Cria o dígito para verificação
        int digit;

        // Busca o dígito no k-ésimo nó
        linked_list_get_node(n, k, &digit);

        // Caso o dígito seja um zero (à esquerda), remove da lista
        // Caso contrário, encerra o loop para não remover zeros do meio
        if (digit == 0)
            linked_list_remove_node(n, k, NULL);
        else
            break;
    }

    // Se chegou até aqui, a lista foi preenchida com os dígitos corretamente
    // Retorna o número astronômico criado
    return n;
}

BigNum* bignum_sum(const BigNum *n1, const BigNum *n2) {
    // Verifica se n1 e n2 existem
    if (n1 == NULL || n2 == NULL)
        return NULL;

    // Armazena a quantidade de dígitos de n1 e n2
    int size_n1 = linked_list_size(n1);
    int size_n2 = linked_list_size(n2);

    // Armazena a maior quantidade de dígitos em max_size
    int max_size;

    if (size_n1 > size_n2)
        max_size = size_n1;
    else
        max_size = size_n2;

    // Cria o número sum que guardará a soma de n1 e n2
    BigNum *sum = linked_list_create();
    if (sum == NULL)
        return NULL;

    // Cria o carry inicial valendo 0 (para a primeira soma)
    int carry = 0;

    // Cria as variáveis para realizar a soma
    int n1_digit, n2_digit, sum_digit;

    for (int i = 0; i < max_size; i++) {

        // Pega dígito de n1 se o i-ésimo dígito de n1 existir
        if (i < size_n1)
            linked_list_get_node(n1, i, &n1_digit);

        // Caso contrário, se o dígito não existir, assume 0 para a soma
        else
            n1_digit = 0;

        // Pega dígito de n2 se o i-ésimo dígito de n2 existir
        if (i < size_n2)
            linked_list_get_node(n2, i, &n2_digit);

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
        linked_list_insert_node(sum, i, sum_digit);

        // Processo repete para o próximo dígito
        // ou apenas termina se for o último
    }

    // Se terminou o loop com carry = 1, adiciona um dígito extra em sum
    if (carry == 1)
        linked_list_insert_node(sum, max_size, carry);
    
    // Se chegou até aqui, o número sum foi somado e já pode retornar
    return sum;
}


int bignum_compare(const BigNum *n1, const BigNum *n2) {
    // Verifica se n1 e n2 existem
    if ((n1 == NULL) || (n2 == NULL))
        return -1;

    // Obtém a quantidade de dígitos de cada número
    int n1_size = linked_list_size(n1);
    int n2_size = linked_list_size(n2);

    /*
        Faz uma verificação inicial:
        - Se algum dos dois números possuir mais dígitos, é o maior
        - Se possuirem dígitos iguais, analisar cada dígito
    */
    if (n1_size > n2_size)
        // n1 é maior que n2
        return 1;

    if (n1_size < n2_size)
        // n1 é menor que n2
        return 2;

    // Se chegou aqui, possuem número de dígitos iguais
    // Verificar dígito a dígito

    // Cria as variáveis para a lógica de verificação
    int greater = 0, n1_digit, n2_digit;

    // Percorre as listas paralelamente, dígito a dígito,
    // do mais significativo para o menos significativo
    for (int i = n1_size - 1; i >= 0; i--) {

        // Obtém os i-ésimos dígitos de n1 e n2 e armazena
        // em n1_digit e n2_digit, respectivamente
        linked_list_get_node(n1, i, &n1_digit);
        linked_list_get_node(n2, i, &n2_digit);

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
    
    // Retorna a variável que indica qual caso chegou.
    return greater;
}

int bignum_print(const BigNum *n) {
    // Antes de tudo, verifica se o número existe
    if (n == NULL)
        return -1;

    // Se a lista existe, verifica também se está vazia
    if (linked_list_is_empty(n))
        return 0;

    // Obtém o número de dígitos do número
    int n_size = linked_list_size(n);
    int digit;
    
    // Percorre a lista do final para o começo e imprime cada dígito
    for (int i = n_size - 1; i >= 0; i--) {
        linked_list_get_node(n, i, &digit);
        printf("%d", digit);
    }

    // Imprime uma quebra de linha
    printf("\n");

    // Se chegou até aqui, retorna 1 (sucesso)
    return 1;
}

void bignum_destroy(BigNum **n) {
    // Apenas chama a função para liberar a lista da memória
    // A função já trata todos os casos
    linked_list_free(n);
}