#include <stdio.h>        // Biblioteca para entrada e saída de dados
#include <stdlib.h>       // Biblioteca para alocação de memória
#include <string.h>       // Biblioteca para manipulação de strings
#include "linked_list.h"  // Biblioteca criada para lista encadeada
#include "big_numbers.h"  // Biblioteca criara para grandes números

#define LINE_MAX 1000     // Tamanho máximo da linha para entrada das operações

int main() {
    /*  Variáveis:
        - num_operations: número de vezes que o programa vai rodar
        - line_content: conteúdo da linha (operação + n1 + n2)
        - operation: primeira palavra de line_content  (operação)
        - first_num: segunda palavra de line_content   (n1)
        - second_num: terceira palavra de line_content (n2)
    */

    int num_operations;
    char *line_content = malloc(LINE_MAX * sizeof(char));
    char *operation, *first_num, *second_num;

    // Lê do usuário número de operações e armazena em num_operations
    scanf("%d", &num_operations);

    // Loop para repetir número de operações do programa
    for (int i = 0; i < num_operations; i++) {
        // Lê a linha do usuário e armazena em line_content
        scanf(" %[^\n]", line_content);
        
        // "Corta" a string line_content em três partes
        operation = strtok(line_content, " ");
        first_num = strtok(NULL, " ");
        second_num = strtok(NULL, " ");

        // Cria os grandes números
        LinkedList *n1 = bignum_create(first_num, strlen(first_num));
        LinkedList *n2 = bignum_create(second_num, strlen(second_num));

        // Verifica a operação e chama função para realizar
        if (strcmp(operation, "soma") == 0) {

        } else if (strcmp(operation, "maior") == 0) {

        } else if (strcmp(operation, "menor") == 0) {
            
        } else if (strcmp(operation, "igual") == 0) {
            
        } else {
            printf("Operação inválida!\n");
        }


        // Não esquecer de excluir os números
    }

    // Libera memória alocada para o line_content
    free(line_content);

    return 1;
}