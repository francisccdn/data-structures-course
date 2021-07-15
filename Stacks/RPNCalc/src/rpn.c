#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/rpn.h"
#include "../include/stack.h"

#ifndef _RPN_C_
#define _RPN_C_

#define BUFFERSIZE 64

// Checa se o valor é um operador ou não
int is_operator(char in)
{
    if (in == '+' || in == '-' || in == 'x' || in == '*' || in == '/')
    {
        return 1;
    }
    return 0;
}

// Realiza uma das quatro operações básicas entre dois valores
int operation(float a, float b, char op, float *out)
{
    switch (op)
    {
    case '+':
        *out = a + b;
        return 1;
    case '-':
        *out = a - b;
        return 1;
    case 'x':
    case '*':
        *out = a * b;
        return 1;
    case '/':
        *out = a / b;
        return 1;
    default:
        return 0;
    }
}

// Exibe uma mensagem explicando o funcionamento
void print_hello()
{
    printf("--- Calculadora em notação polonesa reversa ---\nOperadores disponíveis: %c %c %c %c %c\n99 para sair\n\n", '+', '-', 'x', '*', '/');
    return;
}

// Roda a calculadora indefinidamente, retornando 0 caso ocorra algum erro
int calculator()
{
    print_hello();

    // Variavel para guardar código de erro que será retornado
    int noerror = 1;

    // Cria a pilha que será usada para as operações
    Stack *st = stack_create();
    if (!st)
        return 0;

    // Loop principal da calculadora rodando
    int run_calc = 1;
    while (run_calc)
    {
        // Entrada do usuário
        char buffer[BUFFERSIZE];
        fgets(buffer, BUFFERSIZE, stdin);

        // Divide a string de entrada nos valores que a compõe
        char values[BUFFERSIZE][BUFFERSIZE];
        int j = 0;
        for (int i = 0, k = 0; i < BUFFERSIZE; i++)
        {
            if (buffer[i] == ' ')
            {
                values[j][k] = '\0';
                j++;
                k = 0;
                continue;
            }

            if (buffer[i] == '\n')
            {
                values[j][k] = '\0';
                j++;
                k = 0;
                break;
            }

            values[j][k] = buffer[i];
            k++;
        }

        // Analisar cada valor que compõe a string
        for (int i = 0; i < j; i++)
        {
            char* value = values[i];

            // Se não for um operador, empilha o valor
            if (!is_operator(value[0]))
            {
                float in = atof(value);
                if (in >= 98.99 && in <= 99.01)
                {
                    run_calc = 0;
                    break;
                }

                if (!stack_push(st, in))
                {
                    run_calc = 0;
                    noerror = 0;
                    break;
                }
                continue;
            }

            // Se for um operador, desempilha os dois últimos valores e faz a operação entre eles
            float a, b;
            if (!stack_pop(st, &b) || !stack_pop(st, &a))
            {
                run_calc = 0;
                noerror = 0;
                break;
            }

            float out;
            if (!operation(a, b, value[0], &out))
            {
                run_calc = 0;
                noerror = 0;
                break;
            }

            // Empilha o resultado da operação e imprime ela no console
            if (!stack_push(st, out))
            {
                run_calc = 0;
                noerror = 0;
                break;
            }
            printf("\n%f\n", out);
        }
    }

    stack_free(st);
    return noerror;
}

#endif