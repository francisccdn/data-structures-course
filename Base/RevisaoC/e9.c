#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size[2];
    printf("Qual o tamanho da matriz?\n");
    scanf("%d%d", &size[0], &size[1]);

    int **p = (int **)malloc(size[0] * sizeof(int *));
    if (p == NULL)
    {
        printf("Memória não alocada.");
        return 1;
    }

    for (int i = 0; i < size[0]; i++)
    {
        *(p + i) = (int *)malloc(size[1] * sizeof(int));
        if ((p + i) == NULL)
        {
            printf("Memória não alocada.");
            return 1;
        }
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            printf("Elemento %dx%d: ", i, j);
            scanf("%d", &p[i][j]);
        }
    }

    printf("\n\nSua matriz é:\n");
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size[0]; i++)
    {
        free(p[i]);
    }
    free(p);

    return 0;
}