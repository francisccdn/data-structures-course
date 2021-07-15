#include<stdio.h>

#include "../include/matriz.h"

int main(void)
{
    Matriz* minha_matriz = cria_matriz(3, 4);

    for (int i = 0; i < nlinhas(minha_matriz); i++)
    {
        for (int j = 0; j < ncolunas(minha_matriz); j++)
        {
            float v = (i+j);
            atribui_matriz(minha_matriz, i, j, &v);
        }
    }
    
    printf("Matriz:");
    for (int i = 0; i < nlinhas(minha_matriz); i++)
    {
        printf("\n");
        for (int j = 0; j < ncolunas(minha_matriz); j++)
        {
            float v;
            acessa_matriz(minha_matriz, i, j, &v);
            printf("%f ", v);
        }
    }
    
    libera_matriz(minha_matriz);

    return 0;
}