#include <stdlib.h>
#include "Stack.h"

/*  Return 
     1  -> Success
     0  -> Expected fail
    -1  -> Unexpected error
*/

struct stack {
    int data[MAX];
    int qty;
};

Stack* create_stack() {
    Stack* s = malloc(sizeof(Stack));
    if (s == NULL) return NULL;

    s->qty = 0;

    return s;
}

int is_empty(Stack *s) {
    if (s == NULL) return -1;
    if (s->qty == 0) return 1;

    return 0;
}

int is_full(Stack *s) {
    if (s == NULL) return -1;
    if (s->qty == MAX) return 1;

    return 0;
}

int push(Stack *s, int value) {
    if (s == NULL) return -1;

    if (!is_full(s)) {
        s->data[s->qty] = value;
        s->qty++;

        return 1;
    }

    return 0;
}

int pop(Stack *s, int *value) {
    if (s == NULL) return -1;
    if (value == NULL) return -1;

    if (!is_empty(s)) {
        *value = s->data[s->qty - 1];
        s->qty--;

        return 1;
    }

    return 0;
}

int peek(Stack *s, int *value) {
    if (s == NULL) return -1;

    if (!is_empty(s)) {
        *value = s->data[s->qty - 1];

        return 1;
    }

    return 0;
}

void free_stack(Stack **s) {
    if (s == NULL) return -1;

    free(*s);
    *s = NULL;
}