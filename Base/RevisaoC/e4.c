#include <stdio.h>
#include <math.h>

void roots(double a, double b, double c, double* r);
double delta(double a, double b, double c);

int main(int argc, char const *argv[])
{
    double a, b, c;
    
    printf("a*x^2 + b*x + c = 0\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    double* results;
    roots(a, b, c, results);

    if (isnan(*results))
    {
        printf("Não há raízes reais.\n");
        return 0;
    }

    printf("As raízes são: x' = %lf; x\" = %lf", *(results), *(results +1));
    return 0;
}

void roots(double a, double b, double c, double *r)
{
    double sqrtdel = sqrt(delta(a, b, c));
    printf("sqrtdel %lf\n", sqrtdel);

    *r = (-b + sqrtdel) / (2*a);
    *(r + 1) = (-b - sqrtdel) / (2*a);
}

double delta(double a, double b, double c)
{
    return (b*b) - (4*a*c);
}