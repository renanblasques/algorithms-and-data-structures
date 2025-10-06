#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct List {
    list_type data[LIST_MAX];
    int size;
};


List *list_create(void) {
    List *l = malloc(sizeof(List));

    if (l == NULL) return l;

    l->size = 0;
    return l;
}

int list_destroy(List **l) {
    if (l == NULL) return -1;

    if (*l == NULL) return 0;

    free(*l);
    *l = NULL;

    return 1;
}

int list_is_empty(const List *l) {
    if (l == NULL) return -1;

    if (l->size == 0) return 1;

    return 0;
}

int list_is_full(const List *l) {
    if (l == NULL) return -1;

    if (l->size == LIST_MAX) return 1;

    return 0;
}

int list_size(const List *l) {
    if (l == NULL) return -1;

    return l->size;
}

int list_insert_at_end(List *l, list_type value) {
    if (l == NULL) return -1;

    if (list_is_full(l)) return -1;

    l->data[l->size] = value;
    l->size++;

    return 1;
}

int list_insert_at(List *l, int position, list_type value) {
    if (l == NULL) return -1;

    if (list_is_full(l)) return -1;

    if ((position < 0) || (position > l->size)) return -1;

    for (int i = l->size; i > position; i--) {
        l->data[i] = l->data[i - 1];
    }

    l->data[position] = value;
    l->size++;

    return 1;
}

int list_remove_at(List *l, int position, list_type *removed) {
    if (l == NULL) return -1;

    if (list_is_empty(l)) return -1;

    if ((position < 0) || (position >= l->size)) return -1;

    if (removed != NULL) {
        *removed = l->data[position];
    }

    for (int i = position; i < l->size - 1; i++) {
        l->data[i] = l->data[i + 1];
    }

    l->size--;

    return 1;
}

int list_get_at(const List *l, int position, list_type *value) {
    if (l == NULL) return -1;

    if (value == NULL) return -1;

    if (list_is_empty(l)) return -1;

    if ((position < 0) || (position >= l->size)) return -1;

    *value = l->data[position];

    return 1;
}

int list_search(const List *l, list_type value, int *position) {
    if (l == NULL) return -1;

    if (position == NULL) return -1;

    *position = -1;

    for (int i = 0; i < l->size; i++) {
        if (l->data[i] == value) {
            *position = i;
            return 1;
        }
    }

    return 0;
}

int list_clean(List *l) {
    if (l == NULL) return -1;

    l->size = 0;

    return 1;
}

int list_print(const List *l) {
    if (l == NULL) return -1;

    if (list_is_empty(l)) {
        printf("[]\n");
        return 1;
    }

    printf("[");
    for (int i = 0; i < l->size - 1; i++) {
        printf(LIST_TYPE_FORMAT, l->data[i]);
        printf(" ");
    }
    printf(LIST_TYPE_FORMAT, l->data[l->size - 1]);
    printf("]\n");

    return 1;
}