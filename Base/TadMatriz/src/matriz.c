#include <stdlib.h>
#include "../include/matriz.h"

#ifndef _matriz_c_
#define _matriz_c_

struct matriz
{
    float **p;
    int ncol;
    int nrow;
};

Matriz *cria_matriz(int nl, int nc)
{
    Matriz *m = (Matriz *)malloc(sizeof(Matriz));

    m->ncol = nc;
    m->nrow = nl;

    m->p = (float **)malloc(nl * sizeof(float *));

    if (m->p == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < nl; i++)
    {
        *(m->p + i) = (float *)malloc(nc * sizeof(float));

        if (*(m->p + i) == NULL)
        {
            return NULL;
        }
    }

    return m;
}

void libera_matriz(Matriz *mat)
{
    for (int i = 0; i < mat->nrow; i++)
    {
        free(*(mat->p + i));
    }
    free(mat->p);
    free(mat);
}

int acessa_matriz(Matriz *mat, int i, int j, float *v)
{
    if (mat->p[i] + j == NULL)
    {
        return 2;
    }

    *v = mat->p[i][j];
    return 0;
}

int atribui_matriz(Matriz *mat, int i, int j, float *v)
{
    mat->p[i][j] = *v;

    if (mat->p[i] + j == NULL)
    {
        return 2;
    }
    return 0;
}

int nlinhas(Matriz *mat)
{
    return mat->nrow;
}

int ncolunas(Matriz *mat)
{
    return mat->ncol;
}

#endif