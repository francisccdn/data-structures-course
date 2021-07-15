// Construa um programa que mostre a quantidades de vezes que os caracteres de uma string aparecem.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char string[128];
    printf("Digite sua string: ");
    scanf("%s", string);

    int size;
    for (int i = 0; i < 128; i++)
    {
        if (string[i] == '\0')
        {
            size = i;
            break;
        }
    }

    int *count = (int *)malloc(size * sizeof(int));
    if (count == NULL)
    {
        printf("Memória não alocada.");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        if (count[i] == -1)
        {
            continue;
        }

        for (int j = i; j < size; j++)
        {
            if (string[i] == string[j])
            {
                count[i]++;
                if (i != j)
                {
                    count[j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (count[i] == -1)
        {
            continue;
        }

        printf("\"%c\": %d\n", string[i], count[i]);
    }

    free(count);
    return 0;
}