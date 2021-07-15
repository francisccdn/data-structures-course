#include <stdio.h>
#include "../include/rpn.h"

int main(void)
{
    if(!calculator())
    {
        printf("\nCalculadora encontrou um erro em sua execução.\n");
        return 1;
    }
    return 0;
}