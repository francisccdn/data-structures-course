#include <stdio.h>
#include "../include/dectobin.h"

int main(void)
{
    while (1)
    {
        int n;
        printf("\nDigite o numero decimal (negativos para sair): ");
        scanf("%d", &n);

        if (n < 0)
            break;

        if(!printbin(n))
        {
            printf("\nErro ao converter %d para binario.", n);
        }
    }
    
    return 0;
}