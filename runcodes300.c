#include <stdio.h>

long int factorial(int n);

int main() {
    int number;
    long int result;
    scanf("%d", &number);
    
    printf("Calculando fatorial de %d...\n", number);
    result = factorial(number);
    printf("Resultado final: %ld\n", result);

    return 0;
}

long int factorial(int n) {
    printf("Entrando em fatorial(%d)\n", n);

    if (n == 0) {
        printf("Caso base atingido: fatorial(0) = 1\n");
        return 1;
    }
    if (n == 1) {
        printf("Caso base atingido: fatorial(1) = 1\n");
        return 1;
    }

    long int result = n * factorial(n - 1);
    printf("Retornando de fatorial(%d) = %ld\n", n, result);
    return result;

}