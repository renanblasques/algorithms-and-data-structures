#include <stdio.h>
#include <stdlib.h>

int sum_even(int sum_init, int size, int vector[]);

int main() {
    int size = 1, *vector, sum = 0;
    scanf("%d", &size);
    vector = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }

    sum = sum_even(sum, size, vector);
    printf("Soma dos pares: %d\n", sum);

    return 0;
}

int sum_even(int sum_init, int size, int vector[]) {
    int sum = sum_init;

    if (size - 1 < 0) {
        return sum;
    }
    if (vector[size - 1] % 2 == 0) {
        sum = sum_init + vector[size - 1];
    }

    return sum_even(sum, size - 1, vector);
}