#include <stdio.h>
#include "Queue.h"

int try_deq3(Queue *q1, Queue *q2);
int try_remove(Queue *first, Queue *second);

int main() {
    Queue *q1, *q2;
    q1 = create_queue();
    q2 = create_queue();

    if ((q1 == NULL) || (q2 == NULL)) {
        printf("Erro ao criar filas.\n");
        return 1;
    }

    int option = 0;
    do {
        scanf("%d", &option);
        switch (option) {
        case 1: {
            int value;
            scanf("%d", &value);
            enqueue(q1, value);
            break;
        }
        case 2: {
            int value;
            scanf("%d", &value);
            enqueue(q2, value);
            break;
        }
        case 3: {
            try_deq3(q1, q2);
            break;
        }
        default:
            break;
        }
    } while (option != 0);
    free_queue(&q1);
    free_queue(&q2);

    return 0;
}

int try_remove(Queue *first, Queue *second) {
    if ((first == NULL) || (second == NULL)) return -1;

    int number;

    if (dequeue(first, &number)) {
        printf("%d\n", number);
        return 1;
    } else if (dequeue(second, &number)) {
        printf("%d\n", number);
        return 1;
    }

    return 0;
}

int try_deq3(Queue *q1, Queue *q2) {
    if (q1 == NULL) return -1;
    if (q2 == NULL) return -1;

    try_remove(q2, q1);
    try_remove(q2, q1);
    try_remove(q1, q2);

    return 1;
}