#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = (int*)malloc(sizeof(int));

    scanf("%d", ptr);
    printf("Num %d\n", *ptr);

    return 0;
}