// Construa um programa que identifique o maior e o menor número de um vetor de inteiros.

#include <stdio.h>
#include <stdlib.h>

#define MIN -999999999
#define MAX 9999999999

int max(int*, int);
int min(int*, int);

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

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (p + i));
    }

    printf("\nMaior número: %d \t Menor número: %d\n", max(p, size), min(p, size));

    free(p);

    return 0;
}

int max(int* ar, int size)
{
    int max = MIN;
    for (int i = 0; i < size; i++)
    {
        if (ar[i] > max)
        {
            max = ar[i];
        }
    }
    
    return max;
}

int min(int* ar, int size)
{
    int min = MAX;
    for (int i = 0; i < size; i++)
    {
        if (ar[i] < min)
        {
            min = ar[i];
        }
    }
    
    return min;
}