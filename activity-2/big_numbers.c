#include <stdio.h>
#include <stdlib.h>
#include "big_numbers.h"

LinkedList* bignum_create(const char number[], int size) {
    // Verifica se o número recebido existe
    // Caso não exista, já retorna nulo
    if (number == NULL)
        return NULL;

    // Verifica se o tamanho do número recebido é valido
    // Caso não seja, já retorna nulo
    if (size <= 0)
        return NULL;

    // Cria a lista encadeada (número astronômico)
    LinkedList *n = linked_list_create();

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
        int ok = linked_list_insert_node(n, i, digit);
        j--;

        // Verifica se inseriu o dígito com sucesso
        // Em caso de falha, desaloca n e retorna nulo
        if (ok == -1) {
            linked_list_free(&n);
            return NULL;
        }
    }

    // Loop para remover os zeros à esquerda
    // Note que k vai até 1, pois o número pode ser 0
    for (int k = size - 1; k >= 1; k--) {
        // Cria o dígito para verificação
        int digit;

        // Busca o dígito no k-ésimo nó
        int ok = linked_list_get_node(n, k, &digit);

        // Verifica se obteve o dígito com sucesso
        // Em caso de falha, desaloca n e retorna nulo
        if (ok == -1) {
            linked_list_free(&n);
            return NULL;
        }

        // Caso o dígito seja um zero (à esquerda), remove da lista
        if (digit == 0) {
            ok = linked_list_remove_node(n, k, NULL);

            // Verifica se removeu o dígito com sucesso
            // Em caso de falha, desaloca n e retorna nulo
            if (ok == -1) {
                linked_list_free(&n);
                return NULL;
            }

        // Caso contrário, encerra o loop para não remover zeros do meio
        } else {
            break;
        }
    }

    // Se chegou até aqui, a lista foi preenchida com os dígitos corretamente
    // Retorna o número astronômico criado
    return n;
}

LinkedList* bignum_sum(const LinkedList *n1, const LinkedList *n2) {
    // Verifica se os números recebidos existem
    // Caso não existam, já retorna nulo
    if ((n1 == NULL) || (n2 == NULL))
        return NULL;

    // Obtém a quantidade de dígitos de cada número
    int n1_size = linked_list_size(n1);
    int n2_size = linked_list_size(n2);

    // Cria um grande número para o número que representa a soma
    LinkedList *sum = linked_list_create();

    // Verifica se a função alocou memória para a lista
    // Em caso de falha, já retorna nulo
    if (sum == NULL)
        return NULL;


    // Cria as variáveis para somar os números e verificação
    int n1_digit, n2_digit, sum_digit, carry = 0;

    if (n1_size < n2_size) {
        for (int i = 0; i < n1_size; i++) {

            // Obtém os dígitos de n1 e n2
            // Já verifica se conseguiu obter
            // Em caso de falha, desaloca sum e retorna nulo
            if ((linked_list_get_node(n1, i, &n1_digit) == -1) 
                    || (linked_list_get_node(n2, i, &n2_digit) == -1)) {

                linked_list_free(&sum);
                return NULL;
            }

            // Soma os dígitos de cada número, junto com o carry
            sum_digit = n1_digit + n2_digit + carry;

            // Se a soma ultrapassar 9, passar valor para o carry e subtrair 10 do dígito
            if (sum_digit >= 10) {
                carry = 1;
                sum_digit -= 10;

            // Caso contrário, apenas zerar o carry
            } else {
                carry = 0;
            }

            // Insere a soma dos dígitos de n1 e n2 no sum
            // Já verifica se conseguiu inserir
            // Em caso de falha, desaloca sum e retorna nulo
            if (linked_list_insert_node(sum, i, sum_digit) == -1) {
                linked_list_free(&sum);
                return NULL;
            }
        }

        // Obtém o dígito seguinte do número maior (que já não existe no número menor)
        // Já verifica se conseguiu obter
        // Em caso de falha, desaloca sum e retorna nulo
        if (linked_list_get_node(n2, n1_size, &n2_digit) == -1) {
            linked_list_free(&sum);
                return NULL;
        }

        // Soma apenas o dígito do número maior com o carry
        sum_digit = n2_digit + carry;

        // Se a soma chegar em 10, passar valor para o carry e subtrair 10 do dígito
        if (sum_digit == 10) {
            carry = 1;
            sum_digit = 0;

        // Caso contrário, apenas zerar o carry
        } else {
            carry = 0;
        }

        if (linked_list_insert_node(sum, n1_size, sum_digit) == -1) {
            linked_list_free(&sum);
            return NULL;
        }

        // Continuar o mesmo processo agora, caso existam dígitos no número maior
        // Observe que apenas os dígitos do número maior são copiados para a soma
        for (int i = n1_size + 1; i < n2_size; i++) {
            if (linked_list_get_node(n2, i, &sum_digit) == -1) {
                linked_list_free(&sum);
                    return NULL;
            }

            if (linked_list_insert_node(sum, i, sum_digit) == -1) {
                linked_list_free(&sum);
                return NULL;
            }
        }
    }
}