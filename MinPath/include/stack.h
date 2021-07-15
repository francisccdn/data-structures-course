#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack Stack;

Stack* stack_create();
int stack_push(Stack* stack, int value);
int stack_pop(Stack* stack, int *data);
int stack_peek(Stack* stack, int *data);
int stack_is_empty(Stack* stack);
void stack_free(Stack* stack);

#endif