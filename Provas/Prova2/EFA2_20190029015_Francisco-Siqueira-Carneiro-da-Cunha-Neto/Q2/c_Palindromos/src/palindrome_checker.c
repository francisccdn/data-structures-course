#include "../include/queue.h"
#include "../include/stack.h"
#include <stdio.h>

#ifndef _PALINDROME_CHECKER_C_
#define _PALINDROME_CHECKER_C_

// Checa se uma frase é um palindromo
int is_palindrome(char *str)
{
    // Fila para checar os caracteres de frente pra trás
    Queue *q = q_create();
    // Pilha para checar os caracteres de trás pra frente
    Stack *s = stack_create();

    // Enfileira e empilha cada caractere da frase
    int i = 0;
    char c = str[i];
    while (c != '\0')
    {
        c = str[i++];
        // Não enfileira o caractere espaço ou nulo
        if (c == ' ' || c == '\0')
            continue;

        if (!q_enqueue(q, c))
        {
            printf("Falha ao enfileirar caractere %c\n", c);
            q_free(q);
            stack_free(s);
            return -1;
        }
        if (!stack_push(s, c))
        {
            printf("Falha ao empilhar caractere %c\n", c);
            q_free(q);
            stack_free(s);
            return -1;
        }
    }

    // Desenfileira e desemplilha ao mesmo tempo
    while (!q_is_empty(q))
    {
        char queue_c;
        if (!q_dequeue(q, &queue_c))
        {
            printf("Falha ao desenfileirar caractere %c\n", queue_c);
            q_free(q);
            stack_free(s);
            return -1;
        }

        char stack_c;
        if (!stack_pop(s, &stack_c))
        {
            printf("Falha ao desempilhar caractere %c\n", stack_c);
            q_free(q);
            stack_free(s);
            return -1;
        }

        // Se forem diferentes, não é palindromo
        if (stack_c != queue_c)
        {
            q_free(q);
            stack_free(s);
            return 0;
        }
    }

    q_free(q);
    stack_free(s);
    // Se passou do loop anterior, é um palindromo
    return 1;
}

#endif