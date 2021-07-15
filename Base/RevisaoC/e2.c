#include "stdio.h"

int main(void)
{
    int n;
    printf("Digite o número: ");
    scanf("%d", &n);

    char* paridade = n % 2 == 0 ? "par" : "impar";

    printf("%d é %s\n", n, paridade);

    return 0;
}
