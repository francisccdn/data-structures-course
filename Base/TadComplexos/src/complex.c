#include <stdlib.h>
#include <stdio.h>
#include "../include/complex.h"

#ifndef _complex_c_
#define _complex_c_

struct complex
{
    float a;
    float b;
};

Complex *make_complex(const float a, const float b)
{
    Complex *c = (Complex *)malloc(sizeof(Complex));

    c->a = a;
    c->b = b;

    return c;
}

void free_complex(Complex *c)
{
    free(c);
}

int get_complex(const Complex *c, float *a, float *b)
{
    *a = c->a;
    *b = c->b;
}

int set_complex(Complex *c, const float a, const float b)
{
    c->a = a;
    c->b = b;
}

Complex *sum_complex(Complex *x, Complex *y)
{
    return make_complex(x->a + y->a, x->b + y->b);
}

Complex *sub_complex(Complex *x, Complex *y)
{
    return make_complex(x->a + y->a, x->b + y->b);
}

Complex *mul_complex(Complex *x, Complex *y)
{
    float a = (x->a * y->a) - (x->b * y->b);
    float b = (x->b * y->a) + (x->a * y->b);
    return make_complex(a, b);
}

Complex *div_complex(Complex *x, Complex *y)
{
    float a = ((x->a * y->a) + (x->b * y->b))/((y->a * y->a) + (y->b * y->b));
    float b = ((x->b * y->a) - (x->a * y->b))/((y->a * y->a) + (y->b * y->b));
    return make_complex(a, b);
}

void print_complex(Complex *c)
{
    printf("(%.2f + %.2fi)", (c->a), (c->b));
}

#endif