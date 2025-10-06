#include <stdio.h>
#include <sys/time.h>

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

int main() {
    struct timeval inicio, fim;
    long segundos, microssegundos;
    
    gettimeofday(&inicio, NULL);

    int number;
    long int result;
    scanf("%d", &number);

    printf("Calculando fibonacci de %d...\n", number);
    result = fibonacci(number);
    printf("Resultado final: %ld\n", result);

    gettimeofday(&fim, NULL);

    // Cálculo correto do tempo
    segundos = fim.tv_sec - inicio.tv_sec;
    microssegundos = fim.tv_usec - inicio.tv_usec;

    if (microssegundos < 0) {
        segundos -= 1;
        microssegundos += 1000000;
    }

    printf("Tempo decorrido: %ld.%06ld segundos\n", segundos, microssegundos);

    return 0;
}
