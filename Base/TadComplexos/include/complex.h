#pragma once

typedef struct complex Complex;

Complex *make_complex(const float a, const float b);
void free_complex(Complex *c);
int get_complex(const Complex *c, float *a, float *b);
int set_complex(Complex *c, const float a, const float b);
Complex *sum_complex(Complex *x, Complex *y);
Complex *sub_complex(Complex *x, Complex *y);
Complex *mul_complex(Complex *x, Complex *y);
Complex *div_complex(Complex *x, Complex *y);
void print_complex(Complex *c);
