#include <stdio.h>
#include "complex.h"

int main() {
    Complex x;
    float real, imag;

    scanf("%f %f", &real, &imag);

    x = complex_create(real, imag);

    return 0;
}