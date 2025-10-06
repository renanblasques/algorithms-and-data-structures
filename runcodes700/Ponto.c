#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

#define EPS 0.00001

Ponto *criaPonto(float x, float y) {
    Ponto *p = malloc(sizeof(Ponto));
    if (!p) {
        printf("Nao foi possivel alocar o ponto\n");
        return NULL;
    }

    p->x = x;
    p->y = y;
    return p;
}

void liberaPonto(Ponto *p) {
    if (p != NULL) free(p);
}

void acessaPonto(Ponto *p, float *x, float *y) {
    if (p == NULL) {
        printf("Ponteiro invalido! Abortando...\n");
        return;
    }

    *x = p->x;
    *y = p->y;
}

void atribuiPonto(Ponto *p, float x, float y) {
    if (p == NULL) {
        printf("Ponteiro invalido! Abortando...\n");
        return;
    }
    p->x = x;
    p->y = y;
}

float distancia(Ponto *p1, Ponto *p2) {
    if (!p1 || !p2) {
        printf("Ponteiros invalidos para a operacao!! Abortando...");
        return -1;
    }

    float dst_x = p1->x - p2->x;
    float dst_y = p1->y - p2->y;
    float distancia = sqrt(dst_x * dst_x + dst_y * dst_y);
    return distancia;
}

float distanciaOrigem(Ponto *p) {
    if (!p) {
        printf("Ponteiros invalidos para a operacao!! Abortando...");
        return -1;
    }
    
    float distancia = sqrt(p->x * p->x + p->y * p->y);
    return distancia;
}

void imprimePonto(Ponto *p) {
    if (!p) {
        printf("Ponteiros invalidos para a operacao!! Abortando...");
        return;
    }

    printf("(%.3f,%.3f)\n", p->x, p->y);
}

int pontosIguais(Ponto *p1, Ponto *p2) {
    float diff_x = p1->x - p2->x;

    if (fabs(diff_x) > EPS) {
        return 0;
    }

    float diff_y = p1->y - p2->y;

    if (fabs(diff_y) > EPS) {
        return 0;
    }

    return 1;
}
