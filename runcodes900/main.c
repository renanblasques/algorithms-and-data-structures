#include <stdio.h>
#include <stdlib.h>
#include "LSD.h"

int main() {
    int option = 0;
    DynamicList *l = list_create();

    if (l == NULL) {
        printf("Erro ao alocar memória para lista.\n");
    }

    do {
        int number, position, size, ok;
        scanf("%d", &option);

        switch (option) {
            case 1: {
                scanf("%d", &number);

                ok = list_insert_end(l, number);
                if (ok == -1) ok = 0;

                printf("%d\n", ok);
                break;
            }

            case 2: {
                scanf("%d", &position);
                scanf("%d", &number);

                ok = list_insert_at(l, position, number);
                if (ok == -1) ok = 0;

                printf("%d\n", ok);
                break;
            }

            case 3: {
                scanf("%d", &position);

                ok = list_remove_at(l, position, &number);
                if (ok) {
                    printf("%d\n", number);
                    break;
                }

                printf("ERRO\n");
                break;
            }

            case 4: {
                scanf("%d", &position);

                ok = list_get_at(l, position, &number);
                if (ok) {
                    printf("%d\n", number);
                    break;
                }
                
                printf("ERRO\n");
                break;
            }

            case 5: {
                scanf("%d", &number);

                ok = list_find(l, number, &position);
                if (ok == -1) {
                    printf("ERRO\n");
                    break;
                }
                
                printf("%d\n", position);
                break;
            }

            case 6: {
                size = list_size(l);
                if (size >= 0) {
                    printf("%d\n", size);
                    break;
                }

                printf("ERRO\n");
                break;
            }

            case 7: {
                ok = list_print(l);

                if (ok == -1) {
                    printf("ERRO\n");
                }
                break;
            }

            case 8: {
                ok = list_clear(l);

                if (ok == -1) {
                    printf("ERRO\n");
                }
                break;
            }

            default:
                break;
        }

    } while (option != 9);

    list_destroy(&l);
    
    return 0;
}