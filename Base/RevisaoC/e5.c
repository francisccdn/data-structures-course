#include <stdio.h>

void usingWhile(int, int);
void usingDoWhile(int, int);
void usingFor(int, int);

int main(void)
{
    int a, b;
    printf("Digite dois números:\n");
    scanf("%d%d", &a, &b);

    usingFor(a, b);
    printf("\n");
    usingWhile(a, b);
    printf("\n");
    usingDoWhile(a, b);
    printf("\n");

    return 0;
}

void usingWhile(int a, int b)
{
    while (a <= b)
    {
        printf("%d ", a++);
    }
}

void usingDoWhile(int a, int b)
{
    do
    {
        printf("%d ", a++);
    } while (a <= b);
}

void usingFor(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        printf("%d ", i);
    }
    
}