#include <stdlib.h>
#include "Queue.h"

#define MAX 100

struct queue {
    int data[MAX];
    int front;
    int rear;
    int qty;
};

Queue* create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) return q;

    q->front = 0;
    q->rear = 0;
    q->qty = 0;

    return q;
}

int is_empty(const Queue *q) {
    if (q == NULL) return -1;

    if (q->qty == 0) return 1;

    return 0;
}

int is_full(const Queue *q) {
    if (q == NULL) return -1;

    if (q->qty == MAX) return 1;

    return 0;
}

int enqueue(Queue *q, int value) {
    if (q == NULL) return -1;

    if (is_full(q)) return 0;

    q->data[q->rear] = value;

    q->rear++;
    if (q->rear == MAX) q->rear = 0;

    q->qty++;

    return 1;
}

int dequeue(Queue *q, int *value) {
    if (q == NULL) return -1;
    if (is_empty(q)) return 0;

    // Optional to save
    if (value != NULL) {
        *value = q->data[q->front];
    }

    q->front++;
    if (q->front == MAX) q->front = 0;

    q->qty--;

    return 1;
}

int front(const Queue *q, int *value) {
    if (q == NULL) return -1;
    if (value == NULL) return -1;

    if (is_empty(q)) return 0;

    *value = q->data[q->front];

    return 1;
}

int size(const Queue *q) {
    if (q == NULL) return -1;

    return q->qty;
}

void free_queue(Queue **q) {
    if (q == NULL) return;

    free(*q);
    *q = NULL;
}