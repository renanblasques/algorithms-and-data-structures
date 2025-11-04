#include "stack.h"
#include <stdlib.h>

struct Stack {
    stack_type data[STACK_MAX];
    int size;
};

Stack* stack_create() {
    Stack *s = malloc(sizeof(Stack));

    if (s == NULL) return s;

    s->size = 0;

    return s;
}

int stack_is_empty(Stack *s) {
    if (s == NULL) return -1;

    if (s->size == 0) return 1;

    return 0;
}

int stack_is_full(Stack *s) {
    if (s == NULL) return -1;

    if (s->size == STACK_MAX) return 1;

    return 0;
}

int stack_push(Stack *s, stack_type value) {
    if (s == NULL) return -1;

    if (stack_is_full(s)) return 0;

    s->data[s->size] = value;
    s->size++;

    return 1;
}

int stack_pop(Stack *s, stack_type *value) {
    if (s == NULL) return -1;

    if (stack_is_empty(s)) return 0;

    if (value != NULL) {
        *value = s->data[s->size - 1];
    }

    s->size--;

    return 1;
}

int stack_peek(Stack *s, stack_type *value) {
    if (s == NULL) return -1;

    if (value == NULL) return -1;

    if (stack_is_empty(s)) return 0;

    *value = s->data[s->size - 1];

    return 1;
}

void stack_free(Stack **s) {
    if (s == NULL) return;
    if (*s == NULL) return;

    free(*s);
    *s = NULL;
}