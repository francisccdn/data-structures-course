#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 800;
    printf("\nmaca:");
    
    for (int i = 0; i < n; i++)
    {
        if (rand() % 10 >= 4)
        {
            printf("r");
        }
        else
        {
            printf("g");
        }
    }
    printf("\n");

    return 0;
}