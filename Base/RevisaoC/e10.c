#include <stdio.h>
#include <stdlib.h>

void invertArray(int* ar, int size);

int main(void)
{
    int size;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &size);

    int *ar = (int *)malloc(size * sizeof(int));
    if (ar == NULL)
    {
        printf("Memória não alocada.");
        return 1;
    }


    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (ar + i));
    }

    if (invertArray(ar, size) == 1)
    {
        printf("Memória não alocada.");
        return 1;
    }

    printf("\nSer vetor invertido: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(ar + i));
    }

    free(ar);

    return 0;
}

int invertArray(int* ar, int size)
{
    int *cpy = (int *)malloc(size * sizeof(int));
    if (cpy == NULL)
    {
        printf("Memória não alocada.");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        *(cpy + i) = *(ar + i);
    }

    for (int i = 0; i < size; i++)
    {
        *(ar + (size-1) - i) = *(cpy + i);
    }

    free(cpy);
    return 0;
}