#include <stdio.h>

int main() {
    int vector[10], mid, min = 0, max = 9, number, found = 0;

    printf("Insira a seguir os 10 números crescentes no vetor:\n");
    printf("Digite a posição 0 do vetor: ");
    scanf("%d", &vector[0]);
    for (int i = 1; i < 10; i++) {
        printf("Digite a posição %d do vetor: ", i);
        scanf("%d", &vector[i]);
        if (vector[i] < vector[i - 1]) {
            printf("Esse valor é menor que o anterior!\n");
            i--;
        }
    }

    printf("Digite o número que deseja buscar: ");
    scanf("%d", &number);

    
    while (!found) {

        mid = (max + min) / 2;
        printf("\n\nNovo meio entre %d e %d: %d\n\n", min, max, mid);

        if (vector[mid] == number) {
            printf("Número %d encontrado na posição na posição %d\n", number, mid);
            found = 1;
        } else if (vector[mid] < number) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return 0;
}