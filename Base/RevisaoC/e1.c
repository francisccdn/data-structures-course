#include "stdio.h"

#define PI 3.14159265359

int main(void)
{
  double radius;

  printf("Digite o raio do circulo: ");
  scanf("%lf", &radius);

  double area = PI * radius * radius;

  printf("A área é: %lf\n", area);

  return 0;
}
