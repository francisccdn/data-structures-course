#include <stdio.h>
#include "../include/expr_check.h"

int main(void)
{
    char *expr;

    expr = "[()()]";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));
    
    expr = "[([])]";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));
    
    expr = "[(])";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));
    
    expr = "[)()(]";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));

    expr = "[{()()}{}]";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));

    expr = "[{()()}{}]{";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));

    expr = "[{()()}{}]{<>(())}";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));

    expr = "[{()(()}{}]";
    printf("A expressao %s esta balanceada? %d\n\n", expr, valid_expr(expr));

    return 0;
}