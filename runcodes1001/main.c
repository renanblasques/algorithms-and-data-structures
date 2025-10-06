#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
    Stack *bin = create_stack();
    if (bin == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        return 1;
    }

    int number;
    scanf("%d", &number);

    while (number != 0) {
        int rest = number % 2;
        push(bin, rest);
        number = number / 2;
    }

    while (!is_empty(bin)) {
        int value;
        pop(bin, &value);
        printf("%d", value);
    }
    printf("\n");

    return 0;
}