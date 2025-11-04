#include <stdlib.h>
#include "queue.h"

struct Queue {
    queue_type data[QUEUE_MAX];
    int front;
    int rear;
    int size;
};

Queue* queue_create() {
    Queue *q = malloc(sizeof(Queue));

    if (q == NULL) return NULL;

    q->front = q->rear = q->size = 0;

    return q;
}

int queue_is_empty(const Queue *q) {
    if (q == NULL) return -1;

    if (q->size == 0) return 1;

    return 0;
}

int queue_is_full(const Queue *q) {
    if (q == NULL) return -1;

    if (q->size == QUEUE_MAX) return 1;

    return 0;
}

int queue_enqueue(Queue *q, queue_type value) {
    if (q == NULL) return -1;

    if (queue_is_full(q)) return 0;

    q->data[q->rear] = value;
    
    q->rear++;
    if (q->rear == QUEUE_MAX) q->rear = 0;
    
    q->size++;

    return 1;
}

int queue_dequeue(Queue *q, queue_type *value) {
    if (q == NULL) return -1;

    if (queue_is_empty(q)) return 0;

    if (value != NULL) *value = q->data[q->front];

    q->front++;
    if (q->front == QUEUE_MAX) q->front = 0;

    q->size--;

    return 1;
}

int queue_front(const Queue *q, queue_type *value) {
    if (q == NULL) return -1;

    if (value == NULL) return -1;

    if (queue_is_empty(q)) return 0;

    *value = q->data[q->front];

    return 1;
}

int queue_size(const Queue *q) {
    if (q == NULL) return -1;

    return q->size;
}

void queue_free(Queue **q) {
    if (q == NULL) return;
    if (*q == NULL) return;

    free(*q);
    *q = NULL;
}