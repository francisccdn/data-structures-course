#include <stdio.h>
#include "../include/expr_check.h"

int main(void)
{
    char expr[64];

    while (1)
    {
        printf("Digite sua expressao (q para sair): ");
        scanf("%s", expr);

        if (expr[0] == 'q')
            break;

        int is_valid = valid_expr(expr);

        if (is_valid == -1)
        {
            printf("Ocorreu um erro, tente novamente.\n");
            continue;
        }

        printf("A expressao %s esta balanceada? %d\n\n", expr, is_valid);
    }

    return 0;
}