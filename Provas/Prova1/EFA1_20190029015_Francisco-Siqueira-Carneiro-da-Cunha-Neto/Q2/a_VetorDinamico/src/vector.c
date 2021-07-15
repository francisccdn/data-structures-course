#include <stdlib.h>
#include "../include/vector.h"

#ifndef _VECTOR_C_
#define _VECTOR_C_

// Struct da vetor dinâmico.
// Armazena um ponteiro para o primeiro elemento do vetor, a quantidade de elementos e a dimensão atual.
struct vector
{
    int n;
    int v_dim;
    float *v;
};

// Cria um novo vetor dinâmico, retornando seu endereço de memória.
DynVector *dv_create(int dim)
{
    // Alocar a memória necessária para a estrutura do vetor.
    DynVector *v = (DynVector*)malloc(sizeof(DynVector));

    if (v)
    {
        // Alocar a memória necessária para todos os elementos do vetor.
        v->v = (float*)malloc(sizeof(float) * dim);
        // Se houve um erro na alocação, retorna nulo.
        if (!v->v)
            return NULL;

        // Inicializa o vetor com 0 elementos.
        v->n = 0;
        v->v_dim = dim;
    }

    return v;
}

// Aumenta a memória alocada para os elementos do vetor, para comportar uma nova dimensão.
void redim_vetord(DynVector *vec, int dim)
{
    // Realoca a memória.
    vec->v = (float*)realloc(vec->v, sizeof(float) * dim);
    // Guarda a nova dimensão na estrutura do vetor.
    vec->v_dim = dim;
}

// Insere um novo elemento no final do vetor.
int dv_push_back(DynVector *vec, float x)
{
    // Incrementa a quantidade de elementos que estão no vetor.
    (vec->n)++;

    // Se a quantidade passa a ser maior que a dimensão do vetor
    if (vec->n >= vec->v_dim)
    {
        // Duplica a quantidade de elementos que o vetor pode guardar.
        redim_vetord(vec, vec->v_dim*2);
    }

    // Insere o elemento na última posição do vetor.
    (vec->v)[vec->n - 1] = x;

    return 1;
}

// Retorna a quantidade de elementos no vetor.
int dv_size(DynVector *vec)
{
    return vec->n;
}

// Retorna o elemento da posição desejada.
int dv_get(DynVector *vec, int pos, float *v)
{
    *v = vec->v[pos];
    return 1;
}

// Libera a memória alocada para o vetor.
void dv_free(DynVector *vec)
{
    // Libera a memória alocada para os elementos do vetor.
    free(vec->v);
    // Libera a memória alocada para a estrutura do vetor.
    free(vec);
}

#endif
