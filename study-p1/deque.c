#include <stdlib.h>
#include "deque.h"

struct Deque {
    deque_type data[DEQUE_MAX];
    int front;
    int back;
    int size;
};

Deque* deque_create(void) {
    Deque *dq = malloc(sizeof(Deque));
    if (dq == NULL) return NULL;

    dq->front = 0;
    dq->back = 0;
    dq->size = 0;

    return dq;
}

int deque_is_empty(const Deque *dq) {
    if (dq == NULL) return -1;

    return (dq->size == 0);
}

int deque_is_full(const Deque *dq) {
    if (dq == NULL) return -1;

    return (dq->size == DEQUE_MAX);
}

int deque_size(const Deque *dq) {
    if (dq == NULL) return -1;

    return (dq->size);
}

int deque_push_front(Deque *dq, deque_type value) {
    if (dq == NULL) return -1;

    if (deque_is_full(dq)) return 0;

    if (dq->size == 0) {
        dq->front = 0;
        dq->back = 0;
    } else {
        dq->front--;
        if (dq->front < 0) dq->front = DEQUE_MAX - 1;
    }

    dq->data[dq->front] = value;
    dq->size++;

    return 1;
}

int deque_push_back(Deque *dq, deque_type value) {
    if (dq == NULL) return -1;

    if (deque_is_full(dq)) return 0;

    if (dq->size == 0) {
        dq->front = 0;
        dq->back = 0;
    } else {
        dq->back++;
        if (dq->back == DEQUE_MAX) dq->back = 0;
    }

    dq->data[dq->back] = value;
    dq->size++;

    return 1;
}

int deque_pop_front(Deque *dq, deque_type *value) {
    if (dq == NULL) return -1;

    if (deque_is_empty(dq)) return 0;

    if (value != NULL) {
        *value = dq->data[dq->front];
    }

    dq->front++;
    if (dq->front == DEQUE_MAX) dq->front = 0;

    dq->size--;

    return 1;
}

int deque_pop_back(Deque *dq, deque_type *value) {
    if (dq == NULL) return -1;

    if (deque_is_empty(dq)) return 0;

    if (value != NULL) {
        *value = dq->data[dq->back];
    }

    dq->back--;
    if (dq->back < 0) dq->back = DEQUE_MAX - 1;

    dq->size--;

    return 1;
}

int front(const Deque *dq, deque_type *value) {
    if (dq == NULL || !value) return -1;

    if (deque_is_empty(dq)) return 0;

    *value = dq->data[dq->front];

    return 1;
}

int back(const Deque *dq, deque_type *value) {
    if (dq == NULL || !value) return -1;

    if (deque_is_empty(dq)) return 0;

    *value = dq->data[dq->back];

    return 1;
}

void free_deque(Deque **dq) {
    if (dq == NULL || *dq == NULL) return;

    free(*dq);
    *dq = NULL;
}