#include <stdlib.h>

#include "../include/vector.h"
#include "../include/stack.h"

#ifndef _STACK_C_
#define _STACK_C_

// Struct da pilha
// Armazena o vetor sobre o qual a pilha vai ser construida
struct stack
{
    DynVector *vec;
};

// Cria uma nova pilha, retornando seu endereço de memória
// O(1)
Stack* stack_create()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    // Se a memória foi alocada com sucesso
    if (stack)
    {
        // Cria o vetor da pilha com dimensão 2
        stack->vec = dv_create(2);

        // Se o vetor não pôde ser criado, retorna nulo
        if (!stack->vec)
            return NULL;
    }

    return stack;
}

// Insere um elemento na pilha
// O(n) -- Realloc no pior caso
int stack_push(Stack* stack, float data)
{
    // Insere um elemento ao final do vetor da pilha
    dv_push_back(stack->vec, data);
    return 1;
}

// Remove um elemento da pilha, retornando seu valor
// O(1)
int stack_pop(Stack* stack, float *data)
{
    // Pega o elemento no topo da lista, retornando falso se isso falhar
    if (!stack_peek(stack, data))
        return 0;

    // Remove o elemento no topo da lista
    dv_pop_back(stack->vec);
    return 1;
}

// Retorna o valor do elemento no topo da pilha
// O(1)
int stack_peek(Stack* stack, float *data)
{
    // Não há elementos para retornar caso a pilha esteja vazia
    if (stack_is_empty(stack))
        return 0;

    dv_get(stack->vec, dv_size(stack->vec) - 1, data);
    return 1;
}

// Checa se a pilha está vazia
// O(1)
int stack_is_empty(Stack* stack)
{
    return (dv_size(stack->vec) == 0);
}

// Libera a memória alocada para a pilha
// O(1)
void stack_free(Stack* stack)
{
    dv_free(stack->vec);
    free(stack);
}

#endif