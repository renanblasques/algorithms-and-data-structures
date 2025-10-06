#include <stdio.h>
#include "LSE.h"

int main() {
    int option = 0, success;
    LSE *list = lse_cria();

    if (list == NULL) {
        printf("Erro ao alocar lista.\n");
    }
    
    do {
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int elem;
                scanf("%d", &elem);

                success = lse_insere_final(list, elem);

                printf("%d\n", success);
                break;
            }
            case 2: {
                int pos, elem;
                scanf("%d", &pos);
                scanf("%d", &elem);

                success = lse_insere_pos(list, pos, elem);

                printf("%d\n", success);
                break;
            }
            case 3: {
                int pos, removed;
                scanf("%d", &pos);

                success = lse_remove_pos(list, pos, &removed);

                if (success == 1) {
                    printf("%d\n", removed);
                } else {
                    printf("ERRO\n");
                }
                break;
            }
            case 4: {
                int pos, target;
                scanf("%d", &pos);

                success = lse_consulta_pos(list, pos, &target);

                if (success == 1) {
                    printf("%d\n", target);
                } else {
                    printf("ERRO\n");
                }
                break;
            }
            case 5: {
                int target, pos;
                scanf("%d", &target);
                
                success = lse_busca(list, target, &pos);

                printf("%d\n", pos);
                
                break;
            }
            case 6: {
                int size = lse_tamanho(list);

                if (size != -1) {
                    printf("%d\n", size);
                } else {
                    printf("ERRO\n");
                }
                break;
            }
            case 7: {
                success = lse_imprime(list);

                if (success == -1) {
                    printf("ERRO\n");
                }
                break;
            }
            case 8: {
                success = lse_limpa(list);

                if (success == -1) {
                    printf("ERRO\n");
                }

                break;
            }
            default: {
                break;
            }
        }
    } while (option != 9);
    
    lse_destroi(&list);

    return 0;
}