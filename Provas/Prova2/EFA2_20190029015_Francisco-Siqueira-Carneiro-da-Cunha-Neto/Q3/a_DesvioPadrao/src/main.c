#include <stdio.h>
#include <math.h>

float standart_deviation(float *ar, int size)
{
    float mean = 0;
    for (int i = 0; i < size; i++)
    {      
        mean += ar[i];
    }
    mean /= size;

    float sum = 0;
    for (int i = 0; i < size; i++)
    {      
        sum += (ar[i] - mean) * (ar[i] - mean);
    }   

    return sqrt(sum / size);
}

int main(void)
{
    int ar_size = 0;
    printf("Tamanho do vetor: ");
    scanf("%d", &ar_size);

    float ar[ar_size];

    for (int i = 0; i < ar_size; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%f", &ar[i]);
    }
    
    printf("\nVetor: ");
    for (int i = 0; i < ar_size; i++)
    {
        printf("%.2f ", ar[i]);
    }
    
    float sd = standart_deviation(ar, ar_size);
    printf("\nDesvio padrao: %f\n", sd);
    
    return 0;
}