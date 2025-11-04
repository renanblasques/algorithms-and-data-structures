#include <stdlib.h>
#include "big_int.h"

struct BigInt {
    int lenght;   // número de digitos usados
    int capacity; // máximo de dígitos que posso usar
    char *digits;
};

BigInt *big_int_create(int number_of_digits) {
    if (number_of_digits <= 0) return NULL;

    BigInt *n = malloc(sizeof(BigInt));
    if (n == NULL) return NULL;

    n->digits = calloc(sizeof(char), number_of_digits);
    if (n->digits == NULL) {
        free(n);
        return NULL;
    }

    n->lenght = 1;
    n->capacity = number_of_digits;

    return n;
}

BigInt *big_int_sum(BigInt *a, BigInt *b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }

    int size_sum;
    if (a->lenght > b->lenght) {
        size_sum = a->lenght;
    } else {
        size_sum = b->lenght;
    }

    BigInt *big_sum = big_int_create(size_sum + 1);

    int carry = 0;
    for (int i = 0; i <= size_sum; i++) {
        char digit_a = 0;
        char digit_b = 0;

        if (i < a->lenght) {
            digit_a = a->digits[i];
        }
        if (i < b->lenght) {
            digit_b = b->digits[i];
        }

        char sum = digit_a + digit_b;
        big_sum->digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry == 0) {
    }

}