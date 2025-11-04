#ifndef queue_h
#define queue_h

#define QUEUE_MAX 100
#define QUEUE_TYPE_FORMAT "%d"

typedef struct Queue Queue;
typedef int queue_type;

Queue* queue_create();
int queue_is_empty(const Queue *q);
int queue_is_full(const Queue *q);
int queue_enqueue(Queue *q, queue_type value);
int queue_dequeue(Queue *q, queue_type *value);
int queue_front(const Queue *q, queue_type *value);
int queue_size(const Queue *q);
void queue_free(Queue **q);

#endif