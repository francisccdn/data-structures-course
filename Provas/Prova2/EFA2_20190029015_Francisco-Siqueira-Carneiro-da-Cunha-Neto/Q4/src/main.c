#include <stdio.h>

int mdc(unsigned int m, unsigned int n)
{
    if (n == 0)
        return m;
 
    if (n > 0)
        return mdc(n, (m % n));
    
    if (n > m)
        return mdc(n, m);
}

int main(void)
{
    int m = 0, n = 0;
    
    printf("Digite a: ");
    scanf("%d", &m);

    printf("Digite b: ");
    scanf("%d", &n);

    int r = mdc(m, n);

    printf("MDC de %d e %d = %d\n", m, n, r);

    return 0;
}