/*  ===========================================================================
    |    TRABALHO 2 -ALGORTIMOS E ESTRUTURAS DE DADOS - NÚMEROS ASTRONÔMICOS  |
    |       Renan Silva Blasques                - NUSP:  9784057              |
    |       Rodrigo De Jesus Ferreira Gonçalves - NUSP: 16899823              |
    ===========================================================================   */

#include <stdio.h>        // Biblioteca para entrada e saída de dados
#include <stdlib.h>       // Biblioteca para alocação de memória
#include <string.h>       // Biblioteca para manipulação de strings
#include "big_numbers.h"  // Biblioteca criada para os números astronômicos

#define LINE_MAX 1000     // Tamanho máximo da linha para entrada das operações

int main() {
    // Lê do usuário número de operações e armazena em num_operations
    int num_operations;
    scanf("%d", &num_operations);
    getchar();

    // Aloca memória para armazenar o conteúdo das linha digitada (operação + n1 + n2)
    char *line_content = malloc(LINE_MAX * sizeof(char));

    // Verifica se memória foi alocada
    if (line_content == NULL)
        return 1;

    // Loop para repetir número de operações do programa
    for (int i = 0; i < num_operations; i++) {
        // Lê a linha do usuário e armazena em line_content
        scanf(" %[^\n]", line_content);
        
        // Cria os ponteiros para as três palavras de line_content
        // e "corta" a string line_content em três partes
        char *operation = strtok(line_content, " ");
        char *first_num = strtok(NULL, " ");
        char *second_num = strtok(NULL, " ");

        if (operation == NULL || first_num == NULL || second_num == NULL) {
            free(line_content);
            return 1;
        }

        // Cria os grandes números
        // Passa a string cortada e o tamanho dela
        BigNum *n1 = bignum_create(first_num, strlen(first_num));
        BigNum *n2 = bignum_create(second_num, strlen(second_num));

        // Verifica se os números foram criados
        if (n1 == NULL || n2 == NULL) {
            bignum_destroy(&n1);
            bignum_destroy(&n2);
            free(line_content);
            return 1;
        }

        printf("Resultado:: ");

        // Verifica a operação e chama função para realizá-la
        if (strcmp(operation, "soma") == 0) {
            
            // Chama função para somar n1 e n2 e armazenar em sum
            BigNum *sum = bignum_sum(n1, n2);

            // Chama funções para imprimir o número sum e desalocar a memória
            bignum_print(sum);
            bignum_destroy(&sum);

        } else if (strcmp(operation, "maior") == 0) {
            printf(bignum_compare(n1, n2) == 1 ? "True\n" : "False\n");

        } else if (strcmp(operation, "menor") == 0) {
            printf(bignum_compare(n1, n2) == 2 ? "True\n" : "False\n");

        } else if (strcmp(operation, "igual") == 0) {
            printf(bignum_compare(n1, n2) == 0 ? "True\n" : "False\n");

        } else {
            printf("Operação inválida!\n");
        }

        // Libera memória alocada para os números
        bignum_destroy(&n1);
        bignum_destroy(&n2);
    }

    // Libera memória alocada para o line_content
    free(line_content);

    // Fim do programa -> Retorna 0 (sucesso)
    return 0;
}