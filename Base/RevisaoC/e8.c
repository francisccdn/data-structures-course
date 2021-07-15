#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("é seu vetor.\n");

    free(p);

    return 0;
}