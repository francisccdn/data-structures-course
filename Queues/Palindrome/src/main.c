#include <stdio.h>
#include "../include/palindrome_checker.h"

int main(void)
{
    char *str;

    str = "hello world";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "arara";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "bom dia";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "aibofobia";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "!!!";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "palindromo";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "a base do teto desaba";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "never odd or even";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    str = "roma me tem amor";
    printf("A frase \"%s\" eh um palindromo? %d\n\n", str, is_palindrome(str));

    return 0;
}