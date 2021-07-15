#include <stdlib.h>

#include "../include/linkedlist.h"
#include "../include/stack.h"

#ifndef _STACK_C_
#define _STACK_C_

// Struct da pilha
// Armazena a lista sobre a qual a pilha vai ser construida
struct stack
{
    LinkedList *list;
};

// Cria uma nova pilha, retornando seu endereço de memória
Stack* stack_create()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    // Se a memória foi alocada com sucesso
    if (stack)
    {
        // Cria a lista da pilha
        stack->list = ll_create_list();

        // Se a lista não pôde ser criado, retorna nulo
        if (!stack->list)
            return NULL;
    }

    return stack;
}

// Insere um elemento na pilha
int stack_push(Stack* stack, char data)
{
    // Insere um elemento ao inicio da lista da pilha
    return ll_insert_first(stack->list, data);
}

// Remove um elemento da pilha, retornando seu valor
int stack_pop(Stack* stack, char *data)
{
    // Pega o elemento no topo da lista, retornando falso se isso falhar
    if (!stack_peek(stack, data))
        return 0;

    // Remove o elemento no topo da lista
    ll_remove_first(stack->list);
    return 1;
}

// Retorna o valor do elemento no topo da pilha
int stack_peek(Stack* stack, char *data)
{
    // Não há elementos para retornar caso a pilha esteja vazia
    if (stack_is_empty(stack))
        return 0;

    *data = ll_first(stack->list);
    return 1;
}

// Checa se a pilha está vazia
int stack_is_empty(Stack* stack)
{
    return ll_is_empty(stack->list);
}

// Libera a memória alocada para a pilha
void stack_free(Stack* stack)
{
    ll_free(stack->list);
    free(stack);
}

#endif