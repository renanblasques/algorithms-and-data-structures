#include <stdio.h>
#include "complex.h"

Complex complex_create(float real, float imag) {
    Complex number;
    number.real = real;
    number.imag = imag;

    return number;
}

Complex complex_sum(Complex a, Complex b) {
    Complex sum;

    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;

    return sum;
}

Complex complex_sub(Complex a, Complex b) {
    Complex sub;

    sub.real = a.real - b.real;
    sub.imag = a.imag - b.imag;

    return sub;
}

Complex complex_mult(Complex a, Complex b) {
    Complex mult;

    mult.real = (a.real * b.real) - (a.imag * b.imag);
    mult.imag = (a.real * b.imag) + (a.imag * b.real);

    return mult;
}

void complex_print(Complex n) {
    if (n.imag < 0) {
        printf("%.1f%.1fi\n", n.real, n.imag);
    } else {
        printf("%f+%fi\n", n.real, n.imag);
    }
}