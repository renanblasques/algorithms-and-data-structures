#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    int option = 0, position, value;
    LinkedList *list1 = linked_list_create();
    LinkedList *list2 = linked_list_create();

    do {
        scanf("%d", &option);
        switch (option) {
        case 1: {
            scanf("%d", &value);
            scanf("%d", &position);
            linked_list_insert_node(list1, position, value);
            break;
        }
        case 2: {
            scanf("%d", &value);
            scanf("%d", &position);
            linked_list_insert_node(list2, position, value);
            break;
        }
        case 3: {
            scanf("%d", &position);
            linked_list_remove_node(list1, position, NULL);
            break;
        }
        case 4: {
            scanf("%d", &position);
            linked_list_remove_node(list2, position, NULL);
            break;
        }
        case 5: {
            for (int i = 0; i < linked_list_size(list2); i++) {
                linked_list_get_node(list2, i, &value);
                position = linked_list_size(list1);
                linked_list_insert_node(list1, position, value);
            }
            break;
        }
        case 6: {
            for (int i = 0; i < linked_list_size(list1); i++) {
                linked_list_get_node(list1, i, &value);
                position = linked_list_size(list2);
                linked_list_insert_node(list2, position, value);
            }
            break;
        }
        case 7: {
            printf("[");
            int size = linked_list_size(list1);
            for (int i = 0; i < size; i++) {
                if (i < size - 1) {
                    linked_list_get_node(list1, i, &value);
                    printf("%d ", value);
                    continue;
                }
                linked_list_get_node(list1, i, &value);
                printf("%d", value);
            }
            printf("]\n");
            break;
        }
        case 8: {
            printf("[");
            int size = linked_list_size(list2);
            for (int i = 0; i < size; i++) {
                if (i < size - 1) {
                    linked_list_get_node(list2, i, &value);
                    printf("%d ", value);
                    continue;
                }
                linked_list_get_node(list2, i, &value);
                printf("%d", value);
            }
            printf("]\n");
            break;
        }
        default:
            break;
        }

    } while (option != 9);

    linked_list_free(&list1);
    linked_list_free(&list2);
    
    return 0;
}