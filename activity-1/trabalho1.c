// Inclusão de biblioteca para ler entradas do usuário e imprimir saídas na tela
#include <stdio.h>
// Inclusão de biblioteca para alocar espaço na memória dinamicamente
#include <stdlib.h>


// Menu de opções para o usuário
void menu_message();

// Menu de saída para o usuário
void ending_message();

// Função para ler o vetor, sempre crescente
void read_crescent_vector(int v[], int size);

// Função para imprimir o vetor
void print_vector(int v[], int size);

// Função para verificar se o vetor é valido
// Retorna 1 se verdadeiro ou 0 se falso
int valid_vector(int v[], int size);

// Função para inverter o vetor de entrada
void reverse_vector(int v[], int reverse_v[], int size);

// Função de busca sequência de um elemento no vetor
// Imprime SIM se o elemento existe ou NAO, caso contrário
void sequential_search(int v[], int size, int target);

// Função de busca binária iterativa de um elemento no vetor
// Imprime SIM se o elemento existe ou NAO, caso contrário
void iteractive_binary_search(int v[], int size, int target);

// Função de busca binária recursiva de um elemento no vetor
// Imprime SIM se o elemento existe ou NAO, caso contrário
void recursive_binary_search(int v[], int left, int right, int target);

int main() {
    /* Inicialização das variáveis
        option:      opção digitada pelo usuário
        size:        tamanho do vetor a ser obtido
        *v:          vetor original a ser obtido
        *reverse_v:  vetor que poderá ser invertido
        target:      elemento que poderá ser buscado
    */
    int option = 0, size = 0, *v, *reverse_v, target;

    // Obtém o tamanho do vetor
    scanf("%d", &size);

    // Aloca memória para o vetor e o vetor inverso
    v = (int *) malloc(size * sizeof(int));
    reverse_v = (int *) malloc(size * sizeof(int));

    // Verifica se os vetores foram alocados. Caso negativo, encerra o programa
    if (v == NULL) return 1;
    if (reverse_v == NULL) {
        free(v);
        return 1;
    }

    // Chama a função para ler o vetor crescente
    read_crescent_vector(v, size);

    // Loop principal do programa:
    do {
        // Chama a função que imprime o menu de opções ao usuário
        menu_message();

        // Obtém a opção desejada do usuário
        scanf("%d", &option);

        switch (option) {
        case 1:
            // Chama a função para inverter o vetor de entrada
            reverse_vector(v, reverse_v, size);
            // Chama a função para imprimir o vetor invertido
            print_vector(reverse_v, size);
            break;
        case 2:
            // Obtém o elemento a ser buscado no vetor de entrada
            scanf("%d", &target);
            // Chama a função para fazer a busca sequencial
            sequential_search(v, size, target);
            break;
        case 3:
            // Obtém o elemento a ser buscado no vetor de entrada
            scanf("%d", &target);
            // Chama a função para fazer a busca binária recursiva
            iteractive_binary_search(v, size, target);
            break;
        case 4:
            // Obtém o elemento a ser buscado no vetor de entrada
            scanf("%d", &target);
            // Chama a função para fazer a busca binária recursiva
            recursive_binary_search(v, 0, size - 1, target);
            break;
        case 5:
            // Encerra o programa e exibe uma mensagem de encerramento
            ending_message();
            break;
        default:
            // Caso o valor digitado seja menor que 1 ou maior que 5
            printf("Opção inválida! Digite novamente.\n");
            break;
        }
    } while (option != 5);

    // Libera a memória alocada para os vetores
    free(v);
    free(reverse_v);

    return 0;
}

void menu_message() {
    printf("\n");
    printf("1. Inversão da ordem do vetor de entrada.\n");
    printf("2. Busca sequencial no vetor de entrada.\n");
    printf("3. Busca binária iterativa no vetor de entrada.\n");
    printf("4. Busca binária recursiva no vetor de entrada.\n");
    printf("5. Encerrar o programa.\n");
    printf("\n");
}

void ending_message() {
    printf("Encerrando programa.\n");
}

int valid_vector(int v[], int size) {
    if (v == NULL) {
        printf("Erro: vetor de entrada não contém elementos.\n");
        return 0;
    }
    if (size <= 0) {
        printf("Erro: tamanho de vetor inválido.\n");
        return 0;
    }
    return 1;
}

void reverse_vector(int v[], int reverse_v[], int size) {
    if (!valid_vector(v, size)) return;

    for (int i = 0; i < size; i++) {
        reverse_v[i] = v[size - 1 - i];
    }
}

void read_crescent_vector(int v[], int size) {
    if (!valid_vector(v, size)) return;

    scanf("%d", &v[0]);
    for (int i = 1; i < size; i++) {
        scanf("%d", &v[i]);
        if (v[i] < v[i - 1]) {
            printf("O valor não pode ser menor que o anterior.\n");
            i--;
        }
    }
}

void print_vector(int v[], int size) {
    if (!valid_vector(v, size)) return;

    for (int i = 0; i < size - 1; i++) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[size - 1]);
}

void sequential_search(int v[], int size, int target) {
    if (!valid_vector(v, size)) return;

    for (int i = 0; i < size; i++) {
        if (v[i] == target) {
            printf("SIM\n");
            return;
        }
    }

    printf("NAO\n");
}

void iteractive_binary_search(int v[], int size, int target) {
    if (!valid_vector(v, size)) return;

    int min = 0, max = size - 1, middle;
    int found = 0;

    while (min <= max) {
        middle = (min + max) / 2;
        if (target == v[middle]) {
            printf("SIM\n");
            return;
        }
        if (target > v[middle]) {
            min = middle + 1;
        } else {
            max = middle - 1;
        }
    }

    printf("NAO\n");
}

void recursive_binary_search(int v[], int left, int right, int target) {
    if (v == NULL) return;

    if (left > right) {
        printf("NAO\n");
        return;
    }

    int middle = (right + left) / 2;

    if (v[middle] == target) {
        printf("SIM\n");
        return;
    }

    if (v[middle] > target) {
        recursive_binary_search(v, left, middle - 1, target);
    } else {
        recursive_binary_search(v, middle + 1, right, target);
    }
}