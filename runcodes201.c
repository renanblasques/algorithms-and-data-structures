#include <stdio.h>
#include <stdlib.h>

void menu_inicial() {
    printf("---- MENU ----\n");
    printf("1. Adicionar um valor à lista\n");
    printf("2. Remover o último valor da lista\n");
    printf("3. Listar todos os valores da lista\n");
    printf("4. Calcular e exibir a soma e a média dos valores\n");
    printf("5. Ordenar a lista em ordem crescente\n");
    printf("6. Encerrar o programa\n");
    printf("Digite a opção desejada: ");
}

// Comentarios para aceitar no runcodes

int main() {
    int tamanho = 0, opcao;
    int *vetor = NULL;

    do {
        // menu_inicial();
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            tamanho++;
            vetor = realloc(vetor, tamanho * sizeof(int));
            // printf("Digite o valor a ser adicionado: ");
            scanf("%d", &vetor[tamanho - 1]);
            // printf("\n");
            break;
        case 2:
            if (tamanho == 0) {
                // printf("Não há nada para remover.\n\n");
                break;
            }
            tamanho--;
            vetor = realloc(vetor, tamanho * sizeof(int));
            // printf("Último valor removido.\n\n");
            break;
        case 3:
            if (tamanho == 0) {
                // printf("Não há nada para listar.\n\n");
                break;
            }
            for (int i = 0; i < tamanho - 1; i++) {
                printf("%d ", vetor[i]);
            }
            printf("%d\n", vetor[tamanho - 1]);
            // printf("\n");
            break;
        case 4:
            int soma = 0;
            float media;
            for (int i = 0; i < tamanho; i++) {
                soma += vetor[i];
            }
            media = (float)soma / tamanho;
            printf("Soma = ");
            printf("%d, ", soma);
            printf("Media = ");
            printf("%.2f\n", media);
            // printf("\n");
            break;
        case 5:
            if (tamanho == 0) {
                // printf("Não há nada para ordenar.\n\n");
                break;
            }

            int flag = 1, aux;
            while (flag) {
                flag = 0;
                for (int i = 0; i < tamanho - 1; i++) {
                    if (vetor[i] > vetor[i + 1]) {
                        aux = vetor[i];
                        vetor[i] = vetor[i + 1];
                        vetor[i + 1] = aux;
                        flag = 1;
                    }
                }
            }

            // printf("\n");
            //free(lista);
            break;
        case 6:
            // printf("Encerrando o programa\n");
            break;
        default:
            // printf("Opção inválida! Digite uma opção válida: ");
            break;
        }
    } while (opcao != 6);

    free(vetor);

    return 0;
}