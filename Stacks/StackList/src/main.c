#include <stdio.h>
#include "../include/stack.h"

int main(void)
{
    Stack *stack = stack_create();

    while (1)
    {
        float val;
        if (stack_peek(stack, &val))
        {
            printf("Topo da pilha: %.2f\n", val);
        }
        else
        {
            if (stack_is_empty(stack))
            {
                printf("Pilha está vazia.\n");
            }
            else
            {
                printf("Ocorreu um erro.\n");
            }
        }

        printf("\n");

        float newval;
        printf("\nEmpilhar valor (99 para sair ou 98 para desempilhar): ");
        scanf("%f", &newval);

        if (newval == 99)
        {
            break;
        }

        if (newval == 98)
        {
            float popped;
            if (stack_pop(stack, &popped))
            {
                printf("Desempilhado: %.2f\n", popped);
            }
            else
            {
                printf("Não pôde desempilhar (pilha vazia).\n");
            }

            continue;
        }

        if (!stack_push(stack, newval))
        {
            printf("Não pôde empilhar valor.\n");
        }
    }

    stack_free(stack);

    return 0;
}