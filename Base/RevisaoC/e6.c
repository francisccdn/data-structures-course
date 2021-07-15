#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Digite os dois numeros:\n");
    scanf("%d%d", &a, &b);

    int sum = 0;
    while (a <= b)
    {
        sum += a++;
    }

    printf("Soma: %d\n", sum);
    return 0;
}