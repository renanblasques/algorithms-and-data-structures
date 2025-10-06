#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, new_number, position;
    scanf("%d", &size);
    int *vector = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }

    scanf("%d", &new_number);
    scanf("%d", &position);
    size++;
    vector = realloc(vector, size * sizeof(int));

    for (int i = size - 1; i > position; i--) {
        vector[i] = vector[i - 1];
    }
    vector[position] = new_number;

    for (int i = 0; i < size - 1; i++) {
        printf("%d ", vector[i]);
    }
    printf("%d\n", vector[size - 1]);

    free(vector);

    return 0;
}