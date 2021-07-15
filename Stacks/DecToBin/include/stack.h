#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack Stack;

Stack* stack_create();
int stack_push(Stack* stack, char value);
int stack_pop(Stack* stack, char *data);
int stack_peek(Stack* stack, char *data);
int stack_is_empty(Stack* stack);
void stack_free(Stack* stack);

#endif