#include <stdio.h>
#include "../include/heap.h"

int main(void)
{
    int dim = 0;
    printf("Qual a altura máxima do seu heap? ");
    scanf("%d", &dim);

    int firstdata = -99;
    printf("\nDigite um numero para adicionar ao heap: ");
    scanf("%d", &firstdata);

    Heap *t = heap_create(dim, firstdata);

    if (t == NULL)
    {
        printf("Erro na criação do heap\n");
        heap_free(t);
        return 1;
    }

    while (1)
    {
        printf("\nHeap\n");
        printf("Representação de parentese: ");
        heap_print_parenthesis(t);
        printf("\nRepresentação de barras:\n");
        heap_print_bars(t);
 
        int data = -99;
        printf("\nDigite um numero para adicionar ao heap (-99 para sair): ");
        scanf("%d", &data);

        if (data == -99)
        {
            break;
        }

        if (!heap_insert(t, data))
        {
            printf("Erro ao inserir %d\n", data);
        }
    }
    
    heap_free(t);

    return 0;
}