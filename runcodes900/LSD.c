#include <stdio.h>
#include <stdlib.h>
#include "LSD.h"

DynamicList *list_create() {
    DynamicList *list = (DynamicList *)malloc(sizeof(DynamicList));
    if (list == NULL) return list;

    list->data = NULL;
    list->size = 0;
    list->capacity = 0;

    return list;
}

int list_destroy(DynamicList **list) {
    if (list == NULL) return -1;
    if (*list == NULL) return 0;

    free((*list)->data);
    free(*list);
    *list = NULL;

    return 1;
}

int list_is_empty(const DynamicList *list) {
    if (list == NULL) return -1;

    if (list->size == 0) return 1;

    return 0;
}

int list_size(const DynamicList *list) {
    if (list == NULL) return -1;

    return list->size;
}

int list_capacity(const DynamicList *list) {
    if (list == NULL) return -1;

    return list->capacity;
}

int list_insert_end(DynamicList *list, ListType elem) {
    if (list == NULL) return -1;

    if (list_ensure_capacity(list) == -1) return -1;

    list->data[list->size] = elem;
    list->size++;

    return 1;
}

int list_insert_at(DynamicList *list, int pos, ListType elem) {
    if (list == NULL) return -1;
    if ((pos < 0) || (pos > list->size)) return 0;

    if (list_ensure_capacity(list) == -1) return -1;

    for (int i = list->size; i > pos; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[pos] = elem;
    list->size++;

    return 1;
}

int list_remove_at(DynamicList *list, int pos, ListType *removed) {
    if (list == NULL) return -1;
    if ((pos < 0) || (pos >= list->size)) return 0;

    if (removed != NULL) {
        *removed = list->data[pos];
    }

    for (int i = pos; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;

    return 1;
}

int list_get_at(const DynamicList *list, int pos, ListType *elem) {
    if (list == NULL) return -1;
    if (elem == NULL) return -1;
    if ((pos < 0) || (pos >= list->size)) return 0;

    *elem = list->data[pos];
    
    return 1;
}

int list_find(const DynamicList *list, ListType elem, int *pos) {
    if (list == NULL) return -1;
    if (pos == NULL) return -1;

    *pos = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == elem) {
            *pos = i;
            return 1;
        }
    }

    return 0;
}

int list_clear(DynamicList *list) {
    if (list == NULL) return -1;
    if (list->size == 0) return 0;

    list->size = 0;
    return 1;
}

int list_print(const DynamicList *list) {
    if (list == NULL) return -1;
    if (list_is_empty(list)) {
        printf("[]\n");
        return 0;
    }

    printf("[");
    for (int i = 0; i < list->size - 1; i++) {
        printf("%d, ", list->data[i]);
    }
    printf("%d]\n", list->data[list->size - 1]);

    return 1;
}

int list_ensure_capacity(DynamicList *list) {
    if (list == NULL) return -1;

    int new_capacity;

    if (list->capacity == 0) {
        new_capacity = 4;
    } else {
        new_capacity = list->capacity * 2;
    }

    ListType *new_data_list = (ListType *)realloc(list->data, new_capacity * sizeof(ListType));
    if (new_data_list == NULL) return -1;

    list->data = new_data_list;
    list->capacity = new_capacity;

    return 1;
}