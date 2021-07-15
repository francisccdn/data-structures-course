#include <stdio.h>
#include <stdlib.h>
#include "../include/heap.h"

#ifndef _HEAP_C_
#define _HEAP_C_

// Struct da arvore binaria
struct bintree
{
    int dim;
    int *vec;
};

// Cria uma nova arvore
Heap *heap_create(int max_h, int data)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));

    if (heap == NULL)
        return NULL;

    int dim = 0;
    for (int i = 0; i < max_h; i++)
    {
        dim = (2 * dim) + 2;
    }
    dim++;

    heap->dim = dim;
    heap->vec = (int *)malloc(sizeof(int) * dim);

    if (heap->vec == NULL)
        return NULL;

    heap->vec[0] = data;
    for (int i = 1; i < dim; i++)
    {
        heap->vec[i] = -99;
    }

    return heap;
}

// Imprime uma subarvore por um diagrama de barras
void subheap_print_bars(Heap *heap, int parent_height, int pos)
{
    if (pos >= heap->dim)
        return;
        
    if (heap->vec[pos] == -99)
        return;

    int h = parent_height - 1;
    for (int i = 0; i < h; i++)
    {
        printf("-");
    }
    printf(" %d\n", heap->vec[pos]);
    subheap_print_bars(heap, h, (pos * 2) + 1);
    subheap_print_bars(heap, h, (pos * 2) + 2);
}

// Imprime a arvore por um diagrama de barras
void heap_print_bars(Heap *heap)
{
    if (heap == NULL)
        return;

    int pos = 0;
    int h = heap_height(heap);
    for (int i = 0; i < h; i++)
    {
        printf("-");
    }
    printf(" %d\n", heap->vec[pos]);
    subheap_print_bars(heap, h, (pos * 2) + 1);
    subheap_print_bars(heap, h, (pos * 2) + 2);
}

void subheap_print_parenthesis(Heap *heap, int pos)
{
    if (heap == NULL || pos >= heap->dim)
        return;

    if (heap->vec[pos] == -99)
        return;

    printf(" (%d", heap->vec[pos]);
    subheap_print_parenthesis(heap, (pos * 2) + 1);
    subheap_print_parenthesis(heap, (pos * 2) + 2);
    printf(")");
}

void heap_print_parenthesis(Heap *heap)
{
    subheap_print_parenthesis(heap, 0);
}

// Libera a memoria alocada para a arvore
void heap_free(Heap *heap)
{
    if (heap == NULL)
        return;

    free(heap->vec);
    free(heap);
}

// Checa se a subarvore contem o dado informado
int subheap_exists(Heap *heap, int data, int pos)
{
    if (pos >= heap->dim)
        return 0;

    if (heap->vec[pos] == -99)
        return 0;

    if (heap->vec[pos] == data)
        return 1;

    return subheap_exists(heap, data, (2 * pos) + 1) || subheap_exists(heap, data, (2 * pos) + 2);
}

// Checa se a arvore contem o dado informado
int heap_exists(Heap *heap, int data)
{
    if (heap == NULL)
        return 0;

    return subheap_exists(heap, data, 0);
}

// Retorna a posição do nó que contém o dado
int subheap_find(Heap *heap, int data, int pos)
{
    if (heap == NULL)
        return -1;

    if (heap->vec[pos] == data)
        return pos;

    int l = subheap_find(heap, data, (2 * pos) + 1);
    int r = subheap_find(heap, data, (2 * pos) + 2);

    if (l > 0)
        return l;
    if (r > 0)
        return r;

    return -1;
}

// Retorna a posição do nó que contém o dado
int heap_find(Heap *heap, int data)
{
    return subheap_find(heap, data, 0);
}

// Retorna o maior valor entre dois inteiros
int max2(int a, int b)
{
    if (a >= b)
        return a;

    return b;
}

// Retorna a altura da subarvore
int subheap_height(Heap *heap, int pos)
{
    if (pos >= heap->dim)
        return -1;

    if (heap->vec[pos] == -99)
        return -1;

    return 1 + max2(subheap_height(heap, (2 * pos) + 1), subheap_height(heap, (2 * pos) + 2));
}

// Retorna a altura da arvore
int heap_height(Heap *heap)
{
    if (heap == NULL)
        return -1;

    return subheap_height(heap, 0);
}

// Insere um novo dado na subarvore
int subheap_insert(Heap *heap, int data, int pos)
{
    // Não permite inserir dados em posições maiores que a dimensão do heap
    if (pos >= heap->dim)
        return 0;

    // Não permite dados duplicados na arvore
    if (heap_exists(heap, data))
        return 0;

    // Se não tem filho a esquerda, insere a esquerda
    if (heap->vec[(2 * pos) + 1] == -99)
    {
        heap->vec[(2 * pos) + 1] = data;
        return 1;
    }

    // Se não tem filho a direita, insere a direita
    if (heap->vec[(2 * pos) + 2] == -99)
    {
        heap->vec[(2 * pos) + 2] = data;
        return 1;
    }

    // Se tem filhos nos dois lados, faz a inserção na subarvore do filho com menos altura
    if (subheap_height(heap, (2 * pos) + 1) < subheap_height(heap, (2 * pos) + 2))
        return subheap_insert(heap, data, (2 * pos) + 1);
    else
        return subheap_insert(heap, data, (2 * pos) + 2);
}

// Insere um novo dado na subarvore
int heap_insert(Heap *heap, int data)
{
    if (heap == NULL)
        return 0;

    return subheap_insert(heap, data, 0);
}

#endif