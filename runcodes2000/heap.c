#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

struct heap {
    int *data;
    int capacity;
    int size;
};

static void heapify_up(Heap *h, int pos) {
    int current_pos = pos;

    while (current_pos > 0) {
        int parent_pos = (current_pos - 1) / 2;

        if (h->data[parent_pos] >= h->data[current_pos])
            break;

        int tmp = h->data[parent_pos];
        h->data[parent_pos] = h->data[current_pos];
        h->data[current_pos] = tmp;

        current_pos = parent_pos;
    }
}

static void heapify_down(Heap *h) {
    int current_pos = 0;

    while (1) {
        int left = current_pos * 2 + 1;
        int right = current_pos * 2 + 2;
        int largest = current_pos;

        if (left < h->size && h->data[left] > h->data[largest])
            largest = left;

        if (right < h->size && h->data[right] > h->data[largest])
            largest = right;

        if (largest == current_pos)
            break;

        int tmp = h->data[current_pos];
        h->data[current_pos] = h->data[largest];
        h->data[largest] = tmp;

        current_pos = largest;
    }
}


Heap *heap_create(int max_cap) {
    if (max_cap <= 0)
        return NULL;

    Heap *h = malloc(sizeof(Heap));
    if (h == NULL)
        return NULL;

    int *data = malloc(max_cap * sizeof(int));
    if (data == NULL) {
        free(h);
        return NULL;
    }

    h->data = data;
    h->capacity = max_cap;
    h->size = 0;

    return h;
}

int heap_insert(Heap *h, int value) {
    if (h == NULL || heap_is_full(h))
        return -1;

    h->data[h->size] = value;

    heapify_up(h, h->size);
    h->size++;

    return 1;
}

int heap_remove_max(Heap *h, int *removed) {
    if (h == NULL || heap_is_empty(h))
        return -1;

    if (removed != NULL)
        *removed = h->data[0];

    h->size--;
    h->data[0] = h->data[h->size];

    heapify_down(h);

    return 1;
}

int heap_is_empty(Heap *h) {
    if (h == NULL || h->size == 0)
        return 1;

    return 0;
}

int heap_is_full(Heap *h) {
    if (h == NULL || h->size < h->capacity)
        return 0;

    return 1;
}

void heap_destroy(Heap **h) {
    if (h == NULL || *h == NULL)
        return;

    free((*h)->data);
    free(*h);
    *h = NULL;
}