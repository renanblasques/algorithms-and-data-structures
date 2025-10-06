#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct stack Stack;

Stack* create_stack();
int is_empty(Stack *s);
int is_full(Stack *s);
int push(Stack *s, int value);
int pop(Stack *s, int *value);
int peek(Stack *s, int *value);
void free_stack(Stack *s);

#endif