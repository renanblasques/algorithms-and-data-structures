#ifndef DEQUE_H
#define DEQUE_H

#define DEQUE_MAX 100

typedef struct Deque Deque;
typedef int deque_type;

Deque* deque_create(void);
int deque_is_empty(const Deque *dq);
int deque_is_full(const Deque *dq);
int deque_size(const Deque *dq);

int deque_push_front(Deque *dq, deque_type value);
int deque_push_back(Deque *dq, deque_type value);
int deque_pop_front(Deque *dq, deque_type *value);
int deque_pop_back(Deque *dq, deque_type *value);

int front(const Deque *dq, deque_type *value);
int back(const Deque *dq, deque_type *value);

void free_deque(Deque **dq);

#endif

