#include <stdio.h>
#include <string.h>
#include "../include/palindrome_checker.h"

int main(void)
{
    char str[64];

    while (1)
    {
        printf("Digite sua frase (q para sair): ");
        fgets(str, 64, stdin);
        strtok(str, "\n");

        if (str[0] == 'q')
            break;

        int palindrome = is_palindrome(str);

        if (palindrome == -1)
        {
            printf("Ocorreu um erro, tente novamente.\n");
            continue;
        }

        printf("A frase \"%s\" eh um palindromo? %d\n\n", str, palindrome);
    }

    return 0;
}