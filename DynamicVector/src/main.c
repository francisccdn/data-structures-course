#include <stdio.h>
#include "../include/vector.h"

int main(void)
{
    DynVector *vector = dv_create(5);

    while (1)
    {
        for (int i = 0; i < dv_size(vector); i++)
        {
            float val;
            if (!dv_get(vector, i, &val))
            {
                printf("\nError: No element at pos %d\n", i);
            }

            printf("%.2f ", val);
        }
        printf("\n\n");

        float newval;
        printf("\nAdd value (99 to quit, 98 to pop back): ");
        scanf("%f", &newval);

        if (newval == 99)
        {
            break;
        }
        
        if (newval == 98)
        {
            dv_pop_back(vector);
            continue;
        }

        dv_push_back(vector, newval);
    }

    dv_free(vector);

    return 0;
}