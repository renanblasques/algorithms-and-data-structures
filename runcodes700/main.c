#include <stdio.h>
#include "Ponto.h"

int main() {
    int option = 0;

    float x1, y1, x2, y2;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);
    
    Ponto *p1 = criaPonto(x1, y1);
    Ponto *p2 = criaPonto(x2, y2);

    do {
        scanf("%d", &option);
        switch (option) {
            case 1: {
                imprimePonto(p1);
                break;
            }
            case 2: {
                imprimePonto(p2);
                break;
            }
            case 3: {
                printf("%.3f\n", distancia(p1, p2));
                break;
            }
            case 4: {
                printf("%.3f\n", distanciaOrigem(p1));
                break;
            }
            case 5: { 
                printf("%.3f\n", distanciaOrigem(p2));
                break;
            }
            case 6: {
                float x, y;
                scanf("%f %f", &x, &y);
                atribuiPonto(p1, x, y);
                break;
            }
            case 7: {
                float x, y;
                scanf("%f %f", &x, &y);
                atribuiPonto(p2, x, y);
                break;
            }
            case 8: {
                int equals = pontosIguais(p1, p2);
                printf("%d\n", equals);
                break;
            }
            case 9: {
                break;
            }
            default: {
                break;
            }
        }
    } while (option != 9);
    
    liberaPonto(p1);
    liberaPonto(p2);

    return 0;
}