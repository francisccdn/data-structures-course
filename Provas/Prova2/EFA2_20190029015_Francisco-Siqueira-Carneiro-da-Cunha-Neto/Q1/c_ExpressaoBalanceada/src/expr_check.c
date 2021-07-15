#include "../include/expr_check.h"
#include "../include/stack.h"

#ifndef _EXPR_CHECK_C_
#define _EXPR_CHECK_C_

// Retorna verdadeiro se o caractere é de fechamento
int is_closing_char(char c)
{
    if (c == ']' || c == '}' || c == ')' || c == '>')
    {
        return 1;
    }
    return 0;
}

// Retorna o caractere de abertura daquele caractere de fechamento
char get_opening_char(char c)
{
    switch (c)
    {
    case ']':
        return '[';

    case '}':
        return '{';

    case ')':
        return '(';

    case '>':
        return '<';

    default:
        return 'e';
    }
    return 'e';
}

// Retorna verdadeiro se a expressão for válida, -1 em caso de erro
int valid_expr(char* expr)
{
    // Cria pilha utilizada para avaliar a expressão
    Stack *st = stack_create();
    if (!st)
        return -1;
    
    // Percorre a string, armazenando os caracteres individuais em c
    int i = 0;
    char c = expr[i];
    while (c != '\0')
    {
        // Se o caractere é de fechamento
        if (is_closing_char(c))
        {
            // Desempilha um caractere, que deve ser a abertura de c
            char popped;
            if (!stack_pop(st, &popped))
            {
                stack_free(st);
                return -1;
            }
            
            char target = get_opening_char(c);
            if (target == 'e')
            {
                stack_free(st);
                return -1;
            }

            // Se o caractere desempilhado não é a abertura de c, a expressão não é valida
            if (popped != target)
            {
                stack_free(st);
                return 0;
            }
        }
        else
        {
            // Se ele é de abertura, empilha o caractere
            if(!stack_push(st, c))
            {
                stack_free(st);
                return -1;
            }
        }

        c = expr[++i];
    }

    // Se a pilha não está vazia ao final, não houve o fechamento de algum caractere, e a expressão é invalida
    if(!stack_is_empty(st))
    {
        stack_free(st);
        return 0;
    }
    
    // Se não saiu da função até aqui, a expressão é balanceada
    stack_free(st);
    return 1;
}

#endif