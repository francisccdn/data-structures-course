#include <stdlib.h>

#include "../include/seti.h"
#include "../include/linkedlist.h"

#ifndef _SET_I_C_
#define _SET_I_C_

// Struct do conjunto de inteiros.
struct seti
{
    // Ponteiro para a lista que vai armazenar o conjunto.
    LinkedList *list;
};

// ** (a) Criação do TAD.

// Cria o um novo conjunto, retornando seu endereço de memória.
SetI *seti_create()
{
    SetI *set = (SetI *)malloc(sizeof(SetI));

    // Se a memoria foi alocada sem erros, cria a lista do conjunto.
    if (set)
    {
        set->list = ll_create_list();

        // Se não foi possível criar a lista, retorna nulo.
        if (!set->list)
            return NULL;
    }
    
    return set;
}

// ** (b) União de dois Seti.

// Cria um novo conjunto, composto da união de dois outros.
SetI *seti_union(SetI *a, SetI *b)
{
    // Cria o novo conjunto união.
    SetI *a_union_b = seti_create();
    if (!a_union_b)
        return NULL;

    // Insere todos os elementos do conjunto a na união.
    for (int i = 0; i < ll_size(a->list); i++)
    {
        seti_insert(a_union_b, ll_get(a->list, i));
    }
    
    // Insere todos os elementos do conjunto b na união.
    for (int i = 0; i < ll_size(b->list); i++)
    {
        seti_insert(a_union_b, ll_get(b->list, i));
    }

    return a_union_b;
}

// ** (c) Inserção de um elemento em um Seti.

// Insere um novo elemento no conjunto, impedindo elementos duplicados.
int seti_insert(SetI *set, int value)
{
    // Se o elemento já está no conjunto, saí da função retornando falso.
    if (ll_exists(set->list, value))
        return 0;
    
    // Insere o elemento em ordem crescente, retornando falso caso ocorra algum erro.
    return ll_insert_sorted(set->list, value);
}

// ** (d) Remoção de um elemento em um Seti.

// Remove elemento com dado valor do conjunto.
int seti_remove(SetI *set, int value)
{
    return ll_remove(set->list, value);
}

// ** (e) Intersecção de dois Seti.

// Cria um novo conjunto, composto da interseção de dois outros.
SetI *seti_intersection(SetI *a, SetI *b)
{
    // Cria o novo conjunto interseção.
    SetI *a_intersection_b = seti_create();
    if (!a_intersection_b)
        return NULL;

    // Percorre todos os elementos do conjunto a.
    for (int i = 0; i < ll_size(a->list); i++)
    {
        // Elemento analisado.
        int value = ll_get(a->list, i);

        // Se o elemento também existe no conjunto b
        if (ll_exists(b->list, value))
        {
            // Insere ele na interseção.
            seti_insert(a_intersection_b, value);
        }
    }

    return a_intersection_b;
}

// ** (f) Testa se um valor pertence a um Seti.

// Checa se existe um elemento no conjunto com esse valor.
int seti_exists(SetI *set, int value)
{
    return ll_exists(set->list, value);
}

// ** (g) Testa se dois Seti são iguais.

// Retorna verdadeiro se os dois conjuntos contém os mesmos elementos.
int seti_equals(SetI *a, SetI *b)
{
    // Se os conjuntos tem tamanhos diferentes, eles não são iguais.
    if (seti_size(a) != seti_size(b))
        return 0;

    // Percorre todos os elementos do conjunto a.
    for (int i = 0; i < ll_size(a->list); i++)
    {
        // Elemento analisado.
        int value = ll_get(a->list, i);

        // Se o elemento não existe no conjunto b, os conjuntos não são idênticos.
        if (!ll_exists(b->list, value))
        {
            // Retorna falso.
            return 0;
        }
    }

    // Se eles tem o mesmo tamanho, e todos os elementos de a estão contidos em b, eles são iguais.
    return 1;
}

// ** (h) Retorna o Tamanho de um Seti.

// Retorna o tamanho do conjunto.
int seti_size(SetI *set)
{
    return ll_size(set->list);
}

// ** (i) Testa se o Seti é vazio.

// Checa se o conjunto é vazio.
int seti_is_empty(SetI *set)
{
    return ll_is_empty(set->list);
}

// Libera a memória alocada para o conjunto.
void seti_free(SetI *set)
{
    ll_free(set->list);
    free(set);
}

// Imprime o conjunto no terminal.
void seti_print(SetI *set, char *message)
{
    ll_print(set->list, message);
}

#endif