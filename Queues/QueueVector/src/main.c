#include <stdio.h>
#include "../include/queue.h"

int main(void)
{
    Queue *q = q_create();

    while (1)
    {
        float val;
        if (q_peek(q, &val))
        {
            printf("Começo da fila: %.2f\n", val);
        }
        else
        {
            if (q_is_empty(q))
            {
                printf("Fila está vazia.\n");
            }
            else
            {
                printf("Ocorreu um erro.\n");
            }
        }

        printf("\n");

        float newval;
        printf("\nEnfileirar valor (99 para sair ou 98 para desenfileirar): ");
        scanf("%f", &newval);

        if (newval == 99)
        {
            break;
        }

        if (newval == 98)
        {
            float dequeued;
            if (q_dequeue(q, &dequeued))
            {
                printf("Desenfileirado: %.2f\n", dequeued);
            }
            else
            {
                printf("Não pôde desenfileirar (fila vazia).\n");
            }

            continue;
        }

        if (!q_enqueue(q, newval))
        {
            printf("Não pôde enfileirar valor.\n");
        }
    }

    q_free(q);

    return 0;
}