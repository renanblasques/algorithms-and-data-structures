#include <stdio.h>

long int fibonacci(int n);

int main() {
    int number;
    long int result;
    scanf("%d", &number);

    printf("Calculando fibonacci de %d...\n", number);
    result = fibonacci(number);
    printf("Resultado final: %ld\n", result);

    return 0;
}

long int fibonacci(int n) {
    printf("Entrando em fibonacci(%d)\n", n);

    if (n == 0) {
        printf("Caso base atingido: fibonacci(0) = 0\n");
        return 0;
    }
    if (n == 1) {
        printf("Caso base atingido: fibonacci(1) = 1\n");
        return 1;
    }
    
    long int result = fibonacci(n - 1) + fibonacci(n - 2);

    printf("Retornando de fibonacci(%d) = %ld\n", n, result);
    return result;
}