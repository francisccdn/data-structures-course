#include <stdio.h>
#include <math.h>

void isPrime(int);

int main(void)
{
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    isPrime(n);
    return 0;
}

void isPrime(int n)
{
    int prime = 1;

    int rt = sqrt(n);
    for (int i = 2; i <= rt; i++)
    {
        if (n % i == 0)
        {
            prime = 0;
            break;
        }
    }

    if (prime)
    {
        printf("%d é primo.\n", n);
    }
    else
    {
        printf("%d não é primo.\n", n);
    }
}