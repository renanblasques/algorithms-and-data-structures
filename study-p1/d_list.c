#include <stdio.h>
#include <stdlib.h>
#include "d_list.h"

struct DList {
    d_list_type *data;
    int size;
    int capacity;
};

DList *d_list_create(void) {
    DList *l = malloc(sizeof(DList));

    if (l == NULL) return l;

    l->data = NULL;
    l->size = 0;
    l->capacity = 0;

    return l;
}

int d_list_destroy(DList **l) {
    if (l == NULL) return -1;

    if (*l == NULL) return 0;

    free((*l)->data);
    free(*l);

    *l = NULL;

    return 1;
}

int d_list_is_empty(const DList *l) {
    if (l == NULL) return -1;

    if (l->size == 0) return 1;

    return 0;
}

int d_list_size(const DList *l) {
    if (l == NULL) return -1;

    return l->size;
}

int d_list_capacity(const DList *l) {
    if (l == NULL) return -1;

    return l->capacity;
}

int d_list_insert_at_end(DList *l, d_list_type value) {
    if (l == NULL) return -1;

    if (d_list_ensure_capacity(l) == -1) return -1;

    l->data[l->size] = value;
    l->size++;

    return 1;
}

int d_list_insert_at(DList *l, int position, d_list_type value) {
    if (l == NULL) return -1;

    if (d_list_ensure_capacity(l) == -1) return -1;

    if ((position < 0) || (position > l->size)) return -1;

    for (int i = l->size; i > position; i--) {
        l->data[i] = l->data[i - 1];
    }

    l->data[position] = value;
    l->size++;

    return 1;
}

int d_list_remove_at(DList *l, int position, d_list_type *removed) {
    if (l == NULL) return -1;

    if (d_list_is_empty(l) == 1) return -1;

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

int d_list_get_at(const DList *l, int position, d_list_type *value) {
    if (l == NULL) return -1;

    if (value == NULL) return -1;

    if (d_list_is_empty(l)) return -1;

    if ((position < 0) || (position >= l->size)) return -1;

    *value = l->data[position];

    return 1;
}

int d_list_search(const DList *l, d_list_type value, int *position) {
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

int d_list_clean(DList *l) {
    if (l == NULL) return -1;

    l->size = 0;

    return 1;
}

int d_list_print(const DList *l) {
    if (l == NULL) return -1;

    if (d_list_is_empty(l)) {
        printf("[]\n");
        return 1;
    }

    printf("[");
    for (int i = 0; i < l->size - 1; i++) {
        printf(D_LIST_TYPE_FORMAT, l->data[i]);
        printf(" ");
    }
    printf(D_LIST_TYPE_FORMAT, l->data[l->size - 1]);
    printf("]\n");

    return 1;
}


int d_list_ensure_capacity(DList *l) {
    if (l == NULL) return -1;

    if (l->size < l->capacity) return 1;

    int new_capacity;

    if (l->capacity == 0) {
        new_capacity = 4;
    } else {
        new_capacity = l->capacity * 2;
    }

    d_list_type *new_data = realloc(l->data, new_capacity * sizeof(d_list_type));

    if (new_data == NULL) return -1;

    l->data = new_data;
    l->capacity = new_capacity;

    return 1;
}