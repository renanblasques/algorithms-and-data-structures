#ifndef complex_h
#define complex_h

typedef struct Complex {
    float real;
    float imag;
} Complex;

Complex complex_create(float real, float imag);
Complex complex_sum(Complex a, Complex b);
Complex complex_sub(Complex a, Complex b);
Complex complex_mult(Complex a, Complex b);
void complex_print(Complex n);

#endif