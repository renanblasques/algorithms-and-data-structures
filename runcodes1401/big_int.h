#ifndef big_int_h
#define big_int_h

typedef struct BigInt BigInt;

BigInt big_int_create(int number_of_digits);
BigInt *big_int_sum(BigInt *a, BigInt *b);

#endif