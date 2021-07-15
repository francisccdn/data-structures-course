#include <stdio.h>
#include <stdlib.h>

void printVector(int *, int);

int main(void)
{
    int size;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &size);

    int *p = (int *)malloc(size * sizeof(int));
    if (p == NULL)
    {
        printf("Memória não alocada.");
        return 1;
    }

    printf("Digite o elemento: ");
    scanf("%d", (p + size - 1));
    for (int i = 0; i < size - 1; i++)
    {
        *(p + i) = 0;
    }

    for (int i = size - 1; i > 0; i--)
    {
        printVector(p, size);
        *(p + i - 1) = *(p + i);
        *(p + i) = 0;
    }

    printVector(p, size);

    free(p);

    return 0;
}

void printVector(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}