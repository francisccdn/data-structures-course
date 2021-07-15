#include <stdio.h>
#include "../include/stack.h"

#ifndef _DECTOBIN_C_
#define _DECTOBIN_C_

int printbin(int n)
{
    int dec = n;

    Stack *st = stack_create();
    if (!st)
        return 0;

    while (dec != 0)
    {
        int b = dec % 2;
        stack_push(st, b);

        dec = dec / 2;
    }

    printf("\n%d in binary: ", n);
    while (!stack_is_empty(st))
    {
        char b;
        if(!stack_pop(st, &b))
            return 0;

        printf("%d", b);
    }
    printf("\n");

    stack_free(st);
    return 1;
}

#endif