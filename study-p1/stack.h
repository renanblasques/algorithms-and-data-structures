#ifndef stack_h
#define stack_h

#define STACK_MAX 100
#define STACK_TYPE_FORMAT "%d"

typedef struct Stack Stack;
typedef int stack_type;

Stack* stack_create();
int stack_is_empty(Stack *s);
int stack_is_full(Stack *s);
int stack_push(Stack *s, stack_type value);
int stack_pop(Stack *s, stack_type *value);
int stack_peek(Stack *s, stack_type *value);
void stack_free(Stack **s);

#endif