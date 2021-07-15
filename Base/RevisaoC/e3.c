#include "stdio.h"

float getFourthScore(float avg)
{
    return (7*4) - (avg*3);
}

int main(void)
{
    float n[3];
    printf("Digite suas 3 notas:\n");
    scanf("%f%f%f", &n[0], &n[1], &n[2]);

    float avg = 0;
    for (size_t i = 0; i < 3; i++)
    {
        avg += n[i];
    }
    avg /= 3;
    
    if (avg >= 7.0)
    {
        printf("APROVADO com média %f.\n", avg);
        return 0;
    }

    float needs = getFourthScore(avg);

    if (needs > 10.0)
    {
        printf("Você está REPROVADO com média %f.\n", avg);

        return 0;
    }

    printf("Sua média é %f, está de RECUPERAÇÃO.\n", avg);
    printf("Você precisa tirar %f na sua 4a prova para passar.\n", needs);
    
    return 0;
}
